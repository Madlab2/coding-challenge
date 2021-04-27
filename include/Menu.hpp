#pragma once

#include <iostream>
#include <string>

class Menu {

    private:
        //to make wait for std::cin() more efficient -> mutex/lock, .notify_one()
        void sleep();

        void wakeUp();

    public:
        Menu() {};
        ~Menu() {};

        void run();
};
