/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** OrderManager
*/

#include <string>
#include <Order.hpp>

namespace Plazza {

    Order::Order(PizzaType pizzaType, PizzaSize pizzaSize, int quantity) {
        this->_pizzaType = pizzaType;
        this->_pizzaSize = pizzaSize;
        this->_quantity = quantity;
    }

    PizzaType Order::getPizzaType() {
        return (this->_pizzaType);
    }

    PizzaSize Order::getPizzaSize() {
        return (this->_pizzaSize);
    }

    int Order::getQuantity() {
        return (this->_quantity);
    }

}
