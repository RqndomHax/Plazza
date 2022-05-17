/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** Pizzeria
*/

#ifndef PIZZERIA_HPP_
    #define PIZZERIA_HPP_
    #include <vector>
    #include "Order.hpp"

namespace Plazza {

    class Pizzeria {
        public:
            Pizzeria();

            void writeOrder(Order order);
            void removeKitchen(int kitchenId);
            void createKitchen();
        private:
            std::vector<int> _kitchensId;
            int _nextId;
    };

}

#endif /* !PIZZERIA_HPP_ */
