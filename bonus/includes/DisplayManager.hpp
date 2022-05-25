/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** DisplayManager
*/

#ifndef DISPLAYMANAGER_HPP_
    #define DISPLAYMANAGER_HPP_
    #include <string>
    #include "PizzaManager.hpp"
    #include "Pizzeria.hpp"

namespace Plazza {

    class DisplayManager {
        public:
            DisplayManager(Pizzeria *pizzeria);
            ~DisplayManager();

            void runDisplay();

            class Error : public std::exception {
                public:

                    Error(std::string message) : _message(message) {}

                    char const *what() const noexcept override {
                        return (this->_message).c_str();
                    }

                private:
                    std::string const _message;
            };

            class Exit : public std::exception {
            };

        private:
            void _parseInput(void);

            bool _doesRefresh(void);

            void _printDisplay(void);

            void _printKichenInfos(KitchenInfo *info);

            void _printKitchens(void);

<<<<<<< HEAD
=======
            void _printInfos(void);

            int _countKitchenClosed(void) const;

>>>>>>> bonus
            Pizzeria *_pizzeria;

            PizzaManager _pizzaManager;

            int _kitchenId;

            clock_t _oldRefresh;

            bool _isInitialized;
    };

}

#endif /* !DISPLAYMANAGER_HPP_ */
