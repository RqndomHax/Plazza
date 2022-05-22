/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** PizzeriaJob
*/

#include <PizzeriaJob.hpp>

namespace Plazza {

    PizzeriaJob::PizzeriaJob(Pizzeria *jobOwner) {
        this->_jobOwner = jobOwner;
        this->_thread = std::thread(&PizzeriaJob::runJob, this);
    }

    PizzeriaJob::~PizzeriaJob() {
    }

    void PizzeriaJob::runJob(void) {
    }

    void PizzeriaJob::joinThread(void) {
        this->_thread.join();
    }
}
