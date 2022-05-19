/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** IPC
*/

#include <IPC.hpp>
#include <iostream>
#include <unistd.h>

namespace Plazza {

    IPC::IPC() {
        this->_calls = 0;
        this->_nextId = 0;
        this->_currentId = 0;
        this->_buffer = std::string(1024, '\0');
    }

    IPC::~IPC() {
        std::cerr << "IPC unloaded" << std::endl;
    }

    std::string IPC::read() {
        this->_calls += 1;

        while (this->_buffer.at(0) == '\0');
        std::string tmp = this->_buffer;
        this->_calls -= 1;

        if (this->_calls == 0)
            this->_buffer.replace(0, 1024, 1024, '\0');
        return (tmp);
    }


    void IPC::write(std::string content) {
        long long int id = this->_nextId++;
        while (this->_buffer.at(0) != '\0' && id != this->_currentId);
        this->_buffer.replace(0, content.size(), content);
        this->_buffer.replace(content.size(), 1024 - content.size(), 1024 - content.size(), '\0');
        this->_currentId += 1;
    }

}