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

        switch (this->getType()) {
            case Regina:
                content += "regina_";
                break;
            case Margarita:
                content += "margarita_";
                break;
            case Americana:
                content += "americana_";
                break;
            case Fantasia:
                content += "fantasia_";
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
