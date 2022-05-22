/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** KitchenOrder
*/

#ifndef KITCHENORDER_HPP_
    #define KITCHENORDER_HPP_
    #include "Job.hpp"
    #include "Kitchen.hpp"

namespace Plazza {

    class KitchenOrder : public Job<Kitchen> {
        public:
            KitchenOrder(Kitchen *jobOwner);
            ~KitchenOrder() override;

            void runJob(void) override;

            void joinThread(void) override;

        private:
            std::thread _thread;
            Kitchen *_jobOwner;

            bool _isTarget(std::string line);
    };

}

#endif /* !KITCHENORDER_HPP_ */
