/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** ShellManager
*/

#include <iostream>
#include <fstream>
#include <ShellManager.hpp>
#include <Utils.hpp>

namespace Plazza {

    void ShellManager::runShell() {
        std::string line;

        std::cout << "> ";
        if (!(std::getline(std::cin, line)))
            return;
        try {
            this->_parseInput(line);
        } catch (ShellManager::Error const &error) {
            std::cerr << "SHELL MANAGER ERROR | " << error.what() << std::endl;
        } catch (ShellManager::Exit const &ignored) {
            return;
        }
        runShell();
    }

    void ShellManager::_parseInput(std::string command) {
        if (command == "exit")
            throw ShellManager::Exit();
        std::vector<std::string> commands = splitString(command, " ");
        std::cerr << "Commands =";
        for (std::string cmd : commands) {
            std::cerr << " [" << cmd << "]";
        }
        std::cerr << std::endl;
    }

}