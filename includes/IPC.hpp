/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** IPC
*/

#ifndef IPC_HPP_
    #define IPC_HPP_
    #include <string>
    #include <array>
    #include <mutex>

namespace Plazza {

    class IPC {
        public:
            IPC();
            ~IPC();

            std::string read();
            void write(std::string content);
            std::string _buffer;

        private:
            int _calls;
            long long int _nextId;
            long long int _currentId;
            std::mutex _mutex;
    };

}

#endif /* !IPC_HPP_ */
