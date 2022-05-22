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

    void KitchenJob::runJob(void) {
        if (this->_jobOwner == nullptr)
            return;

        std::string line = "";

        *this->_jobOwner->getIPC() >> line;

        if (!stringStartsWith("[COOK]", line))
            return (_restart());

        std::cout << "order asked !" << std::endl;

        if (this->_jobOwner->isActive())
            this->runJob();
    }

    void KitchenJob::joinThread(void) {
        this->_thread.join();
    }

}