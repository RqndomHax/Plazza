/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** Settings
*/

#include <Settings.hpp>

namespace Plazza {


    Settings::Settings(double cookingTime, int cooks, long replaceDuration) {
        this->_cookingTime = cookingTime;
        this->_cooks = cooks;
        this->_replaceDuration = replaceDuration;
    }

    double Settings::getCookingTime(void) const {
        return (this->_cookingTime);
    }

    int Settings::getCooks(void) const {
        return (this->_cooks);
    }

    long Settings::getReplaceDuration(void) const {
        return (this->_replaceDuration);
    }

    PizzaManager Settings::getPizzaManager(void) {
        return (this->_pizzaManager);
    }

}
