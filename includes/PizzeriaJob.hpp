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

            std::map<std::string, void (PizzeriaJob::*)(KitchenInfo *infos)> _events;

            void _restart(void);
            void _kitchenInitialized(KitchenInfo *kitchen);
            void _kitchenClosed(KitchenInfo *kitchen);
            int _getId(std::string line);
            bool _isRunning;
    };

}

#endif /* !PIZZERIAJOB_HPP_ */
