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

bool isNumberAndPositive(char const *target);

std::vector<std::string> splitString(std::string target, std::string dlm);

bool stringStartsWith(std::string prefix, std::string target);

#endif /* !UTILS_HPP_ */
