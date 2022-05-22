/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** Pizza
*/

#ifndef PIZZA_HPP_
    #define PIZZA_HPP_
    #include <vector>
    #include <string>

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

    enum Ingredients {
        DOE,
        TOMATO,
        GRUYERE,
        EGGPLANT,
        HAM,
        MUSHROOMS,
        STEAK,
        GOAT_CHEESE,
        CHIEF_LOVE
    };

    class Pizza {
        
        public:

            Pizza(PizzaType type = Margarita, std::vector<Ingredients> ingredients = {}, PizzaSize size = S);

            PizzaType getType(void) const;

            std::vector<Ingredients> getIngredients(void) const;

            PizzaSize getSize(void) const;

            void setSize(PizzaSize size);

            std::string pack(void) const;

        private:
            PizzaType _type;
            std::vector<Ingredients> _ingredients;
            PizzaSize _size;
    };

}

#endif /* !PIZZA_HPP_ */
