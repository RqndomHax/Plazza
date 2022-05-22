/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** Kitchen
*/

#include <Kitchen.hpp>

namespace Plazza {

    Kitchen::Kitchen(int id, Pipe &pipe) {
        this->_id = id;
        this->_pipe = pipe;

        
        pipe << this->retrieveId() + "Kitchen built.";
    }

    Kitchen::~Kitchen() {
    }

    void Kitchen::cookPizza(void) {
        if (this->_orders.empty())
            return;

        Pizza pizza = this->_orders.front();
        this->_orders.pop();

        this->_pipe << this->retrieveId() + pizza.display() + " cooking.";
    }
    
    void Kitchen::addOrder(Pizza pizza) {
        this->_orders.push(pizza);
    }

    std::string Kitchen::retrieveId() {
        return ("[" + std::to_string(this->_id) + "] ");
    }

}
