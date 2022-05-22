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
    #include "KitchenInfo.hpp"

namespace Plazza {

    class PizzeriaJob;

    class Pizzeria {
        public:
            Pizzeria(Settings &settings, Logger *logger);

            ~Pizzeria();

            void dispatchOrder(Order order);

            void removeKitchen(KitchenInfo *kitchen);

            void createKitchen(void);

            Settings getSettings(void);

            Logger *getLogger(void);

            Pipe *getMasterPipe(void);

            KitchenInfo *getKitchen(int kitchenId);

        private:
            Settings _settings;
            std::vector<KitchenInfo *> _kitchens;
            int _nextId;
            Pipe *_masterPipe = nullptr;
            Logger *_logger = nullptr;

            int _retrieveKitchenJob(void);

            PizzeriaJob *_job = nullptr;
    };

}


#endif /* !PIZZERIA_HPP_ */
