/* 

#HeyMercedes Coding Challenge
Patrick Madlindl
April 2021

*/

#pragma once
#include <string>

#include "Intents.hpp"


class Estimator {
    
    public:
        Estimator() {};
        virtual ~Estimator() {};

        virtual std::string findBestEstimate(std::string input) = 0;

    private:
};


class IntentEstimator : public Estimator {

    public:
        IntentEstimator() {};
        ~IntentEstimator() {};

        virtual std::string findBestEstimate(std::string input) override;

    private:
        
        Intents intents_;

        bool isAinB(std::string A, std::string B);
};

