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
#include <ChefJob.hpp>
#include <RefillerJob.hpp>

namespace Plazza {

    Kitchen::Kitchen(int id, Pipe *pipe, Pipe *masterPipe, Settings settings) {
        this->_id = id;
        this->_pipe = pipe;
        this->_masterPipe = masterPipe;
        this->_settings = settings;

        this->_isActive = true;
        this->updateClock = false;

        this->_ingredients = {};

        for (int i = 0; i < 5; i++)
            this->fillIngredients();
        this->_createCooks();

        this->_orderHandler = new KitchenJob(this);
        this->_refiller = new RefillerJob(this);
        *masterPipe << this->retrieveId() + "Kitchen initialized.";
        this->_handleKitchen();
    }

    Kitchen::~Kitchen() {
        *this->_pipe << "\n";
        for (Job<Kitchen> *job : this->_cooks)
            if (job != nullptr) {
                job->joinThread();
                delete job;
            }
        
        if (this->_orderHandler != nullptr) {
            this->_orderHandler->joinThread();
            delete this->_orderHandler;
        }

        if (this->_refiller != nullptr) {
            this->_refiller->joinThread();
            delete (this->_refiller);
        }

        while (!this->_orders.empty()) {
            delete this->_orders.front();
            this->_orders.pop();
        }

        this->_cooks.clear();
        *this->_masterPipe << this->retrieveId() + "Kitchen closed.";
    }

    void Kitchen::fillIngredients(void) {
        this->_ingredients.push_back(DOE);
        this->_ingredients.push_back(TOMATO);
        this->_ingredients.push_back(GRUYERE);
        this->_ingredients.push_back(EGGPLANT);
        this->_ingredients.push_back(HAM);
        this->_ingredients.push_back(MUSHROOMS);
        this->_ingredients.push_back(STEAK);
        this->_ingredients.push_back(GOAT_CHEESE);
        this->_ingredients.push_back(CHIEF_LOVE);
    }

    std::list<Ingredients> *Kitchen::getAvailableIngredients(void) {
        return (&this->_ingredients);
    }

    void Kitchen::_createCooks(void) {
        for (int i = 0; i < this->_settings.getCooks(); i++)
            this->_cooks.push_back(new ChefJob(i + 1, this));
    }

    Pipe *Kitchen::getPipe(void) {
        return (this->_pipe);
    }

    Pipe *Kitchen::getMasterPipe(void) {
        return (this->_masterPipe);
    }

    Settings Kitchen::getSettings(void) {
        return (this->_settings);
    }

    void Kitchen::setActive(bool status) {
        this->_isActive = status;
    }

    bool Kitchen::isActive(void) const {
        return (this->_isActive);
    }

    std::string Kitchen::retrieveId() {
        return (std::to_string(this->_id) + "/");
    }

    int Kitchen::getId() const {
        return (this->_id);
    }

    void Kitchen::pushOrder(Pizza *pizza) {
        this->_orders.push(pizza);
    }

    void Kitchen::_updateOrders(void) {

        for (Job<Kitchen> *job : this->_cooks) {
            ChefJob *cook = dynamic_cast<ChefJob *>(job);

            if (this->_orders.empty())
                return;

            if (!cook->hasPizza()) {
                cook->setPizza(this->_orders.front());
                this->_orders.pop();
            }
        }
    }

    void Kitchen::_handleKitchen() {
        auto t_start = std::chrono::high_resolution_clock::now();
        while (this->_isActive) {
            auto t_end = std::chrono::high_resolution_clock::now();

            double elapsed_time_ms = std::chrono::duration<double, std::milli>(t_end-t_start).count();

            this->mutex.lock();
            if (this->updateClock) {
                this->updateClock = false;
                t_start = t_end;
            }
            this->mutex.unlock();

            if (elapsed_time_ms >= 5000) {
                this->mutex.lock();
                this->_isActive = false;
                this->mutex.unlock();
                return;
            }

            this->mutex.lock();
            if (this->_orders.empty()) {
                this->mutex.unlock();
                continue;
            }

            this->_updateOrders();
            this->mutex.unlock();
        }
    }

}
