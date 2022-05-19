/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** Pizzeria project
*/

#include <iostream>
#include <ArgsManager.hpp>
#include <ShellManager.hpp>
#include <SharedIPC.hpp>
#include <Pizzeria.hpp>
#include <unistd.h>
#include <stdio.h>

void check() {
    pid_t id = fork();

    if (id > 0) {
        std::cout << "Writing content..." << std::endl;
        Plazza::getPizzeria(nullptr)->getIPC()->write("Hello, world!");
        std::cout << "Writing another content..." << std::endl;
        Plazza::getPizzeria(nullptr)->getIPC()->write("Another world? Rick & Morty!");
        std::cout << "another content written !" << std::endl;
        return;
    }
    if (Plazza::getPizzeria(nullptr) == nullptr) {
        std::cout << "pizzeria is null, return." << std::endl;
        exit(1);
    }
    std::cout << "Reading content..." << std::endl;
    std::string content = Plazza::getPizzeria(nullptr)->getIPC()->read();
    std::cout << "Content = [" << content << "]" << std::endl;
    std::cout << "Reading new content..." << std::endl;
    content = Plazza::getPizzeria(nullptr)->getIPC()->read();
    std::cout << "Content = [" << content << "]" << std::endl;
    exit(1);
}

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
    Plazza::SharedIPC ipcBuilder;
    Plazza::IPC *ipc = nullptr;

    try {
        ipc = ipcBuilder.build();
    } catch (Plazza::SharedIPC::Error const &error) {
        std::cerr << error.what() << std::endl;
        return (84);
    }

    Plazza::Pizzeria *pizzeria = new Plazza::Pizzeria(settings, ipc);
    Plazza::getPizzeria(pizzeria);
    check();
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
