/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** KitchenInfo
*/

#include <KitchenInfo.hpp>
#include <unistd.h>

namespace Plazza {

    KitchenInfo::KitchenInfo(int id, Pipe *pipe, Pipe *masterPipe) {
        this->_id = id;
        this->_pipe = pipe;
        this->_masterPipe = masterPipe;

        this->_ordersProcessing = 0;
        this->_totalOrders = 0;
        this->_ordersCompleted = 0;

        this->isClosed = false;
    }

    void KitchenInfo::createKitchen(Settings settings) {
        int cpid = fork();

        if (cpid == 0) {
            Kitchen kitchen(this->_id, this->_pipe, this->_masterPipe, settings);
            return;
        }
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


    int KitchenInfo::getTotalOrders(void) const{
        return (this->_totalOrders);
    }

    void KitchenInfo::addTotalOrder(void) {
        this->_totalOrders += 1;
    }

    int KitchenInfo::getAwaitingOrders(void) const {
        return (this->_totalOrders - (this->_ordersCompleted + this->_ordersProcessing));
    }

    int KitchenInfo::getProcessingOrders(void) const {
        return (this->_ordersProcessing);
    }

    void KitchenInfo::addProcessingOrder(void) {
        this->_ordersProcessing += 1;
    }

    int KitchenInfo::getCompletedOrders(void) const {
        return (this->_ordersCompleted);
    }

    void KitchenInfo::addCompletedOrder(void) {
        this->_ordersProcessing -= 1;
        this->_ordersCompleted += 1;
    }

}
