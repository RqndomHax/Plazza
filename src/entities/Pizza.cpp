/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** Pizza
*/

#include <Pizza.hpp>

namespace Plazza {

    Pizza::Pizza(PizzaType type, std::vector<Ingredients> ingredients, PizzaSize size) {
        this->_type = type;
        this->_ingredients = ingredients;
        this->_size = size;
    }

    PizzaType Pizza::getType(void) const {
        return (this->_type);
    }

    std::vector<Ingredients> Pizza::getIngredients(void) const {
        return (this->_ingredients);
    }

    PizzaSize Pizza::getSize(void) const {
        return (this->_size);
    }

    void Pizza::setSize(PizzaSize size) {
        this->_size = size;
    }

    std::string Pizza::pack(void) const {
        std::string content = "";

        switch (this->getSize()) {
            case S:
                content += "small ";
                break;
            case M:
                content += "medium ";
                break;
            case L:
                content += "large ";
                break;
            case XL:
                content += "extra large";
                break;
            case XXL:
                content += "extra extra large ";
                break;
            default: break;
        }

        switch (this->getType()) {
            case Regina:
                content += "regina";
                break;
            case Margarita:
                content += "margarita";
                break;
            case Americana:
                content += "americana";
                break;
            case Fantasia:
                content += "fantasia";
                break;
            default: break;
        }

        return (content);
    }


}
