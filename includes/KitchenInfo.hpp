/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** KitchenInfo
*/

#ifndef KITCHENINFO_HPP_
    #define KITCHENINFO_HPP_
    #include "Kitchen.hpp"

namespace Plazza {

    class KitchenInfo {
        public:
            KitchenInfo(int id, Pipe *pipe, Pipe *masterPipe);

            void createKitchen(void);

            int getId(void);
            
            Pipe *getPipe(void);

            Pipe *getMasterPipe(void);

        private:
            int _id;
            Pipe *_pipe;
            Pipe *_masterPipe;
    };

}

#endif /* !KITCHENINFO_HPP_ */
