/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-paul.comte
** File description:
** Kitchen
*/

#ifndef KITCHEN_HPP_
    #define KITCHEN_HPP_

class Kitchen {
    public:
        Kitchen();
        ~Kitchen();

    private:
        void _updateOrders(); // It happens in another thread
};

#endif /* !KITCHEN_HPP_ */
