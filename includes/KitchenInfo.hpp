/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** KitchenInfo
*/

#ifndef KITCHENINFO_HPP_
    #define KITCHENINFO_HPP_
    #include "Kitchen.hpp"

namespace Plazza {

    class KitchenInfo {
        public:
            KitchenInfo(int id, Pipe *pipe, Pipe *masterPipe);

            ~KitchenInfo();

            bool createKitchen(Settings settings);

            int getId(void);
            
            Pipe *getPipe(void);

            Pipe *getMasterPipe(void);

            std::string retrieveId(void);

            bool isClosed;

            std::list<Pizza *> getTotalOrders(void) const;

            void addTotalOrder(Pizza *pizza);

            void addAwaitingOrder(Pizza *pizza);

            std::list<Pizza *> *getAwaitingOrders(void);

            std::list<Pizza *> *getProcessingOrders(void);

            void addProcessingOrder(Pizza *pizza);

            std::list<Pizza *> getCompletedOrders(void) const;

            void addCompletedOrder(Pizza *pizza);

            void refillIngredients(void);

            int getIngredientsQuantity(Ingredients ingredient);

        private:
            int _id;
            Pipe *_pipe;
            Pipe *_masterPipe;

            std::list<Pizza *> _ordersProcessing;
            std::list<Pizza *> _ordersCompleted;
            std::list<Pizza *> _ordersAwaiting;
            std::list<Pizza *> _totalOrders;
            std::list<Ingredients> _ingredients;

            void _takeIngredients(Pizza *pizza);

    };

}

#endif /* !KITCHENINFO_HPP_ */
