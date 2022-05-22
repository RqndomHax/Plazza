/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** OrderManager
*/

#include <string>
#include <Order.hpp>

namespace Plazza {

    Order::Order(Pizza pizza, int quantity) {
        this->_pizza = pizza;
        this->_quantity = quantity;
    }

    Pizza Order::getPizza(void) const {
        return (this->_pizza);
    }

    int Order::getQuantity(void) const {
        return (this->_quantity);
    }

}
