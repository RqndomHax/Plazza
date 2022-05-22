/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** StatusPrinter
*/

#include <iostream>
#include <StatusPrinter.hpp>

namespace Plazza {

    StatusPrinter::StatusPrinter(Pizzeria *pizzeria) {
        this->_pizzeria = pizzeria;
    }

    StatusPrinter::~StatusPrinter() {
    }

    void StatusPrinter::_printSeparator(void) const {
        std::cout << "|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|";
    }

    void StatusPrinter::_printMainInfos(void) const {
        std::cout << "\n\nKitchens" 
                   << "\tOpened"
                   << "\t\tClosed"
        << std::endl;

        int closedKitchens = this->_countKitchenClosed();

        std::cout <<   "\t\t" << this->_pizzeria->getKitchens().size() - closedKitchens
                    << "\t\t" << closedKitchens
        << std::endl;

        std::cout << "\nOrders " 
                   << "\t\tAwaiting"
                   << "\tIn progress"
                   << "\tCompleted"
                   << "\tTotal"
        << std::endl;

        std::cout <<   "\t\t" << this->_pizzeria->getAwaitingOrders()
                    << "\t\t" << this->_pizzeria->inProgressOrders
                    << "\t\t" << this->_pizzeria->getCompletedOrders()
                    << "\t\t" << this->_pizzeria->getTotalOrders()
        << std::endl;
    }

    void StatusPrinter::print(void) const {
        this->_printSeparator();
        this->_printMainInfos();
        std::cout << std::endl;
        this->_printSeparator();

        for (std::size_t i = 0; i < this->_pizzeria->getKitchens().size(); i++) {
            this->_printSeparator();
            std::cout << std::endl << std::endl;
            this->_printKitchen(i + 1);
            std::cout << std::endl;
        }

        this->_printSeparator();
        std::cout << std::endl;
    }

    int StatusPrinter::_countKitchenClosed(void) const {
        int i = 0;

        for (KitchenInfo *info : this->_pizzeria->getKitchens())
            if (info->isClosed)
                i++;
        return (i);
    }

    void StatusPrinter::_printKitchen(int id) const {

        KitchenInfo *info = this->_pizzeria->getKitchen(id);
        if (info == nullptr)
            return;

        std::cout << "\nKitchen: " << id 
                   << "\tState: "
                   << "\t\tOrders awaiting"
                   << "\t\tOrders in progress"
                   << "\tCompleted orders"
                   << "\tTotal orders"
        << std::endl;

        std::cout <<   "\t\t" << (info->isClosed ? "Closed" : "Opened")
                    << "\t\t\t\t" << info->getAwaitingOrders()
                    << "\t\t" << info->getProcessingOrders()
                    << "\t\t\t" << info->getCompletedOrders()
                    << "\t\t\t" << info->getTotalOrders()
        << std::endl;
    }


}
