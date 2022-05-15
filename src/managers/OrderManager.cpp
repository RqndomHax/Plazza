/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** OrderManager
*/

#include <Order.hpp>
#include <string>

namespace Plazza {

    Order::Order(PizzaType pizzaType, PizzaSize pizzaSize) {
        this->_pizzaType = pizzaType;
        this->_pizzaSize = pizzaSize;
    }

    PizzaType Order::getPizzaType() {
        return (this->_pizzaType);
    }

    PizzaSize Order::getPizzaSize() {
        return (this->_pizzaSize);
    }

    Order retrieveOrder(std::string order) {
        (void) order;
        return (Order(PizzaType::Americana, PizzaSize::L));
    }

}
