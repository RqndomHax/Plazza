/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** ArgsManager
*/

#ifndef ARGSMANAGER_HPP_
    #define ARGSMANAGER_HPP_
    #include <string>
    #include <exception>
    #include "Settings.hpp"

namespace Plazza {

    class ArgsManager {

        public:
            ArgsManager(int argc, char **argv);
            void initialize();
            Settings buildSettings();


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
            int _argc;
            char **_argv;

            double _cookingTime;
            int _cooks;
            long _replaceDuration;

            int _retrieveNumber();
            void _checkCorrectSyntax();
            void _checkCookingTime();
            void _checkCooks();
            void _checkReplaceDuration();
    };

}

#endif /* !ARGSMANAGER_HPP_ */
