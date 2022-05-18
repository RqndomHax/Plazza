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

    IPC *SharedIPC::build() {
        if (this->_ipc != nullptr)
            return (this->_ipc);
        std::ofstream file("/tmp/plazza.sock");
        file.close();
        key_t key = ftok("/tmp/plazza.sock", 1);
        if (key == (key_t) -1) {
            perror("IPC error: ftok");
            return (NULL); // TODO throw error
        }
        this->_shmid = shmget(key, sizeof(IPC), IPC_CREAT | 0777);
        if (this->_shmid == -1) {
            std::cerr << "Could not get shared memory" << std::endl;
            return (NULL);
        }
        this->_ptr = shmat(this->_shmid, 0, 0);
        this->_ipc = new (this->_ptr) IPC();
        return (this->_ipc);
    }

    SharedIPC::~SharedIPC() {
        if (this->_ptr == nullptr)
            return;
        shmdt(this->_ptr);
        shmctl(this->_shmid, IPC_RMID, 0);
        this->_ptr = nullptr;
    }

}

