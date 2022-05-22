/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** PizzeriaJob
*/

#ifndef PIZZERIAJOB_HPP_
    #define PIZZERIAJOB_HPP_
    #include "Job.hpp"
    #include "Pizzeria.hpp"
    #include <map>

namespace Plazza {

    class PizzeriaJob : public Job<Pizzeria> {
        public:
            PizzeriaJob(Pizzeria *jobOwner);

            ~PizzeriaJob();

            void runJob(void) override;

            void joinThread(void) override;

        private:
            Pizzeria *_jobOwner;
            std::thread _thread;
            bool _isRunning;

            std::map<std::string, void (PizzeriaJob::*)(KitchenInfo *kitchen)> _kitchenEvents;
            std::map<std::string, void (PizzeriaJob::*)(int cookId, Pizza *pizza, KitchenInfo *kitchen)> _cookEvents;

            void _restart(void);

            void _kitchenInitialized(KitchenInfo *kitchen);
            void _kitchenClosed(KitchenInfo *kitchen);

            void _cookPreparing(int cookId, Pizza *pizza, KitchenInfo *kitchen);
            void _cookFinished(int cookId, Pizza *pizza, KitchenInfo *kitchen);
            void _cookIngredients(int cookId, Pizza *pizza, KitchenInfo *kitchen);

            void _setKitchenEvents(void);
            void _setCookEvents(void);

            void _checkKitchenEvents(std::string line);
            void _checkCookEvents(std::string line);
    };

}

#endif /* !PIZZERIAJOB_HPP_ */
