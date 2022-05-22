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

    double Settings::getCookingTime() const {
        return (this->_cookingTime);
    }

    int Settings::getCooks() const {
        return (this->_cooks);
    }

    long Settings::getReplaceDuration() const {
        return (this->_replaceDuration);
    }

}
