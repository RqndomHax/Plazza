/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** PizzaManager
*/

#include <PizzaManager.hpp>
#include <iostream>

namespace Plazza {

    PizzaManager::PizzaManager() {
        std::vector<Ingredients> reginaIngredients = {DOE, TOMATO, HAM, MUSHROOMS};
        std::vector<Ingredients> margaritaIngredients = {DOE, TOMATO, GRUYERE};
        std::vector<Ingredients> americanaIngredients = {DOE, TOMATO, GRUYERE, STEAK};
        std::vector<Ingredients> fantasiaIngredients = {DOE, TOMATO, EGGPLANT, GOAT_CHEESE, CHIEF_LOVE};

        this->_pizzas["regina"] = Pizza(PizzaType::Regina, reginaIngredients, 2);
        this->_pizzas["margarita"] = Pizza(PizzaType::Margarita, margaritaIngredients, 1);
        this->_pizzas["americana"] = Pizza(PizzaType::Americana, americanaIngredients, 2);
        this->_pizzas["fantasia"] = Pizza(PizzaType::Fantasia, fantasiaIngredients, 4);
    }

    std::map<std::string, Pizza> PizzaManager::getPizzas(void) const {
        return (this->_pizzas);
    }

    Pizza *PizzaManager::unpackPizza(std::string target) {
        std::string type = target.substr(0, target.find('_'));

        std::string size = target.substr(target.find('_') + 1);

        Pizza *pizza = new Pizza(this->_pizzas[type]);

        if (size == "S")
            pizza->setSize(S);
        if (size == "M")
            pizza->setSize(M);
        if (size == "L")
            pizza->setSize(L);
        if (size == "XL")
            pizza->setSize(XL);
        if (size == "XXL")
            pizza->setSize(XXL);

        return (pizza);
    }

}
