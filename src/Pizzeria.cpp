/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** Pizzeria
*/

#include <algorithm>
#include <iostream>
#include <Pizzeria.hpp>

namespace Plazza {

    Pizzeria::Pizzeria(Settings settings) {
        this->_settings = settings;
        this->_nextId = 1;
    }

    void Pizzeria::dispatchOrder(Order order) {
        std::cerr << "Size = " << order.getPizzaSize() << " | Type " << order.getPizzaType() << " | Quantity " << order.getQuantity() << std::endl;
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
