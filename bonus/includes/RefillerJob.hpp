/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** RefillerJob
*/

#ifndef REFILLERJOB_HPP_
    #define REFILLERJOB_HPP_
    #include "Job.hpp"
    #include "Kitchen.hpp"

namespace Plazza {

    class RefillerJob : public Job<Kitchen> {
        public:
            RefillerJob(Kitchen *jobOwner);
            ~RefillerJob() override;

            void runJob(void) override;

            void joinThread(void) override;

        private:
            std::thread _thread;
            Kitchen *_jobOwner;

            bool _isRunning;

    };

}

#endif /* !REFILLERJOB_HPP_ */
