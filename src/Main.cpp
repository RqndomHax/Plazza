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

    Plazza::ShellManager shellManager = Plazza::ShellManager(Plazza::Pizzeria(settings, ipc));
    shellManager.runShell();
    return (0);
}
