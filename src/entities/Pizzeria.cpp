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

namespace Plazza {

    Pizzeria::Pizzeria(Settings &settings, Logger *logger) {
        this->_settings = settings;
        this->_nextId = 1;

        this->_masterPipe = new Pipe();
        this->_job = new PizzeriaJob(this);
        this->_logger = logger;
        *this->_logger << "Pizzeria initialized!";
    }

    Pizzeria::~Pizzeria() {
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
            KitchenInfo *kitchen = this->getKitchen(1);
            *kitchen->getPipe() << "[COOK] " + order.getPizza().pack();
        }
    }

    void Pizzeria::removeKitchen(KitchenInfo *kitchen) {
        delete kitchen->getPipe();
        delete kitchen;
    }

    void Pizzeria::createKitchen() {
        KitchenInfo *kitchenInfo = new KitchenInfo(this->_nextId++, new Pipe(), this->_masterPipe);
        kitchenInfo->createKitchen();
        this->_kitchens.push_back(kitchenInfo);
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

    Pipe *Pizzeria::getMasterPipe(void) {
        return (this->_masterPipe);
    }

    Logger *Pizzeria::getLogger(void) {
        return (this->_logger);
    }

}
