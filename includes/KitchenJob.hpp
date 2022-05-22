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

    class KitchenJob : public Job<Kitchen> {
        public:
            KitchenJob(Kitchen *jobOwner);
            ~KitchenJob() override;

            void _restart(void);

            void runJob(void) override;

            void joinThread(void) override;

        private:
            std::thread _thread;
            Kitchen *_jobOwner;

            bool _isTarget(std::string line);

            void _checkOrder(std::string line);

            void _checkExit(std::string line);

    };

}

#endif /* !KITCHENORDER_HPP_ */
