/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** Pizza
*/

#include <Pizza.hpp>

namespace Plazza {

    Pizza::Pizza(PizzaType type, PizzaSize size) {
        this->_type = type;
        this->_size = size;
    }

    PizzaType Pizza::getType(void) const {
        return (this->_type);
    }

    PizzaSize Pizza::getSize(void) const {
        return (this->_size);
    }

    std::string Pizza::display(void) const {
        std::string content = "";
        switch (this->getType()) {
            case Regina:
                content += "regina of size ";
                break;
            case Margarita:
                content += "margarita of size ";
                break;
            case Americana:
                content += "americana of size ";
                break;
            case Fantasia:
                content += "fantasia of size ";
                break;
            default: break;
        }

        switch (this->getSize()) {
            case S:
                content += "S";
                break;
            case M:
                content += "M";
                break;
            case L:
                content += "L";
                break;
            case XL:
                content += "XL";
                break;
            case XXL:
                content += "XXL";
                break;
            default: break;
        }

        return (content);
    }


}
