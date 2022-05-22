/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** Pizzeria
*/

#include <algorithm>
#include <Pizzeria.hpp>
#include <Kitchen.hpp>
#include <PizzeriaJob.hpp>
#include <unistd.h>
#include <iostream>

namespace Plazza {

    Pizzeria::Pizzeria(Settings &settings, Logger *logger) {
        this->_settings = settings;
        this->_nextId = 1;

        this->_totalOrders = 0;
        this->_completedOrders = 0;
        this->inProgressOrders = 0;
        this->_masterPipe = new Pipe();
        this->_job = new PizzeriaJob(this);
        this->_logger = logger;
        *this->_logger << "Pizzeria initialized!";
    }

    Pizzeria::~Pizzeria() {
        *this->_masterPipe << "\n";
        for (KitchenInfo *tmp : this->_kitchens) {
            *tmp->getPipe() << "[EXIT]";
            delete tmp->getPipe();
            delete tmp;
        }
        if (this->_job != nullptr) {
            this->_job->joinThread();
            delete this->_job;
        }
        if (this->_masterPipe != nullptr)
            delete this->_masterPipe;
        this->_kitchens.clear();
    }

    void Pizzeria::dispatchOrder(Order order) {
        for (int i = 0; i < order.getQuantity(); i++) {
            KitchenInfo *kitchen = this->retrieveBestKitchen();

            *kitchen->getPipe() << "[COOK] " + order.getPizza().pack();
            kitchen->addTotalOrder();
            this->_totalOrders += 1;
        }
    }

    void Pizzeria::removeKitchen(KitchenInfo *kitchen) {
        delete kitchen->getPipe();
        delete kitchen;
    }

    KitchenInfo *Pizzeria::createKitchen() {
        KitchenInfo *kitchenInfo = new KitchenInfo(this->_nextId++, new Pipe(), this->_masterPipe);
        kitchenInfo->createKitchen(this->_settings);
        this->_kitchens.push_back(kitchenInfo);
        return (kitchenInfo);
    }

    Settings Pizzeria::getSettings() {
        return (this->_settings);
    }

    KitchenInfo *Pizzeria::getKitchen(int kitchenId) {
        for (KitchenInfo *kitchen : this->_kitchens) {
            if (kitchen->getId() == kitchenId)
                return (kitchen);
        }
        return (nullptr);
    }

    KitchenInfo *Pizzeria::retrieveBestKitchen(void) {
        if (this->_kitchens.size() == 0)
            return (createKitchen());

        KitchenInfo *bestKitchen = nullptr;

        for (KitchenInfo *kitchen : this->_kitchens) {
            if (kitchen->isClosed)
                continue;
            
            if (kitchen->getAwaitingOrders() + kitchen->getProcessingOrders() >= this->_settings.getCooks() * 2)
                continue;
            if (bestKitchen == nullptr) {
                bestKitchen = kitchen;
                continue;
            }
            if (kitchen->getAwaitingOrders() + kitchen->getProcessingOrders() < bestKitchen->getAwaitingOrders() + kitchen->getProcessingOrders())
                bestKitchen = kitchen;
        }

        if (bestKitchen == nullptr)
            return (createKitchen());
        return (bestKitchen);
    }

    std::vector<KitchenInfo *> Pizzeria::getKitchens(void) {
        return (this->_kitchens);
    }

    Pipe *Pizzeria::getMasterPipe(void) {
        return (this->_masterPipe);
    }

    Logger *Pizzeria::getLogger(void) {
        return (this->_logger);
    }

    int Pizzeria::getAwaitingOrders(void) const {
        return (this->_totalOrders - (this->_completedOrders + this->inProgressOrders));
    }

    int Pizzeria::getTotalOrders(void) const {
        return (this->_totalOrders);
    }

    int Pizzeria::getCompletedOrders(void) const {
        return (this->_completedOrders);
    }

    void Pizzeria::addCompletedOrders(void) {
        this->_completedOrders += 1;
    }

}
