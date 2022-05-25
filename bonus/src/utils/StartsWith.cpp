/*
** EPITECH PROJECT, 2022
**  Utils
** File description:
** StartsWith
*/

#include <string>

namespace Plazza {

    bool stringStartsWith(std::string prefix, std::string target) {
        if (target.size() < prefix.size())
            return (false); 
        if (target.substr(0, prefix.size()) != prefix)
            return (false);
        return (true);
    }

}
