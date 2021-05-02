/* 

#HeyMercedes Coding Challenge
Patrick Madlindl
April 2021

*/

#pragma once
#include <string>

#include "Intents.hpp"


//prototype of a simple Estimator (pure-virtual)
class Estimator {
    
    public:
        Estimator() {};
        virtual ~Estimator() {};

        //a method that gets an input string of natural language and tries to estimate its meaning
        virtual std::string findBestEstimate(std::string input) = 0;

    private:
};

//here polymorphism makes absolutely sense (in my eyes), as there are many strategies to implement a unit that
//categorises natural language.
//here, we implement ONE possible way of doing this: by associating the input to a category of intents
class IntentEstimator : public Estimator {

    public:
        IntentEstimator() {};
        ~IntentEstimator() {};

        //Rule of five
        //Intent Menu does not need to be copy-constructed/copy-assigned/move-constructed/move-assigend, so delete thes
        IntentEstimator(const IntentEstimator& other) = delete;
        IntentEstimator& operator=(const IntentEstimator& other) = delete;
        IntentEstimator(IntentEstimator&& other) = delete;
        IntentEstimator& operator=(IntentEstimator&& other) = delete;

        //the method we HAVE to implement
        virtual std::string findBestEstimate(std::string input) override;

    private:
        
        //contains the information (i.e. mappings of input -> intent category) that IntentEstimator uses
        Intents intents_;
};

