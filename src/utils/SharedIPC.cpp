/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** SharedIPC
*/

#include <iostream>
#include <sys/shm.h>
#include <SharedIPC.hpp>
#include <fstream>

namespace Plazza {

    SharedIPC::SharedIPC() {
        this->_ptr = nullptr;
        this->_ipc = nullptr;
    }

    SharedIPC::~SharedIPC() {
        if (this->_ptr == nullptr)
            return;
        delete this->_ipc;
        shmdt(this->_ptr);
        shmctl(this->_shmid, IPC_RMID, 0);
        this->_ptr = nullptr;
    }

    IPC *SharedIPC::build() {
        if (this->_ipc != nullptr)
            return (this->_ipc);

        this->_createSocketFile();
        this->_retrieveSocketKey();
        this->_retrieveShmid();
        this->_initializeIPC();

        return (this->_ipc);
    }

    void SharedIPC::_createSocketFile() {
        std::ofstream file("/tmp/plazza.sock");
        file.close();
    }

    void SharedIPC::_retrieveSocketKey() {
        this->_key = ftok("/tmp/plazza.sock", 1);

        if (this->_key == (key_t) -1) {
            std::perror("IPC builder | ftok: ");
            throw SharedIPC::Error("Could not retrieve socket key.");
        }
    }

    void SharedIPC::_retrieveShmid() {
        this->_shmid = shmget(this->_key, sizeof(IPC), IPC_CREAT | 0777);

        if (this->_shmid == -1)
            throw SharedIPC::Error("Could not access shared memory.");
    }

    void SharedIPC::_initializeIPC() {
        this->_ptr = shmat(this->_shmid, 0, 0);

        if (this->_ptr == nullptr)
            throw SharedIPC::Error("Shared memory attachment error");
        this->_ipc = new (this->_ptr) IPC();
    }

}

