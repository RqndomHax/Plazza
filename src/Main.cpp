/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** Pizzeria project
*/

#include <iostream>
#include <ArgsManager.hpp>
#include <ShellManager.hpp>

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
    std::cerr << "Cooking time = " << settings.getCookingTime() << std::endl;
    std::cerr << "Cooks = " << settings.getCooks() << std::endl;
    std::cerr << "Replace duration = " << settings.getReplaceDuration() << std::endl;
    Plazza::ShellManager shellManager = Plazza::ShellManager(Plazza::Pizzeria());
    shellManager.runShell();
    return (0);
}
