/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** KitchenOrder
*/

#include <iostream>
#include <thread>
#include <KitchenJob.hpp>
#include <Utils.hpp>

namespace Plazza {

    KitchenJob::KitchenJob(Kitchen *jobOwner) {
        this->_jobOwner = jobOwner;
        this->_thread = std::thread(&KitchenJob::runJob, this);
    }

    KitchenJob::~KitchenJob() {
    }

    void KitchenJob::_restart(void) {
        if (!this->_jobOwner->isActive())
            return;
        this->runJob();
    }

    void KitchenJob::_checkOrder(std::string line) {
        if (!stringStartsWith("[COOK]", line))
            return;
    }

    void KitchenJob::_checkExit(std::string line) {
        if (line == "[EXIT]")
            this->_jobOwner->setActive(false);
    }

    void KitchenJob::runJob(void) {
        if (this->_jobOwner == nullptr)
            return;

        std::string line = "";

        *this->_jobOwner->getPipe() >> line;

        this->_checkOrder(line);
        this->_checkExit(line);

        this->_restart();
    }

    void KitchenJob::joinThread(void) {
        this->_thread.join();
    }

}