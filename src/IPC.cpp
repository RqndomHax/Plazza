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
    }

    IPC::~IPC() {
        std::cerr << "IPC unloaded" << std::endl;
    }

}