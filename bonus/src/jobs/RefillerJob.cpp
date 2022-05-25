/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** KitchenOrder
*/

#include <thread>
#include <RefillerJob.hpp>
#include <Utils.hpp>

namespace Plazza {

    RefillerJob::RefillerJob(Kitchen *jobOwner) {
        this->_jobOwner = jobOwner;
        this->_isRunning = true;
        this->_thread = std::thread(&RefillerJob::runJob, this);
    }

    RefillerJob::~RefillerJob() {
    }

    void RefillerJob::runJob(void) {
        long replaceDuration = this->_jobOwner->getSettings().getReplaceDuration();
        while (this->_jobOwner != nullptr && this->_isRunning) {
            std::this_thread::sleep_for(std::chrono::milliseconds(replaceDuration));
            this->_jobOwner->mutex.lock();
            this->_jobOwner->fillIngredients();
            *this->_jobOwner->getMasterPipe() << this->_jobOwner->retrieveId() + "Kitchen refilling.";
            this->_jobOwner->mutex.unlock();
        }
    }

    void RefillerJob::joinThread(void) {
        this->_isRunning = false;
        this->_thread.join();
    }

}