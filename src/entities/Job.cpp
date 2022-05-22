/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** Job
*/

#include <Job.hpp>

namespace Plazza {

    Job::Job(Kitchen *owner) {
        this->_owner = owner;
    }

    Job::~Job() {
    }

    void Job::runJob(Pizza pizza) {
        (void) pizza;
    }

}
