/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** Job
*/

#ifndef JOB_HPP_
    #define JOB_HPP_
    #include "Kitchen.hpp"
    #include "Pizza.hpp"

namespace Plazza {

    class Job {
        public:
            Job(Kitchen *owner);
            ~Job();

            void runJob(Pizza pizza);
        private:
            Kitchen *_owner;
            Pizza pizza;
    };

}

#endif /* !JOB_HPP_ */
