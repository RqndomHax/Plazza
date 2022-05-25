/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** AutoRemoveOrder
*/

#include <Pizza.hpp>
#include <list>
#include <algorithm>

namespace Plazza {

    Pizza *autoRemoveOrder(std::list<Pizza *> *pizzas, Pizza *target) {
        Pizza *tmp = nullptr;

        if (target == nullptr)
            return (tmp);
        for (Pizza *pizza : *pizzas) {
            if (pizza->getType() != target->getType() || pizza->getSize() != target->getSize())
                continue;
            tmp = pizza;
            break;
        }

        if (tmp == nullptr)
            return (nullptr);
        std::list<Pizza *>::iterator it = std::find(pizzas->begin(), pizzas->end(), tmp);
        pizzas->erase(it);
        return (tmp);
    }

}
