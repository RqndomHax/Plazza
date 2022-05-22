/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** Pipe
*/

#include <unistd.h>
#include <Pipe.hpp>
#include <Utils.hpp>
#include <sstream>

namespace Plazza {

    Pipe::Pipe(Logger *logger) {
        this->_logger = logger;
        if (logger == nullptr)
            return;

        int descriptors[2];

        if (pipe(descriptors) == -1)
            throw Pipe::Error("Could not create data channel. [" + retrieveError() + "]");
        this->_readFd = descriptors[0];
        this->_writeFd = descriptors[1];
    }

    Pipe::~Pipe() {
    }

    int Pipe::getReadFileDescriptor() const {
        return (this->_readFd);
    }

    int Pipe::getWriteFileDescriptor() const {
        return (this->_writeFd);
    }

    std::string Pipe::operator<<(std::string content) {
        dprintf(this->_writeFd, "%s\n", content.c_str());
        *this->_logger << content.c_str();
        return (content);
    }

    std::ostream& Pipe::operator<<(std::ostream &os) {
        std::stringstream ss;
        ss << os.rdbuf();
        std::string content = ss.str();
        dprintf(this->_writeFd, "%s\n", content.c_str());
        *this->_logger << content.c_str();
        return (os);
    }

}
