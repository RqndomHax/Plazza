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

            void createKitchen(Settings settings);

            int getId(void);
            
            Pipe *getPipe(void);

            Pipe *getMasterPipe(void);

            std::string retrieveId(void);

            bool isClosed;

            int getTotalOrders(void) const;

            void addTotalOrder(void);

            int getAwaitingOrders(void) const;

            int getProcessingOrders(void) const;

            void addProcessingOrder(void);

            int getCompletedOrders(void) const;

            void addCompletedOrder(void);

        private:
            int _id;
            Pipe *_pipe;
            Pipe *_masterPipe;

            int _ordersProcessing;
            int _ordersCompleted;
            int _totalOrders;

    };

}

#endif /* !KITCHENINFO_HPP_ */
