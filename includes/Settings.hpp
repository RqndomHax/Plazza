/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** Settings
*/

#ifndef SETTINGS_HPP_
    #define SETTINGS_HPP_
    #include "PizzaManager.hpp"

namespace Plazza {

    class Settings {
        public:
            Settings() {}
            Settings(double cookingTime, int cooks, long replaceDuration);

            double getCookingTime(void) const;

            int getCooks(void) const;

            long getReplaceDuration(void) const;

            PizzaManager getPizzaManager(void);

        private:
            double _cookingTime;
            int _cooks;
            long _replaceDuration;
            PizzaManager _pizzaManager;
    };

}

#endif /* !SETTINGS_HPP_ */
