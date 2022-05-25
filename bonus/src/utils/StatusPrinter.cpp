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

        std::cout <<   "\t\t" << this->_pizzeria->getAwaitingOrders().size()
                    << "\t\t" << this->_pizzeria->getProcessingOrders().size()
                    << "\t\t" << this->_pizzeria->getCompletedOrders().size()
                    << "\t\t" << this->_pizzeria->getTotalOrders().size()
        << std::endl;
    }

    void StatusPrinter::print(void) const {
        this->_printSeparator();
        this->_printMainInfos();
        std::cout << std::endl;

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
                    << "\t\t" << info->getAwaitingOrders()->size()
                    << "\t\t\t" << info->getProcessingOrders()->size()
                    << "\t\t\t" << info->getCompletedOrders().size()
                    << "\t\t\t" << info->getTotalOrders().size()
        << std::endl;

        std::cout << "\nIngredients:"
                   << "\tDoe "
                   << "\t\tTomato"
                   << "\t\tGruyere"
                   << "\t\tEggplant"
                   << "\tHam"
                   << "\tMushrooms"
                   << "\tSteak"
                   << "\t\tGoat cheese"
                   << "\tChief love"
        << std::endl;

        std::cout << "\t\t" << info->getIngredientsQuantity(DOE)
                    << "\t\t" << info->getIngredientsQuantity(TOMATO)
                    << "\t\t" << info->getIngredientsQuantity(GRUYERE)
                    << "\t\t" << info->getIngredientsQuantity(EGGPLANT)
                    << "\t\t" << info->getIngredientsQuantity(HAM)
                    << "\t" << info->getIngredientsQuantity(MUSHROOMS)
                    << "\t\t" << info->getIngredientsQuantity(STEAK)
                    << "\t\t" << info->getIngredientsQuantity(GOAT_CHEESE)
                    << "\t\t" << info->getIngredientsQuantity(CHIEF_LOVE)
        << std::endl;

    }


}
