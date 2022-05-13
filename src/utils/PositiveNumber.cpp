/*
** EPITECH PROJECT, 2022
** utils
** File description:
** isNumberAndPositive
*/

bool isNumberAndPositive(char const *target)
{
    for (int i = 0; target[i]; i++)
        if (target[i] < '0' || target[i] > '9')
            return (false);
    return (true);
}
