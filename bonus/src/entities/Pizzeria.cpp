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
#include <sys/wait.h>
#include <Utils.hpp>

namespace Plazza {

    Pizzeria::Pizzeria(Settings &settings, Logger *logger) {
        this->_settings = settings;
        this->_nextId = 1;

        this->_totalOrders = {};
        this->_completedOrders = {};
        this->_processingOrders = {};
        this->_awaitingOrders = {};
        this->_masterPipe = new Pipe();
        this->_job = new PizzeriaJob(this);
        this->_logger = logger;
        this->isFork = false;
        this->isActive = true;
        *this->_logger << "Pizzeria initialized!";
    }

    Pizzeria::~Pizzeria() {
        this->mutex.lock();
        *this->_masterPipe << "\n";
        this->isActive = false;
        for (KitchenInfo *tmp : this->_kitchens) {
            if (tmp == nullptr)
                continue;
            *tmp->getPipe() << "[EXIT]";
            delete tmp->getPipe();
            delete tmp;
        }
        this->_kitchens.clear();
        autoClear(&this->_awaitingOrders);
        autoClear(&this->_processingOrders);
        autoClear(&this->_completedOrders);
        autoClear(&this->_totalOrders);
        this->mutex.unlock();
        if (this->_job != nullptr) {
            this->_job->joinThread();
            delete this->_job;
        }
        this->mutex.lock();
        if (this->_masterPipe != nullptr)
            delete this->_masterPipe;
        this->mutex.unlock();
    }

    void Pizzeria::dispatchOrder(Order order) {
        for (int i = 0; i < order.getQuantity(); i++) {
            KitchenInfo *kitchen = this->retrieveBestKitchen();

            if (kitchen == nullptr || this->isFork)
                return;
            *kitchen->getPipe() << "[COOK] " + order.getPizza().pack();
            kitchen->addAwaitingOrder(new Pizza(order.getPizza()));
            kitchen->addTotalOrder(new Pizza(order.getPizza()));
            this->_awaitingOrders.push_back(new Pizza(order.getPizza()));
            this->_totalOrders.push_back(new Pizza(order.getPizza()));
        }
    }

    void Pizzeria::dispatchOldOrders(std::list<Pizza *> *pizzas) {
        for (Pizza *pizza : *pizzas) {
            KitchenInfo *kitchen = this->retrieveBestKitchen();

            if (kitchen == nullptr || this->isFork)
                return;
            *kitchen->getPipe() << "[COOK] " + pizza->pack();
            kitchen->addAwaitingOrder(new Pizza(*pizza));
            kitchen->addTotalOrder(new Pizza(*pizza));
            this->_awaitingOrders.push_back(new Pizza(*pizza));
            this->_totalOrders.push_back(new Pizza(*pizza));

            delete pizza;
        }

        pizzas->clear();
    }

    void Pizzeria::removeKitchen(KitchenInfo *kitchen) {
        delete kitchen->getPipe();
        delete kitchen;
    }

    KitchenInfo *Pizzeria::createKitchen() {
        KitchenInfo *kitchenInfo = new KitchenInfo(this->_nextId++, new Pipe(), this->_masterPipe);
        this->isFork = kitchenInfo->createKitchen(this->_settings);
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
            
            if (kitchen->getAwaitingOrders()->size() + kitchen->getProcessingOrders()->size() >= (std::size_t) (this->_settings.getCooks() * 2))
                continue;
            if (bestKitchen == nullptr) {
                bestKitchen = kitchen;
                continue;
            }
            if (kitchen->getAwaitingOrders()->size() + kitchen->getProcessingOrders()->size() < bestKitchen->getAwaitingOrders()->size() + kitchen->getProcessingOrders()->size())
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

    std::list<Pizza *> Pizzeria::getAwaitingOrders(void) const {
        return (this->_awaitingOrders);
    }

    std::list<Pizza *> Pizzeria::getTotalOrders(void) const {
        return (this->_totalOrders);
    }

    std::list<Pizza *> Pizzeria::getCompletedOrders(void) const {
        return (this->_completedOrders);
    }

    void Pizzeria::addCompletedOrders(Pizza *pizza) {
        Pizza *target = autoRemoveOrder(&this->_processingOrders, pizza);

        if (target == nullptr)
            this->_completedOrders.push_back(new Pizza(*pizza));
        else
            this->_completedOrders.push_back(target);
    }

    std::list<Pizza *> Pizzeria::getProcessingOrders(void) const {
        return (this->_processingOrders);
    }

    void Pizzeria::addProcessingOrders(Pizza *pizza) {
        Pizza *target = autoRemoveOrder(&this->_awaitingOrders, pizza);

        if (target == nullptr)
            this->_processingOrders.push_back(new Pizza(*pizza));
        else
            this->_processingOrders.push_back(target);
    }

}
