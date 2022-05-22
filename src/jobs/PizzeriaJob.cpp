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
        this->_thread = std::thread(&PizzeriaJob::runJob, this);
        this->_events["Kitchen initialized"] = &PizzeriaJob::_kitchenInitialized;
        this->_events["Kitchen closed"] = &PizzeriaJob::_kitchenClosed;
        this->_isRunning = true;
    }

    PizzeriaJob::~PizzeriaJob() {
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

    void PizzeriaJob::runJob(void) {
         std::string line = "";

        *this->_jobOwner->getMasterPipe() >> line;

        KitchenInfo *kitchen = this->_jobOwner->getKitchen(this->_getId(line));

        if (kitchen == nullptr)
            return (this->_restart());

        std::string parsed = line.substr(line.find(']') + 2);
        parsed.pop_back();

        void (PizzeriaJob::*func)(KitchenInfo *infos) = this->_events[parsed];
        if (func != nullptr)
           (this->*func)(kitchen);

        this->_restart();
    }

    void PizzeriaJob::joinThread(void) {
        this->_isRunning = false;
        this->_thread.join();
    }
}
