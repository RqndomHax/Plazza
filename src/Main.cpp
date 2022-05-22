/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** Pizzeria project
*/

#include <iostream>
#include <ArgsManager.hpp>
#include <ShellManager.hpp>
#include <Pizzeria.hpp>
#include <unistd.h>
#include <stdio.h>
#include <Logger.hpp>

int main(int argc, char **argv)
{
    Plazza::ArgsManager argsManager(argc, argv);

    try {
        argsManager.initialize();
    } catch (Plazza::ArgsManager::Error &error) {
        std::cerr << "[ArgsManager] >> " << error.what() << std::endl;
        return (84);
    }
    Plazza::Settings settings = argsManager.buildSettings();
    Plazza::Logger logger;
    Plazza::Pipe pipe(&logger);

    Plazza::Pizzeria *pizzeria = new Plazza::Pizzeria(settings, &logger, pipe);
    Plazza::getPizzeria(pizzeria);
    Plazza::ShellManager().runShell();
    delete pizzeria;
    return (0);
}

Plazza::Pizzeria *Plazza::getPizzeria(void *pizzeria) {
    static Plazza::Pizzeria *ptr = nullptr;

    if (ptr != nullptr)
        return (ptr);
    ptr = (Plazza::Pizzeria *) pizzeria;
    return (ptr);
}
