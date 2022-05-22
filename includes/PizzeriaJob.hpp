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
    };

}

#endif /* !PIZZERIAJOB_HPP_ */
