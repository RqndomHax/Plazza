/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** OrderBuilder
*/

#ifndef ORDERBUILDER_HPP_
    #define ORDERBUILDER_HPP_
    #include "Order.hpp"

namespace Plazza {

    class OrderBuilder {
        public:
            OrderBuilder(std::string order);

            Order buildOrder();

            class Error : public std::exception {
                public:

                    Error(std::string message) : _message(message) {}

                    char const *what() const noexcept override {
                        return (this->_message).c_str();
                    }

                private:
                    std::string const _message;
            };


        private:
            std::string _rawType;
            std::string _rawSize;
            std::string _rawQuantity;

            PizzaType _retrieveType();
            PizzaSize _retrieveSize();
            int _retrieveQuantity();
    };

}

#endif /* !ORDERBUILDER_HPP_ */
