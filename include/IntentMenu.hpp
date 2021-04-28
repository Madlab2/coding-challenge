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

        std::unique_ptr<Estimator> estimator_;
    
};
