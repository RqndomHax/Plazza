/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** PizzeriaJob
*/

#include <PizzeriaJob.hpp>
#include <iostream>
#include <Utils.hpp>

namespace Plazza {

    PizzeriaJob::PizzeriaJob(Pizzeria *jobOwner) {
        this->_jobOwner = jobOwner;

        this->_setCookEvents();
        this->_setKitchenEvents();

        this->_isRunning = true;

        this->_thread = std::thread(&PizzeriaJob::runJob, this);
    }

    PizzeriaJob::~PizzeriaJob() {
    }

    void PizzeriaJob::_setKitchenEvents(void) {
        this->_kitchenEvents["Kitchen initialized"] = &PizzeriaJob::_kitchenInitialized;
        this->_kitchenEvents["Kitchen closed"] = &PizzeriaJob::_kitchenClosed;
    }

    void PizzeriaJob::_setCookEvents(void) {
        this->_cookEvents["Cooking"] = &PizzeriaJob::_cookPreparing;
        this->_cookEvents["Cooking finished"] = &PizzeriaJob::_cookFinished;
        this->_cookEvents["Cook need ingredients"] = &PizzeriaJob::_cookIngredients;
    }

    void PizzeriaJob::_cookPreparing(int cookId, Pizza *pizza, KitchenInfo *kitchen) {
        (void) cookId;
        (void) pizza;
        (void) kitchen;
        std::cout << "Pizza is being prepared" << std::endl;
    }

    void PizzeriaJob::_cookFinished(int cookId, Pizza *pizza, KitchenInfo *kitchen) {
        (void) cookId;
        (void) pizza;
        (void) kitchen;
        std::cout << "Pizza is finished" << std::endl;
    }

    void PizzeriaJob::_cookIngredients(int cookId, Pizza *pizza, KitchenInfo *kitchen) {
        (void) cookId;
        (void) pizza;
        (void) kitchen;
        std::cout << "Cook need ingredients" << std::endl;
    }

    void PizzeriaJob::_kitchenInitialized(KitchenInfo *kitchen) {
        *this->_jobOwner->getLogger() << kitchen->retrieveId() + "Kitchen initialized.";
    }

    void PizzeriaJob::_kitchenClosed(KitchenInfo *kitchen) {
        *this->_jobOwner->getLogger() << kitchen->retrieveId() + "Kitchen closed.";
        this->_jobOwner->removeKitchen(kitchen);
    }

    void PizzeriaJob::_restart(void) {
        if (!this->_isRunning)
            return;
        this->runJob();
    }

    void PizzeriaJob::_checkKitchenEvents(std::string line) {
        std::vector<std::string> content = splitString(line, "/");

        if (content.size() != 2)
            return;

        KitchenInfo *kitchen = this->_jobOwner->getKitchen(std::atoi(content[0].c_str()));

        if (kitchen == nullptr)
            return;

        std::string parsed = content[1];
        parsed.pop_back();

        void (PizzeriaJob::*func)(KitchenInfo *infos) = this->_kitchenEvents[parsed];
        if (func != nullptr)
           (this->*func)(kitchen);
    }
    
    void PizzeriaJob::_checkCookEvents(std::string line) {
        std::vector<std::string> content = splitString(line, "/");

        if (content.size() != 4)
            return;

        KitchenInfo *kitchen = this->_jobOwner->getKitchen(std::atoi(content[0].c_str()));

        if (kitchen == nullptr)
            return;
        
        int cookId = std::atoi(content[1].c_str());
        if (cookId == -1)
            return;
        
        Pizza *pizza = this->_jobOwner->getSettings().getPizzaManager().unpackPizza(content[2]);

        std::string parsed = content[3];
        parsed.pop_back();

        void (PizzeriaJob::*func)(int cookId, Pizza *pizza, KitchenInfo *kitchen) = this->_cookEvents[parsed];
        if (func != nullptr)
           (this->*func)(cookId, pizza, kitchen);
        delete pizza;
    }

    void PizzeriaJob::runJob(void) {
         std::string line = "";

        *this->_jobOwner->getMasterPipe() >> line;

        this->_checkKitchenEvents(line);
        this->_checkCookEvents(line);

        this->_restart();
    }

    void PizzeriaJob::joinThread(void) {
        this->_isRunning = false;
        this->_thread.join();
    }
}
