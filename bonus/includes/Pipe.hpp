/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** Pipe
*/

#ifndef PIPE_HPP_
    #define PIPE_HPP_
    #include <stdexcept>
    #include <ostream>
    #include "Logger.hpp"

namespace Plazza {

    class Pipe {
        public:
            Pipe();
            ~Pipe();

            class Error : public std::exception {
                public:

                    Error(std::string message) : _message(message) {}

                    char const *what() const noexcept override {
                        return (this->_message).c_str();
                    }

                private:
                    std::string const _message;
            };

            int getReadFileDescriptor() const;

            int getWriteFileDescriptor() const;

            std::string &operator>>(std::string &content);

            std::string operator<<(std::string content);

            std::ostream& operator<<(std::ostream &os);

        private:
            int _readFd;
            int _writeFd;
    };

}

#endif /* !PIPE_HPP_ */
