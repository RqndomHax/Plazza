/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** ChefJob
*/

#ifndef CHEF_HPP_
    #define CHEF_HPP_
    #include "Job.hpp"
    #include "Kitchen.hpp"

namespace Plazza {

    class ChefJob : public Job<Kitchen> {
        public:
            ChefJob(Kitchen *owner);
            ~ChefJob() override;

            bool hasPizza(void);

            void setPizza(Pizza *currentPizza);

            void runJob(void) override;

            void joinThread(void) override;

        private:
            Kitchen *_jobOwner;
            Pizza *_currentPizza;
            std::thread _thread;
    };

}

#endif /* !CHEF_HPP_ */
