/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** Order
*/

#ifndef ORDER_HPP_
    #define ORDER_HPP_
    #include "Pizza.hpp"

namespace Plazza {

    class Order {
        public:
            Order(PizzaType pizzaType, PizzaSize pizzaSize);

            PizzaType getPizzaType();
            PizzaSize getPizzaSize();

        private:
            PizzaType _pizzaType;
            PizzaSize _pizzaSize;
    };

}

#endif /* !ORDER_HPP_ */
