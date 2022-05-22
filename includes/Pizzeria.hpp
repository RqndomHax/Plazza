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
    #include "Job.hpp"

namespace Plazza {

    class PizzeriaJob;

    class Pizzeria {
        public:
            Pizzeria(Settings &settings, Logger *logger);

            ~Pizzeria();

            void dispatchOrder(Order order);

            void removeKitchen(int kitchenId);

            void createKitchen(void);

            Settings getSettings(void);

            Logger getLogger(void);

        private:
            Settings _settings;
            std::vector<Job<Pizzeria> *> _jobs;
            int _nextId;
            Logger *_logger;

            int _retrieveKitchenJob(void);

            PizzeriaJob *_getJob(int kitchenId);
    };

    Pizzeria *getPizzeria(void *pizzeria);

}


#endif /* !PIZZERIA_HPP_ */
