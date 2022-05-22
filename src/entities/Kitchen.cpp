/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** Kitchen
*/

#include <iostream>
#include <Kitchen.hpp>
#include <Job.hpp>
#include <KitchenJob.hpp>
#include <unistd.h>
#include <chrono>

namespace Plazza {

    Kitchen::Kitchen(int id, Pipe *pipe) {
        this->_id = id;
        this->_pipe = pipe;

        this->_isActive = true;
        *pipe << this->retrieveId() + "Kitchen initialized.";
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

    Pipe *Kitchen::getIPC() {
        return (this->_pipe);
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
        while (this->_isActive) {
            std::string line = "";

            *this->_pipe >> line;

            if (line == "[EXIT]")
                this->_isActive = false;
        }
        std::exit(0);
    }

}
