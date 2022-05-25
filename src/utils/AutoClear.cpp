/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** AutoClear
*/

#include <Pizza.hpp>
#include <list>

namespace Plazza {

    void autoClear(std::list<Plazza::Pizza *> *pizzas) {

        if (pizzas == nullptr)
            return;

        for (Plazza::Pizza *pizza : *pizzas)
            if (pizza != nullptr)
                delete pizza;

        pizzas->clear();
    }

}
