/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** Kitchen
*/

#include <unistd.h>
#include <iostream>
#include <ctime>
#include <chrono>
#include <Kitchen.hpp>
#include <Job.hpp>
#include <KitchenJob.hpp>

namespace Plazza {

    Kitchen::Kitchen(int id, Pipe *pipe, Pipe *masterPipe) {
        this->_id = id;
        this->_pipe = pipe;
        this->_masterPipe = masterPipe;

        this->_isActive = true;
        *masterPipe << this->retrieveId() + "Kitchen initialized.";
        this->_orderHandler = new KitchenJob(this);
        this->_handleKitchen();
    }

    Kitchen::~Kitchen() {
        for (Job<Kitchen> *job : this->_cooks)
            if (job != nullptr) {
                job->joinThread();
                delete job;
            }

        if (this->_orderHandler != nullptr) {
            this->_orderHandler->joinThread();
            delete this->_orderHandler;
        }

        this->_cooks.clear();
    }

    Pipe *Kitchen::getPipe() {
        return (this->_pipe);
    }

    void Kitchen::setActive(bool status) {
        this->_isActive = status;
    }

    bool Kitchen::isActive(void) const {
        return (this->_isActive);
    }

    std::string Kitchen::retrieveId() {
        return ("[" + std::to_string(this->_id) + "] ");
    }

    int Kitchen::getId() const {
        return (this->_id);
    }

    void Kitchen::_handleKitchen() {
        auto t_start = std::chrono::high_resolution_clock::now();
        while (this->_isActive) {
            auto t_end = std::chrono::high_resolution_clock::now();

            double elapsed_time_ms = std::chrono::duration<double, std::milli>(t_end-t_start).count();

            if (elapsed_time_ms >= 5000) {
                this->_isActive = false;
            }
        }
        std::exit(0);
    }

}
