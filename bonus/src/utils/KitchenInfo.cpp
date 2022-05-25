/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** KitchenInfo
*/

#include <KitchenInfo.hpp>
#include <Utils.hpp>
#include <unistd.h>
#include <iostream>
#include <algorithm>

namespace Plazza {

    KitchenInfo::KitchenInfo(int id, Pipe *pipe, Pipe *masterPipe) {
        this->_id = id;
        this->_pipe = pipe;
        this->_masterPipe = masterPipe;

        this->_ordersAwaiting = {};
        this->_ordersProcessing = {};
        this->_totalOrders = {};
        this->_ordersCompleted = {};
        this->_ingredients = {};

        this->isClosed = false;

        for (int i = 0; i < 5; i++)
            this->refillIngredients();
    }

    KitchenInfo::~KitchenInfo() {
        autoClear(&this->_ordersAwaiting);
        autoClear(&this->_ordersProcessing);
        autoClear(&this->_ordersCompleted);
        autoClear(&this->_totalOrders);
    }

    bool KitchenInfo::createKitchen(Settings settings) {
        int cpid = fork();

        if (cpid == 0) {
            Kitchen kitchen(this->_id, this->_pipe, this->_masterPipe, settings);
            return (true);
        }

        return (false);
    }

    int KitchenInfo::getId(void) {
        return (this->_id);
    }
            
    Pipe *KitchenInfo::getPipe(void) {
        return (this->_pipe);
    }

    Pipe *KitchenInfo::getMasterPipe(void) {
        return (this->_masterPipe);
    }

    std::string KitchenInfo::retrieveId() {
        return ("[" + std::to_string(this->_id) + "]");
    }


    std::list<Pizza *> KitchenInfo::getTotalOrders(void) const{
        return (this->_totalOrders);
    }

    void KitchenInfo::addTotalOrder(Pizza *pizza) {
        this->_totalOrders.push_back(pizza);
    }

    void KitchenInfo::addAwaitingOrder(Pizza *pizza) {
        this->_ordersAwaiting.push_back(pizza);
    }

    std::list<Pizza *> *KitchenInfo::getAwaitingOrders(void) {
        return (&(this->_ordersAwaiting));
    }

    std::list<Pizza *> *KitchenInfo::getProcessingOrders(void) {
        return (&(this->_ordersProcessing));
    }

    void KitchenInfo::addProcessingOrder(Pizza *pizza) {
        if (pizza == nullptr)
            return;

        Pizza *target = autoRemoveOrder(&(this->_ordersAwaiting), pizza);

        if (target == nullptr)
            this->_ordersProcessing.push_back(new Pizza(*pizza));
        else
            this->_ordersProcessing.push_back(target);
        this->_takeIngredients(pizza);
    }

    std::list<Pizza *> KitchenInfo::getCompletedOrders(void) const {
        return (this->_ordersCompleted);
    }

    void KitchenInfo::addCompletedOrder(Pizza *pizza) {
        Pizza *target = autoRemoveOrder(&(this->_ordersProcessing), pizza);

        if (target == nullptr)
            this->_ordersCompleted.push_back(new Pizza(*pizza));
        else
            this->_ordersCompleted.push_back(target);
    }

    void KitchenInfo::_takeIngredients(Pizza *pizza) {
        for (Ingredients ingredient : pizza->getIngredients()) {
            std::list<Ingredients> *available = &this->_ingredients;
            std::list<Ingredients>::iterator it = std::find(available->begin(), available->end(), ingredient);
            if (it != available->end())
                available->erase(it);
        }
    }

    void KitchenInfo::refillIngredients(void) {
        this->_ingredients.push_back(DOE);
        this->_ingredients.push_back(TOMATO);
        this->_ingredients.push_back(GRUYERE);
        this->_ingredients.push_back(EGGPLANT);
        this->_ingredients.push_back(HAM);
        this->_ingredients.push_back(MUSHROOMS);
        this->_ingredients.push_back(STEAK);
        this->_ingredients.push_back(GOAT_CHEESE);
        this->_ingredients.push_back(CHIEF_LOVE);
    }

    int KitchenInfo::getIngredientsQuantity(Ingredients ingredient) {
        int quantity = 0;

        for (Ingredients tmp : this->_ingredients)
            if (tmp == ingredient)
                quantity++;
        return (quantity);
    }

}
