/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** args_managers
*/

#include <ArgsManager.hpp>
#include <Utils.hpp>

namespace Plazza {

    ArgsManager::ArgsManager(int argc, char **argv) {
        this->_argc = argc;
        this->_argv = argv;
        this->_cookingTime = -1;
        this->_cooks = -1;
        this->_replaceDuration = -1;
    }

    void ArgsManager::initialize() {
        this->_checkCorrectSyntax();
        this->_checkCookingTime();
        this->_checkCooks();
        this->_checkReplaceDuration();
    }

    Settings ArgsManager::buildSettings() {
        return (Settings(this->_cookingTime, this->_cooks, this->_replaceDuration));
    }

    void ArgsManager::_checkCorrectSyntax() {
        if (this->_argc != 4)
            throw ArgsManager::Error("Incorrect number of arguments.");
    }

    void ArgsManager::_checkCookingTime() {
        char *endPtr;

        this->_cookingTime = std::strtod(this->_argv[1], &endPtr);
        if (this->_argv[1] == endPtr)
            throw ArgsManager::Error("Cooking time is not a valid decimal number.");
        if (this->_cookingTime < 0)
            throw ArgsManager::Error("Cooking time should not be negative.");
    }

    void ArgsManager::_checkCooks() {
        char *endPtr;

        this->_cooks = std::strtol(this->_argv[2], &endPtr, 10);
        if (this->_argv[2] == endPtr)
            throw ArgsManager::Error("Cooks is not a valid integer.");
        if (this->_cooks < 0)
            throw ArgsManager::Error("Cooks should not be negative.");
    }

    void ArgsManager::_checkReplaceDuration() {
        char *endPtr;

        this->_replaceDuration = std::strtol(this->_argv[3], &endPtr, 10);
        if (this->_argv[3] == endPtr)
            throw ArgsManager::Error("Replace duration is not a valid long decimal number.");
        if (this->_replaceDuration < 0)
            throw ArgsManager::Error("Replace duration should not be negative.");
    }

};
