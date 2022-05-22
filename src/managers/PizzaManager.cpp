/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** PizzaManager
*/

#include <PizzaManager.hpp>

namespace Plazza {

    PizzaManager::PizzaManager() {
        std::vector<Ingredients> reginaIngredients = {DOE, TOMATO, HAM, MUSHROOMS};
        std::vector<Ingredients> margaritaIngredients = {DOE, TOMATO, GRUYERE};
        std::vector<Ingredients> americanaIngredients = {DOE, TOMATO, GRUYERE, STEAK};
        std::vector<Ingredients> fantasiaIngredients = {DOE, TOMATO, EGGPLANT, GOAT_CHEESE, CHIEF_LOVE};

        this->_pizzas["regina"] = Pizza(PizzaType::Regina, reginaIngredients);
        this->_pizzas["margarita"] = Pizza(PizzaType::Margarita, margaritaIngredients);
        this->_pizzas["americana"] = Pizza(PizzaType::Americana, americanaIngredients);
        this->_pizzas["fantasia"] = Pizza(PizzaType::Fantasia, fantasiaIngredients);
    }

    std::map<std::string, Pizza> PizzaManager::getPizzas(void) const {
        return (this->_pizzas);
    }

}
