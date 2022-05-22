/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** Chef
*/

#ifndef CHEF_HPP_
    #define CHEF_HPP_
    #include "Job.hpp"
    #include "Kitchen.hpp"

namespace Plazza {

    class Chef : public Job<Kitchen> {
        public:
            Chef(Kitchen *owner);
            ~Chef() override;

            bool hasPizza(void);

            void setPizza(Pizza *currentPizza);

            void runJob(void) override;

            void joinThread(void) override;

        private:
            Kitchen *_jobOwner;
            Pizza *_currentPizza;
    };

}

#endif /* !CHEF_HPP_ */
