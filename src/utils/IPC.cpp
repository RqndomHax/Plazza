/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** IPC
*/

#include <IPC.hpp>

namespace Plazza {

    IPC::IPC() {
    }

    std::stack<int> IPC::getRequests() {
        return (this->_requests);
    }

}