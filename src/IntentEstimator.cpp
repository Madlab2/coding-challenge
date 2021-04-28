#include "IntentEstimator.hpp"

//Estimator::~Estimator() {}

std::string IntentEstimator::findBestEstimate(std::string input) {

    std::string intentFraction;
    DiscreteIntents discreteIntent;
    std::string estimatedIntent;
    
    //input to lower case
    std::transform(input.begin(), input.end(), input.begin(),
    [](unsigned char c){ return std::tolower(c); });


    //Initial value, changes in case we find a correspondance
    estimatedIntent = intents_.DiscreteIntentToString.at(DiscreteIntents::ELSE);

    for (auto key : intents_.intentMappings) {
        
        //check wether the input string contains an elemenent specified in the map of intents
        intentFraction = key.first;

        //save index where correspondence has been found
        //save Intent-kind as well
        //after looping trhrough the map, pick the smallest index

        //we choose this approach because of english scentence structure: Subject Verb Object.
        //
        //especially in spoken language, scentences are shorter and the main points are mentioned at the beginning.
        //TODO: add paper for this
        
        if(isAinB(intentFraction, input)) {

            discreteIntent = key.second;

            estimatedIntent = intents_.DiscreteIntentToString.at(discreteIntent);
        }
    }

    return estimatedIntent;
    
}

bool IntentEstimator::isAinB(std::string A, std::string B) {

    if(B.find(A) == std::string::npos)
        return false;
    else
        return true;
}