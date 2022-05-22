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
    #include "Order.hpp"
    #include "Logger.hpp"
    #include "Pipe.hpp"

namespace Plazza {

    class Pizzeria {
        public:
            Pizzeria(Settings &settings, Logger *logger, Pipe &pipe);

            void dispatchOrder(Order order);

            void removeKitchen(int kitchenId);

            void createKitchen(void);

            Settings getSettings(void);

            Logger getLogger(void);

        private:
            Settings _settings;
            Pipe _pipe;
            std::vector<int> _kitchensId;
            int _nextId;
            Logger *_logger;
    };

    Pizzeria *getPizzeria(void *pizzeria);

}


#endif /* !PIZZERIA_HPP_ */
