/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** OrderBuilder
*/

#include <iostream>
#include <vector>
#include <Utils.hpp>
#include <OrderBuilder.hpp>

namespace Plazza {

    OrderBuilder::OrderBuilder(std::string order) {
        std::vector<std::string> infos = splitString(order, " ");

        if (infos.size() != 3)
            throw OrderBuilder::Error("Format: PizzaType PizzaSize Quantity");
        this->_rawType = infos[0];
        this->_rawSize = infos[1];
        this->_rawQuantity = infos[2];
    }

    Order OrderBuilder::buildOrder() {
        PizzaType type = this->_retrieveType();
        PizzaSize size = this->_retrieveSize();
        int quantity = this->_retrieveQuantity();

        return (Order(type, size, quantity));
    }

    PizzaType OrderBuilder::_retrieveType() {
        if (this->_rawType == "regina")
            return (PizzaType::Regina);
        if (this->_rawType == "margarita")
            return (PizzaType::Margarita);
        if (this->_rawType == "americana")
            return (PizzaType::Americana);
        if (this->_rawType == "fantasia")
            return (PizzaType::Fantasia);
        throw OrderBuilder::Error("Incorrect pizza type.");
    }

    PizzaSize OrderBuilder::_retrieveSize() {
        if (this->_rawSize == "S")
            return (PizzaSize::S);
        if (this->_rawSize == "M")
            return (PizzaSize::M);
        if (this->_rawSize == "L")
            return (PizzaSize::L);
        if (this->_rawSize == "XL")
            return (PizzaSize::XL);
        if (this->_rawSize == "XXL")
            return (PizzaSize::XXL);
        throw OrderBuilder::Error("Incorrect pizza size.");
        return (PizzaSize::S);
    }

    int OrderBuilder::_retrieveQuantity() {
        char *endPtr;
        int quantity;

        if (stringStartsWith("x", this->_rawQuantity) == false)
            throw OrderBuilder::Error("Quantity should be defined by x[1..9][0..9]*.");
        char const *tmpQuantity = this->_rawQuantity.substr(1).c_str();

        quantity = std::strtol(tmpQuantity, &endPtr, 10);
        if (tmpQuantity == endPtr)
            throw OrderBuilder::Error("Quantity is not a valid integer.");
        if (quantity <= 0)
            throw OrderBuilder::Error("Quantity should be greater than 0.");
        return (quantity);
    }

}
