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

            void dispatchOldOrders(std::list<Pizza *> *pizzas);

            void removeKitchen(KitchenInfo *kitchen);

            KitchenInfo *createKitchen(void);

            Settings getSettings(void);

            Logger *getLogger(void);

            Pipe *getMasterPipe(void);

            KitchenInfo *retrieveBestKitchen(void);

            KitchenInfo *getKitchen(int kitchenId);

            std::vector<KitchenInfo *> getKitchens(void);

            std::list<Pizza *> getAwaitingOrders(void) const;

            std::list<Pizza *> getTotalOrders(void) const;

            std::list<Pizza *> getCompletedOrders(void) const;

            std::list<Pizza *> getProcessingOrders(void) const;

            void addCompletedOrders(Pizza *pizza);

            void addProcessingOrders(Pizza *pizza);

            bool isFork;

            bool isActive;

            std::mutex mutex;

        private:
            Settings _settings;
            std::vector<KitchenInfo *> _kitchens;
            int _nextId;
            Pipe *_masterPipe = nullptr;
            Logger *_logger = nullptr;

            int _retrieveKitchenJob(void);

            PizzeriaJob *_job = nullptr;

            std::list<Pizza *> _totalOrders;
            std::list<Pizza *> _completedOrders;
            std::list<Pizza *> _processingOrders;
            std::list<Pizza *> _awaitingOrders;

    };

}


#endif /* !PIZZERIA_HPP_ */
