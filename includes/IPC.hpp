/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** IPC
*/

#ifndef IPC_HPP_
    #define IPC_HPP_
    #include <stack>

namespace Plazza {

    class IPC {
        public:
            IPC();

            std::stack<int> getRequests();

        private:
            std::stack<int> _requests;
    };

}

#endif /* !IPC_HPP_ */
