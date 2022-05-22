/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** Logger
*/

#include <Logger.hpp>
#include <ctime>
#include <time.h>
#include <iostream>
#include <sstream>

namespace Plazza {

    Logger::Logger() {
        std::cout << "filepath = [" << "" << this->_getCurrentDate() << ".log]" << std::endl;
        this->_logFile = std::ofstream(this->_getCurrentDate() + ".log");

        if (!this->_logFile)
            throw Logger::Error("Could not open log file.");
    }

    Logger::~Logger() {
        this->_logFile.close();
    }

    std::string Logger::_getCurrentDate(void) {
        std::time_t t = std::time(nullptr);
        char time[20];

        std::strftime(time, sizeof(time), "%H:%M:%S-%m_%d_%Y", std::localtime(&t));
        return (std::string(time));
    }

}
