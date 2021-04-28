#pragma once

#include <iostream>
#include <string>
#include <memory>

#include "IntentEstimator.hpp"

class Menu {

    public:
        Menu() {};
        virtual ~Menu() {};

        virtual void run() = 0;
        
    private:
};

class IntentMenu : public Menu {

    public:
        IntentMenu();
        IntentMenu(std::unique_ptr<Estimator> specialEstimator);

        ~IntentMenu() {};

        virtual void run() override;
        void setEstimator(std::unique_ptr<Estimator> specialEstimator);

    private:
        //to make wait for std::cin() more efficient -> mutex/lock, .notify_one()
        void sleep();

        void wakeUp();

        std::unique_ptr<Estimator> estimator_;
    
};
