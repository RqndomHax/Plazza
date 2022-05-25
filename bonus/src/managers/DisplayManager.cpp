/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** DisplayManager
*/

#include <iostream>
#include <fstream>
#include <DisplayManager.hpp>
#include <OrderBuilder.hpp>
#include <StatusPrinter.hpp>
#include <Utils.hpp>
#include <ncurses.h>

namespace Plazza {

    DisplayManager::DisplayManager(Pizzeria *pizzeria) {
        this->_pizzeria = pizzeria;
        this->_kitchenId = 1;
        this->_isInitialized = false;
        this->_oldRefresh = std::clock();
        initscr();
        curs_set(0);
        cbreak();
        noecho();
        timeout(0);
<<<<<<< HEAD
=======
        start_color();
        init_pair(1, COLOR_BLACK, COLOR_BLUE); // black text on blue background
        init_pair(2, COLOR_BLUE, COLOR_BLACK); // blue text on black background
        init_pair(3, COLOR_RED, COLOR_WHITE); // red text on white background
        init_pair(4, COLOR_GREEN, COLOR_BLACK); // green text on black background
        init_pair(5, COLOR_CYAN, COLOR_BLACK); // cyan text on black background
>>>>>>> bonus
        keypad(stdscr, true);
    }

    DisplayManager::~DisplayManager() {
        if (!this->_pizzeria->isFork)
            endwin();
    }

    void DisplayManager::runDisplay() {
        if (this->_pizzeria->isFork)
            return;
        try {
            this->_parseInput();
        } catch (DisplayManager::Exit const &ignored) {
            return;
        }
        if (this->_pizzeria->isFork)
            return;
        if (!this->_isInitialized || this->_doesRefresh()) {
            this->_isInitialized = true;
            this->_printDisplay();
        }
        runDisplay();
    }

    void DisplayManager::_parseInput(void) {
        int c = getch();

        if (c == 27) {
            throw DisplayManager::Exit();
            return;
        }

        if (c == 259)
            if (this->_kitchenId > 1)
                this->_kitchenId -= 1;

        if (c == 258)
            if (this->_pizzeria->getKitchens().size() > (std::size_t) this->_kitchenId)
                this->_kitchenId += 1;

        if (c == 105)
            this->_pizzeria->dispatchOrder(OrderBuilder("margarita M x1", this->_pizzaManager).buildOrder());
        if (c == 106)
            this->_pizzeria->dispatchOrder(OrderBuilder("americana M x1", this->_pizzaManager).buildOrder());
        if (c == 107)
            this->_pizzeria->dispatchOrder(OrderBuilder("fantasia M x1", this->_pizzaManager).buildOrder());
        if (c == 117)
            this->_pizzeria->dispatchOrder(OrderBuilder("regina M x1", this->_pizzaManager).buildOrder());
    }

    void DisplayManager::_printDisplay(void) {
        clear();

<<<<<<< HEAD
        this->_printKichenInfos(this->_pizzeria->getKitchen(this->_kitchenId));
=======
        attron(COLOR_PAIR(4));
        this->_printKichenInfos(this->_pizzeria->getKitchen(this->_kitchenId));
        attron(COLOR_PAIR(5));
        this->_printInfos();
>>>>>>> bonus
        this->_printKitchens();
        refresh();
    }

<<<<<<< HEAD
=======
    int DisplayManager::_countKitchenClosed(void) const {
        int i = 0;

        for (KitchenInfo *info : this->_pizzeria->getKitchens())
            if (info->isClosed)
                i++;
        return (i);
    }

    void DisplayManager::_printInfos(void) {
        int x = 0;

        int closed_kitchens = this->_countKitchenClosed();

        mvprintw(1, x+=20, ("Kitchens active [" + std::to_string(this->_pizzeria->getKitchens().size() - closed_kitchens) + "]").c_str());
        mvprintw(1, x+=20, ("Kitchens closed [" + std::to_string(closed_kitchens) + "]").c_str());

        mvprintw(1, x+=20, ("Awaiting orders [" + std::to_string(this->_pizzeria->getAwaitingOrders().size()) + "]").c_str());
        mvprintw(1, x+=22, ("Processing orders [" + std::to_string(this->_pizzeria->getProcessingOrders().size()) + "]").c_str());
        mvprintw(1, x+=25, ("Completed orders [" + std::to_string(this->_pizzeria->getCompletedOrders().size()) + "]").c_str());
        mvprintw(1, x+=26, ("Total orders [" + std::to_string(this->_pizzeria->getTotalOrders().size()) + "]").c_str());

        x = 0;
        mvprintw(3, x+=25, "[U] - Order regina");
        mvprintw(3, x+=25, "[I] - Order margarita");
        mvprintw(3, x+=25, "[J] - Order americana");
        mvprintw(3, x+=25, "[K] - Order fantasia");
    }

>>>>>>> bonus
    void DisplayManager::_printKichenInfos(KitchenInfo *info) {
        if (info == nullptr)
            return;
        int y = 5;

        mvprintw(y += 2, 28, std::string("==== STATUS ====").c_str());

        mvprintw(y += 2, 28, ("Awaiting orders [" + std::to_string(info->getAwaitingOrders()->size()) + "]").c_str());
        mvprintw(y += 2, 28, ("Processing orders [" + std::to_string(info->getProcessingOrders()->size()) + "]").c_str());
        mvprintw(y += 2, 28, ("Completed orders [" + std::to_string(info->getCompletedOrders().size()) + "]").c_str());
        mvprintw(y += 2, 28, ("Total orders [" + std::to_string(info->getTotalOrders().size()) + "]").c_str());

        mvprintw(y += 2, 28, std::string("==== INGREDIENTS ====").c_str());
        mvprintw(y += 2, 28, ("Tomato: " + std::to_string(info->getIngredientsQuantity(TOMATO))).c_str());
        mvprintw(y += 2, 28, ("Gruyere: " + std::to_string(info->getIngredientsQuantity(GRUYERE))).c_str());
        mvprintw(y += 2, 28, ("Eggplant: " + std::to_string(info->getIngredientsQuantity(EGGPLANT))).c_str());
        mvprintw(y += 2, 28, ("Ham: " + std::to_string(info->getIngredientsQuantity(HAM))).c_str());
        mvprintw(y += 2, 28, ("Mushrooms: " + std::to_string(info->getIngredientsQuantity(MUSHROOMS))).c_str());
        mvprintw(y += 2, 28, ("Steak: " + std::to_string(info->getIngredientsQuantity(STEAK))).c_str());
        mvprintw(y += 2, 28, ("Goat cheese: " + std::to_string(info->getIngredientsQuantity(GOAT_CHEESE))).c_str());
        mvprintw(y += 2, 28, ("Chief love: " + std::to_string(info->getIngredientsQuantity(CHIEF_LOVE))).c_str());

        y = 5;
        mvprintw(y += 2, 70, std::string("==== PROCESSING ORDERS ====").c_str());
        for (std::list<Pizza *>::iterator it = info->getProcessingOrders()->begin(); it != info->getProcessingOrders()->end(); it++) {
            if (y >= COLS)
                return;
            mvprintw(y += 2, 70, (*it)->pack().c_str());
        }
<<<<<<< HEAD
=======
        y = 5;
        mvprintw(y += 2, 112, std::string("==== QUEUED ORDERS ====").c_str());
        for (std::list<Pizza *>::iterator it = info->getAwaitingOrders()->begin(); it != info->getAwaitingOrders()->end(); it++) {
            if (y >= COLS)
                return;
            mvprintw(y += 2, 112, (*it)->pack().c_str());
        }
>>>>>>> bonus
    }

    void DisplayManager::_printKitchens(void) {
        int y = 5;
        for (KitchenInfo *kitchen : this->_pizzeria->getKitchens()) {
            if (kitchen->getId() < this->_kitchenId)
                continue;
            if (y >= COLS)
                return;
<<<<<<< HEAD
=======
            if (!kitchen->isClosed) {
                attron(COLOR_PAIR(2));
                if (kitchen->getId() == this->_kitchenId)
                    attron(COLOR_PAIR(1));
            }
            else
                attron(COLOR_PAIR(3));
>>>>>>> bonus
            mvprintw(y += 2, 2, ("Kitchen[" + std::to_string(kitchen->getId()) + "]").c_str());
        }
    }

    bool DisplayManager::_doesRefresh(void) {
        clock_t current = std::clock();
        if (((double) (current - this->_oldRefresh) / CLOCKS_PER_SEC) * 60 >= 1) { // 60 hz monitor
            this->_oldRefresh = current;
            return (true);
        }
        return (false);
    }

}
