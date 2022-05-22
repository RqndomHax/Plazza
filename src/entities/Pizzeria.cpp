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

        this->_logger = logger;
        *this->_logger << "Pizzeria initialized!";
    }

    Pizzeria::~Pizzeria() {
        for (Job<Pizzeria> *tmp : this->_jobs) {
            PizzeriaJob *job = dynamic_cast<PizzeriaJob *>(tmp);
            job->joinThread();
            *job->getPipe() << "[EXIT]";
            delete job;
        }
        this->_jobs.clear();
    }

    void Pizzeria::dispatchOrder(Order order) {
        for (int i = 0; i < order.getQuantity(); i++) {
            PizzeriaJob *job = this->_getJob(1);
            *job->getPipe() << "[COOK] " + order.getPizza().pack();
        }
    }

    void Pizzeria::removeKitchen(int kitchenId) {
        for (Job<Pizzeria> *tmp : this->_jobs) {
            PizzeriaJob *job = dynamic_cast<PizzeriaJob *>(tmp);
            if (job->getId() != kitchenId)
                continue;
            *job->getPipe() << "[EXIT]";
            delete job;
        }
    }

    void Pizzeria::createKitchen() {
        Pipe *tmpPipe = new Pipe();
        int cpid = fork();

        if (cpid == 0) {
            Kitchen kitchen(this->_nextId, tmpPipe);
            return;
        }
        this->_jobs.push_back(new PizzeriaJob(this, this->_nextId++, tmpPipe));
    }

    Settings Pizzeria::getSettings() {
        return (this->_settings);
    }

    PizzeriaJob *Pizzeria::_getJob(int kitchenId) {
        for (Job<Pizzeria> *tmp : this->_jobs) {
            PizzeriaJob *job = dynamic_cast<PizzeriaJob *>(tmp);
            if (job->getId() == kitchenId)
                return (job);
        }
        return (nullptr);
    }
}
