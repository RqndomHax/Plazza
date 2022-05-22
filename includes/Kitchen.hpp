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
    #include <list>
    #include <mutex>
    #include "Pipe.hpp"
    #include "Job.hpp"
    #include "Pizza.hpp"
    #include "Settings.hpp"

namespace Plazza {

    class KitchenOrder;

    class Kitchen {
        public:
            Kitchen(int id, Pipe *pipe, Pipe *masterPipe, Settings settings);
            ~Kitchen();

            Pipe *getPipe();

            Pipe *getMasterPipe();

            bool isActive(void) const;

            void setActive(bool status);

            std::string retrieveId(void);

            std::mutex mutex;

            int getId() const;

            std::list<Ingredients> &getAvailableIngredients();

            Settings getSettings();

            void pushOrder(Pizza *pizza);

        private:
            int _id;
            Pipe *_pipe;
            Pipe *_masterPipe;
            Settings _settings;


            std::queue<Pizza *> _orders;
            Job<Kitchen> *_orderHandler;
            std::vector<Job<Kitchen> *> _cooks;

            std::list<Ingredients> _ingredients;

            bool _isActive;
            void _handleKitchen(void);
            bool _updateOrders(void);

            void _fillIngredients(void);
            void _createCooks(void);
    };

}

#endif /* !KITCHEN_HPP_ */
