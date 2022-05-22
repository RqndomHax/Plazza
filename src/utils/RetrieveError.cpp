/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** RetrieveError
*/

#include <string.h>
#include <string>

std::string retrieveError(void) {
    std::string error = strerror(errno);

    return (error);
}
