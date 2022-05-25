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

    OrderBuilder::OrderBuilder(std::string order, PizzaManager manager) {
        std::vector<std::string> infos = splitString(order, " ");

        if (infos.size() != 3)
            throw OrderBuilder::Error("Format: PizzaType PizzaSize Quantity");
        this->_manager = manager;
        this->_rawType = infos[0];
        this->_rawSize = infos[1];
        this->_rawQuantity = infos[2];
    }

    Order OrderBuilder::buildOrder() {
        Pizza pizza = this->_retrievePizza();
        pizza.setSize(this->_retrieveSize());
        int quantity = this->_retrieveQuantity();

        return (Order(pizza, quantity));
    }

    Pizza OrderBuilder::_retrievePizza() {
        if (this->_manager.getPizzas().count(this->_rawType) == 0)
            throw OrderBuilder::Error("Incorrect or Unknown pizza type.");
        return (this->_manager.getPizzas()[this->_rawType]);
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
        int quantity;

        if (stringStartsWith("x", this->_rawQuantity) == false)
            throw OrderBuilder::Error("Quantity should be defined by x[1..9][0..9]*.");

        quantity = std::atoi(this->_rawQuantity.substr(1).c_str());

        if (quantity <= 0)
            throw OrderBuilder::Error("Quantity should be greater than 0.");
        return (quantity);
    }

}
