/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** Pizzeria
*/

#ifndef PIZZERIA_HPP_
    #define PIZZERIA_HPP_
    #include <vector>
    #include "Settings.hpp"
    #include "IPC.hpp"
    #include "Order.hpp"

namespace Plazza {

    class Pizzeria {
        public:
            Pizzeria() {}
            Pizzeria(Settings settings);

            void dispatchOrder(Order order);
            void removeKitchen(int kitchenId);
            void createKitchen();
            Settings getSettings();
        private:
            Settings _settings;
            std::vector<int> _kitchensId;
            int _nextId;
    };

    Pizzeria *getPizzeria(void *pizzeria);

}


#endif /* !PIZZERIA_HPP_ */
