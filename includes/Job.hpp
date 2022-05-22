/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** Job
*/

#ifndef JOB_HPP_
    #define JOB_HPP_
    #include <thread>

namespace Plazza {

    template<class Owner>
    class Job {
        public:
            virtual ~Job() = default;

            virtual void runJob(void) = 0;

            virtual void joinThread(void) = 0;
    };

}

#endif /* !JOB_HPP_ */
