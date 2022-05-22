/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** KitchenOrder
*/

#include <iostream>
#include <thread>
#include <KitchenJob.hpp>

namespace Plazza {

    KitchenOrder::KitchenOrder(Kitchen *jobOwner) {
        this->_jobOwner = jobOwner;
        this->_thread = std::thread(&KitchenOrder::runJob, this);
    }

    KitchenOrder::~KitchenOrder() {
    }

    void KitchenOrder::runJob(void) {
        if (this->_jobOwner == nullptr)
            return;

        std::string line = "";

        *this->_jobOwner->getIPC() >> line;

        if (this->_isTarget(line))
            std::cout << "order asked !" << std::endl;

        if (this->_jobOwner->isActive())
            this->runJob();
    }

    bool KitchenOrder::_isTarget(std::string line) {

        std::size_t start = line.find('[');
        std::size_t end = line.find(']');

        if (start == std::string::npos || end == std::string::npos)
            return (false);
        
        std::string target = line.substr(start, end);

        std::cout << "target = [" << target << "]" << std::endl;
        if (target == "[COOK " + std::to_string(this->_jobOwner->getId()) + "]")
            return (true);
        return (false);
    }

    void KitchenOrder::joinThread(void) {
        this->_thread.join();
    }

}