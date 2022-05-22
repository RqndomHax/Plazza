/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** Pizzeria
*/

#include <algorithm>
#include <iostream>
#include <Pizzeria.hpp>
#include <Kitchen.hpp>

namespace Plazza {

    Pizzeria::Pizzeria(Settings &settings, Logger *logger, Pipe &pipe) {
        this->_settings = settings;
        this->_pipe = pipe;
        this->_nextId = 1;

        this->_logger = logger;
        *this->_logger << "Pizzeria initialized!";
        Kitchen kitchen(0, pipe);
    }

    void Pizzeria::dispatchOrder(Order order) {
        (void) order;
    }

    void Pizzeria::removeKitchen(int kitchenId) {
        std::vector<int>::iterator position = std::find(this->_kitchensId.begin(), this->_kitchensId.end(), kitchenId);
        if (position == this->_kitchensId.end())
            return;

        this->_kitchensId.erase(position);
    }

    void Pizzeria::createKitchen() {
        this->_kitchensId.push_back(this->_nextId++);
    }

    Settings Pizzeria::getSettings() {
        return (this->_settings);
    }

}
