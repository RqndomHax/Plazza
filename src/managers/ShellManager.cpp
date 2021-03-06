/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** ShellManager
*/

#include <iostream>
#include <fstream>
#include <ShellManager.hpp>
#include <OrderBuilder.hpp>
#include <StatusPrinter.hpp>
#include <Utils.hpp>

namespace Plazza {

    ShellManager::ShellManager(Pizzeria *pizzeria) {
        this->_pizzeria = pizzeria;
    }

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
        if (this->_pizzeria->isFork)
            return;
        runShell();
    }

    void ShellManager::_parseInput(std::string command) {
        if (command == "exit")
            throw ShellManager::Exit();
        if (command == "status") {
            StatusPrinter printer(this->_pizzeria);
            printer.print();
            return;
        }
        for (std::string order : splitString(command, ";")) {
            try {
                Order tmp = OrderBuilder(order, this->_pizzaManager).buildOrder();

                if (tmp.getQuantity() > 0)
                    this->_pizzeria->dispatchOrder(tmp);
                if (this->_pizzeria->isFork)
                    return;
            } catch (OrderBuilder::Error const &error) {
                std::cerr << "[Shell error] " << error.what() << std::endl;
            }

        }
    }

}