/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** Kitchen
*/

#ifndef KITCHEN_HPP_
    #define KITCHEN_HPP_
    #include <string>
    #include <queue>
    #include "Pipe.hpp"
    #include "Pizza.hpp"

namespace Plazza {

    class Kitchen {
        public:
            Kitchen(int id, Pipe &pipe);
            ~Kitchen();

            void cookPizza(void);

            void addOrder(Pizza pizza);

        private:
            int _id;
            Pipe _pipe;
            std::queue<Pizza> _orders;

            void _updateOrders();
            std::string retrieveId(void);
    };

}

#endif /* !KITCHEN_HPP_ */
