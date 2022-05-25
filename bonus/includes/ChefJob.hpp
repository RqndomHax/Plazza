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
            ChefJob(int id, Kitchen *owner);
            ~ChefJob() override;

            int getId(void) const;

            bool hasPizza(void);

            void setPizza(Pizza *currentPizza);

            void runJob(void) override;

            void joinThread(void) override;

        private:
            int _id;
            Kitchen *_jobOwner;
            Pizza *_currentPizza;
            std::thread _thread;

            bool _statusIngredient;

            bool _hasIngredients(void);
            void _takeIngredients(void);
            std::string _retrieveId(void);
            std::string _getPizza(void);

            bool _isPresent(Ingredients target);
    };

}

#endif /* !CHEF_HPP_ */
