/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** SharedIPC
*/

#ifndef SHAREDIPC_HPP_
    #define SHAREDIPC_HPP_
    #include "IPC.hpp"

namespace Plazza {

    class SharedIPC {
        public:
            SharedIPC();
            ~SharedIPC();

            IPC *build();

            class Error : public std::exception {
                public:

                    Error(std::string message) : _message(message) {}

                    char const *what() const noexcept override {
                        return (this->_message).c_str();
                    }

                private:
                    std::string const _message;
            };

        private:
            void *_ptr;
            void *_bufferPtr;
            IPC *_ipc;
            key_t _key;
            int _shmid;
            int _buffershmid;

            void _createSocketFile();
            void _retrieveSocketKey();
            void _retrieveShmid();
            void _retrieveBufferShmid();
            void _initializeIPC();
    };

}

#endif /* !SHAREDIPC_HPP_ */
