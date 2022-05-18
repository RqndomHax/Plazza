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

        private:
            void *_ptr;
            IPC *_ipc;
            int _shmid;
    };

}

#endif /* !SHAREDIPC_HPP_ */
