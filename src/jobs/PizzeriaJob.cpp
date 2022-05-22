/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** PizzeriaJob
*/

#include <PizzeriaJob.hpp>
#include <iostream>

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
        this->_cookEvents["Cook preparing"] = &PizzeriaJob::_cookPreparing;
    }

    void PizzeriaJob::_cookPreparing(int cookId, Pizza *pizza, KitchenInfo *kitchen) {
        (void) cookId;
        (void) pizza;
        (void) kitchen;
        std::cout << "Pizza is being prepared" << std::endl;
    }

    void PizzeriaJob::_kitchenInitialized(KitchenInfo *kitchen) {
        *this->_jobOwner->getLogger() << kitchen->retrieveId() + "Kitchen initialized.";
    }

    void PizzeriaJob::_kitchenClosed(KitchenInfo *kitchen) {
        std::cout << "closed" << std::endl;
        *this->_jobOwner->getLogger() << kitchen->retrieveId() + "Kitchen closed.";
        this->_jobOwner->removeKitchen(kitchen);
    }

    void PizzeriaJob::_restart(void) {
        if (!this->_isRunning)
            return;
        this->runJob();
    }

    int PizzeriaJob::_getId(std::string line) {
        std::size_t pos1 = line.find('[');
        std::size_t pos2 = line.find(']');

        if (pos1 == std::string::npos || pos2 == std::string::npos)
            return (-1);
        return (std::atoi(line.substr(pos1 + 1, pos2).c_str()));
    }

    void PizzeriaJob::_checkKitchenEvents(std::string line) {
        KitchenInfo *kitchen = this->_jobOwner->getKitchen(this->_getId(line));

        if (kitchen == nullptr)
            return;

        std::string parsed = line.substr(line.find(']') + 2);
        parsed.pop_back();

        void (PizzeriaJob::*func)(KitchenInfo *infos) = this->_kitchenEvents[parsed];
        if (func != nullptr)
           (this->*func)(kitchen);
    }
    
    void PizzeriaJob::_checkCookEvents(std::string line) {
        KitchenInfo *kitchen = this->_jobOwner->getKitchen(this->_getId(line));

        if (kitchen == nullptr)
            return;
        
        std::string tmp = line.substr(line.find(']') + 2);

        std::cout << "tmp = [" << tmp << "]" << std::endl;
    }

    void PizzeriaJob::runJob(void) {
         std::string line = "";

        *this->_jobOwner->getMasterPipe() >> line;

        std::cout << "master = [" << line << "]" << std::endl;

        this->_checkKitchenEvents(line);
        this->_checkCookEvents(line);

        this->_restart();
    }

    void PizzeriaJob::joinThread(void) {
        this->_isRunning = false;
        this->_thread.join();
    }
}
