/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** Logger
*/

#include <ctime>
#include <iostream>
#include <thread>
#include <chrono>
#include <Logger.hpp>

namespace Plazza {

    Logger::Logger() {
        this->_logFile = std::ofstream(this->_getCurrentDate() + ".log");

        if (!this->_logFile)
            throw Logger::Error("Could not open log file.");
    }

    Logger::~Logger() {
        this->_logFile.close();
    }

    Logger& Logger::operator<<(std::string const &content) {
        this->_logFile << this->_getCurrentTime() + content + "\n";
        return (*this);
    }

    std::string Logger::_getCurrentDate(void) const {
        std::time_t t = std::time(nullptr);
        char time[20];

        std::strftime(time, sizeof(time), "%H:%M:%S-%m_%d_%Y", std::localtime(&t));
        return (std::string(time));
    }

    std::string Logger::_getCurrentTime(void) const {
        std::time_t t = std::time(nullptr);
        char time[20];

        std::strftime(time, sizeof(time), "[%H:%M:%S] ", std::localtime(&t));
        return (std::string(time));
    }

    std::ofstream &Logger::getLogFile(void) {
        return (this->_logFile);
    }

}
