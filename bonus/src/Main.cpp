/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** Pizzeria project
*/

#include <iostream>
#include <ArgsManager.hpp>
#include <DisplayManager.hpp>
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

    Plazza::Pizzeria pizzeria(settings, &logger);
    Plazza::DisplayManager(&pizzeria).runDisplay();
    return (0);
}
