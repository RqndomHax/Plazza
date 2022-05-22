/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** Pizza
*/

#ifndef PIZZA_HPP_
    #define PIZZA_HPP_
    #include <ostream>

namespace Plazza {

    enum PizzaType {
        Regina = 1,
        Margarita = 2,
        Americana = 4,
        Fantasia = 8
    };

    enum PizzaSize {
        S = 1,
        M = 2,
        L = 4,
        XL = 8,
        XXL = 16
    };

    class Pizza {
        
        public:

            Pizza(PizzaType type = Margarita, PizzaSize size = S);

            PizzaType getType(void) const;
            PizzaSize getSize(void) const;

            std::string display(void) const;

        private:
            PizzaType _type;
            PizzaSize _size;
    };

}

#endif /* !PIZZA_HPP_ */
