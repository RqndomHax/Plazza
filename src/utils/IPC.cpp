/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** IPC
*/

#include <IPC.hpp>
#include <iostream>

namespace Plazza {

    IPC::IPC() {
    }

    IPC::~IPC() {
        if (this->_requests.empty() == false)
            std::cerr << "Error while emptying the requests" << std::endl;
        std::cerr << "IPC unloaded" << std::endl;
    }

    std::stack<int> IPC::getRequests() {
        return (this->_requests);
    }

}