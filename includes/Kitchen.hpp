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
    #include <mutex>
    #include "Pipe.hpp"
    #include "Job.hpp"
    #include "Pizza.hpp"

namespace Plazza {

    class KitchenOrder;

    class Kitchen {
        public:
            Kitchen(int id, Pipe *pipe, Pipe *masterPipe);
            ~Kitchen();

            Pipe *getPipe();

            bool isActive(void) const;

            void setActive(bool status);

            std::string retrieveId(void);

            std::mutex mutex;

            int getId() const;

        private:
            int _id;
            Pipe *_masterPipe;
            Pipe *_pipe;
            std::queue<Pizza> _orders;
            Job<Kitchen> *_orderHandler;
            std::vector<Job<Kitchen> *> _cooks;

            bool _isActive;

            void _handleKitchen(void);

            void _updateOrders();
    };

}

#endif /* !KITCHEN_HPP_ */
