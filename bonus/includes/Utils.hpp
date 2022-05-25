/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** Utils
*/

#ifndef UTILS_HPP_
    #define UTILS_HPP_

    #include <vector>
    #include <string>
    #include <list>
    #include "Pizza.hpp"

namespace Plazza {

    bool isNumberAndPositive(char const *target);

    std::vector<std::string> splitString(std::string target, std::string dlm);

    bool stringStartsWith(std::string prefix, std::string target);

    std::string retrieveError(void);

    Plazza::Pizza *autoRemoveOrder(std::list<Plazza::Pizza *> *pizzas, Plazza::Pizza *target);

    void autoClear(std::list<Plazza::Pizza *> *pizzas);

}

#endif /* !UTILS_HPP_ */
