/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** StatusPrinter
*/

#ifndef STATUSPRINTER_HPP_
    #define STATUSPRINTER_HPP_
    #include "Pizzeria.hpp"

namespace Plazza {

    class StatusPrinter {
        public:
            StatusPrinter(Pizzeria *pizzeria);
            ~StatusPrinter();

            void print(void) const;

        private:
            Pizzeria *_pizzeria = nullptr;

            void _printSeparator(void) const;
            void _printMainInfos(void) const;

            int _countKitchenClosed(void) const;

            void _printKitchen(int id) const;
    };

}

#endif /* !STATUSPRINTER_HPP_ */
