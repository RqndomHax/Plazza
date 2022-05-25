/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** Logger
*/

#ifndef LOGGER_HPP_
    #define LOGGER_HPP_
    #include <string>
    #include <fstream>

namespace Plazza {

    class Logger {
        public:
            Logger();
            ~Logger();

                class Error : public std::exception {
                    public:

                        Error(std::string message) : _message(message) {}

                        char const *what() const noexcept override {
                            return (this->_message).c_str();
                        }

                    private:
                        std::string const _message;
                };

            void log(std::string content);
            std::ofstream &getLogFile(void);
            Logger& operator<<(std::string const content);

        private:
            std::ofstream _logFile;

            std::string _getCurrentDate(void) const;

            std::string _getCurrentTime(void) const;
    };

}

#endif /* !LOGGER_HPP_ */
