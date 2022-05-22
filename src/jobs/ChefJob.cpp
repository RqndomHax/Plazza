/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** Chef
*/

#include <Chef.hpp>

namespace Plazza {

    Chef::Chef(Kitchen *jobOwner) {
        this->_jobOwner = jobOwner;
    }

    Chef::~Chef() {
    }

    bool Chef::hasPizza(void) {
        return (this->_currentPizza != nullptr);
    }

    void Chef::setPizza(Pizza *currentPizza) {
        this->_currentPizza = currentPizza;
    }

    void Chef::runJob(void) {
        
    }

    void Chef::joinThread(void) {

    }

}
