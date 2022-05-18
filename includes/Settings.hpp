/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** Settings
*/

#ifndef SETTINGS_HPP_
    #define SETTINGS_HPP_

namespace Plazza {

    class Settings {
        public:
            Settings() {}
            Settings(double cookingTime, int cooks, long replaceDuration);

            double getCookingTime();
            int getCooks();
            long getReplaceDuration();

        private:
            double _cookingTime;
            int _cooks;
            long _replaceDuration;
    };

}

#endif /* !SETTINGS_HPP_ */
