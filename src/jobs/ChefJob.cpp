/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** ChefJob
*/

#include <ChefJob.hpp>

namespace Plazza {

    ChefJob::ChefJob(Kitchen *jobOwner) {
        this->_jobOwner = jobOwner;
        this->_thread = std::thread(&ChefJob::runJob, this);
    }

    ChefJob::~ChefJob() {
    }

    bool ChefJob::hasPizza(void) {
        return (this->_currentPizza != nullptr);
    }

    void ChefJob::setPizza(Pizza *currentPizza) {
        this->_currentPizza = currentPizza;
    }

    void ChefJob::runJob(void) {
        
    }

    void ChefJob::joinThread(void) {
        this->_thread.join();
    }

}
