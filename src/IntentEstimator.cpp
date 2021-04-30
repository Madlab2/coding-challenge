/* 

#HeyMercedes Coding Challenge
Patrick Madlindl
April 2021

*/

#include "IntentEstimator.hpp"


std::string IntentEstimator::findBestEstimate(std::string input) {

    std::string intentFraction;
    DiscreteIntents discreteIntent;
    std::string estimatedIntent;
    
    //casts input to lower case
    std::transform(input.begin(), input.end(), input.begin(),
    [](unsigned char c){ return std::tolower(c); });


    //Initial value, changes in case we find a correspondance
    estimatedIntent = intents_.DiscreteIntentMessage.at(DiscreteIntents::ELSE);

    for (auto key : intents_.intentMappings) {
        
        //check wether the input string contains an elemenent specified in the map of intents
        intentFraction = key.first;

        //save index where correspondence has been found
        //save Intent-kind as well
        //after looping trhrough the map, pick the smallest index

        //we choose this approach because of english scentence structure: Subject Verb Object.
        //Even more in spoken language, scentences are shorter and the main points are mentioned at the beginning.
        //TODO: add paper for this
        
        //check whether the intentFraction is contained in the user-input. 
        //If so, we can assign the input the corresponding (discrete) intent.
        if(isAinB(intentFraction, input)) {

            discreteIntent = key.second;

            //extract and save the output we want to show the user that corresponds to the discrete intent.
            estimatedIntent = intents_.DiscreteIntentMessage.at(discreteIntent);
        }
    }

    return estimatedIntent;
    
}

//helper function that checks whether a string A is contained in string B
bool IntentEstimator::isAinB(std::string A, std::string B) {

    if(B.find(A) == std::string::npos)
        return false;
    else
        return true;
}