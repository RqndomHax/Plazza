/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** Order
*/

#ifndef ORDER_HPP_
    #define ORDER_HPP_
    #include "Pizza.hpp"
    #include <string>

namespace Plazza {

    class Order {
        public:
            Order(Pizza pizza, int quantity);

            Pizza getPizza(void) const;
            int getQuantity(void) const;

        private:
            Pizza _pizza;
            int _quantity;
    };

}


#endif /* !ORDER_HPP_ */
