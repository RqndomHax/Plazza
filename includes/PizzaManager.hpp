/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** PizzaManager
*/

#ifndef PIZZAMANAGER_HPP_
    #define PIZZAMANAGER_HPP_
    #include <map>
    #include <string>
    #include "Pizza.hpp"

namespace Plazza {

    class PizzaManager {
        public:
            PizzaManager();

            std::map<std::string, Pizza> getPizzas(void) const;

        private:
            std::map<std::string, Pizza> _pizzas;

    };

}

#endif /* !PIZZAMANAGER_HPP_ */
