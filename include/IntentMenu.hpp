/* 

#HeyMercedes Coding Challenge
Patrick Madlindl
April 2021

*/

#pragma once

#include <iostream>
#include <string>
#include <memory>

#include "IntentEstimator.hpp"

//prototype of a simple Menu (pure-virtual)
class Menu {

    public:
        Menu() {};
        virtual ~Menu() {};

        //generally, every Menu should have a run() method that starts the actual menu
        virtual void run() = 0;
        
    private:
};

//it is discussable whether polymorphism will ever be advantageous in this very context. 
//It could also turn out to be better not to use inheritance for different Menu types, 
//as polymorphism could give useless and unjustified contraints.
//However, for consistency and demonstrational purposes I stick to inheritance here.
class IntentMenu : public Menu {

    public:
        //Default ctor will create an IntentEstimator as estimator_
        IntentMenu();

        //...can also be constructed with a provided Estimator
        IntentMenu(std::unique_ptr<Estimator> specialEstimator);

        //nothing to do here. We rely on the smart ptrs to destruct themselves after going out of scope
        ~IntentMenu() {};

        //Rule of five
        //Intent Menu does not need to be copy-constructed/copy-assigned/move-constructed/move-assigend, so delete these
        IntentMenu(const IntentMenu& other) = delete;
        IntentMenu& operator=(const IntentMenu& other) = delete;
        IntentMenu(IntentMenu&& other) = delete;
        IntentMenu& operator=(IntentMenu&& other) = delete;


        //the method we HAVE to implement
        virtual void run() override;

        //Set a Strategy on how to determine inputs for the menu (--> Strategy Design Pattern)
        void setEstimator(std::unique_ptr<Estimator> specialEstimator);

    private:

        //IntentMenu holds an Estimator (IntentEstimator by default) which is used for interpreting inputs 
        //(estimating which category the input most likely belongs to)
        std::unique_ptr<Estimator> estimator_;
    
};
