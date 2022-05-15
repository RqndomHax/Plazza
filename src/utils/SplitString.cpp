/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** SplitString
*/

#include <vector>
#include <string>

std::vector<std::string> splitString(std::string target, std::string dlm) {
    std::vector<std::string> result;

    std::size_t pos = 0;
    std::size_t oldpos = 0;
    while (pos != std::string::npos) {
        pos = target.find(dlm, oldpos);
        std::string tmp = target.substr(oldpos, pos - oldpos);
        if (tmp.size() != 0)
            result.push_back(tmp); 
        oldpos = pos + dlm.size();
    }
    return (result);
}
