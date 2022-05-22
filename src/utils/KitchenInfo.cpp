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

        this->_busyCooks = 0;
        this->_ordersProcessing = 0;
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

}
