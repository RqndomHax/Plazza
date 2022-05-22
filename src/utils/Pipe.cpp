/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** Pipe
*/

#include <unistd.h>
#include <Pipe.hpp>
#include <Utils.hpp>

namespace Plazza {

    Pipe::Pipe() {
        int descriptors[2];

        if (pipe(descriptors) == -1)
            throw Pipe::Error("Could not data channel. [" + retrieveError() + "]");
        this->_readFd = descriptors[0];
        this->_writeFd = descriptors[1];
    }

    Pipe::~Pipe() {
    }

    int Pipe::getReadFileDescriptor() {
        return (this->_readFd);
    }

    int Pipe::getWriteFileDescriptor() {
        return (this->_writeFd);
    }

}
