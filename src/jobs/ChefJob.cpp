/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** ChefJob
*/

#include <ChefJob.hpp>
#include <algorithm>
#include <thread>
#include <iostream>
#include <chrono>

namespace Plazza {

    ChefJob::ChefJob(int id, Kitchen *jobOwner) {
        this->_id = id;
        this->_jobOwner = jobOwner;
        this->_currentPizza = nullptr;
        this->_thread = std::thread(&ChefJob::runJob, this);
    }

    ChefJob::~ChefJob() {
        if (this->_currentPizza != nullptr)
            delete (this->_currentPizza);
    }

    bool ChefJob::hasPizza(void) {
        return (this->_currentPizza != nullptr);
    }

    void ChefJob::setPizza(Pizza *currentPizza) {
        this->_currentPizza = currentPizza;
    }

    bool ChefJob::_hasIngredients(void) {
        for (Ingredients ingredient : _currentPizza->getIngredients()) {
            std::list<Ingredients> available = this->_jobOwner->getAvailableIngredients();

            std::list<Ingredients>::iterator it = std::find(available.begin(), available.end(), ingredient);
            if (it == available.end())
                return (false);
        }
        return (true);
    }

    void ChefJob::_takeIngredients(void) {
        for (Ingredients ingredient : _currentPizza->getIngredients())
            this->_jobOwner->getAvailableIngredients().remove(ingredient);
    }

    std::string ChefJob::_retrieveId(void) {
        return ("[" + std::to_string(this->_id) + "] ");
    }

    void ChefJob::runJob(void) {
        while (this->_jobOwner != nullptr && this->_jobOwner->isActive()) {
            if (this->_currentPizza == nullptr)
                continue;

            if (!_hasIngredients()) {
                std::cout << "not enough ingredients !" << std::endl;
                continue;
            }
            this->_jobOwner->mutex.lock();
            this->_takeIngredients();
            this->_jobOwner->mutex.unlock();

            *this->_jobOwner->getMasterPipe() << this->_jobOwner->retrieveId() + this->_retrieveId() + "Pizza cooking.";
            double cookingTime = this->_currentPizza->getBakeTime() * this->_jobOwner->getSettings().getCookingTime();
            std::this_thread::sleep_for(std::chrono::milliseconds((size_t) (cookingTime * 1000)));

            *this->_jobOwner->getMasterPipe() << this->_jobOwner->retrieveId() + this->_retrieveId() + "Pizza finished.";

            delete this->_currentPizza;
            this->_currentPizza = nullptr;
        }
    }

    void ChefJob::joinThread(void) {
        this->_thread.join();
    }

}
