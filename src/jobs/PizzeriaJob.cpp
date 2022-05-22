/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** PizzeriaJob
*/

#include <PizzeriaJob.hpp>

namespace Plazza {

    PizzeriaJob::PizzeriaJob(Pizzeria *jobOwner, int id, Pipe *pipe) {
        this->_jobOwner = jobOwner;
        this->_id = id;
        this->_pipe = pipe;
        this->_thread = std::thread(&PizzeriaJob::runJob, this);
    }

    PizzeriaJob::~PizzeriaJob() {
        if (this->_pipe != nullptr)
            delete this->_pipe;
    }

    Pipe *PizzeriaJob::getPipe(void) {
        return (this->_pipe);
    }

    int PizzeriaJob::getId(void) const {
        return (this->_id);
    }

    void PizzeriaJob::runJob(void) {
    }

    void PizzeriaJob::joinThread(void) {
        this->_thread.join();
    }
}
