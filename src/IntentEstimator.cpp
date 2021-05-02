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

    size_t pos = 0;

    //contains the discrete intents found in the input and the index where they were found
    std::map<std::size_t, DiscreteIntents> foundIntents;
    
    //casts input to lower case as we do not want make distinctions in that respect
    std::transform(input.begin(), input.end(), input.begin(),
    [](unsigned char c){ return std::tolower(c); });


    //iterate through all intentFractions and check whether they are contained in the input
    for (auto key : intents_.intentMappings) {
        
        //intentFraction is a string of words, e.g. " weather in " or " a fact "
        intentFraction = key.first;

        //check whether the intentFraction is contained in the user-input. 
        //if it is, pos will be a normal size_t, if not, it will be equal to string::npos
        pos = input.find(intentFraction);

        
        if(pos != std::string::npos && pos >= 0) {

            //The intent fraction was found in the input, so we save the discrete intent assigned to the intent fraction 
            //and the index of where it has been found
            std::pair<size_t, DiscreteIntents> newIntent(pos, key.second);

            foundIntents.insert(newIntent);
        }
    }

    //size will be >0 when at least one intent fraction was found in the input
    if(foundIntents.size() > 0) {

        //chose intent with first occurance in input (=> smallest key in map)
        discreteIntent = foundIntents.begin()->second;
        estimatedIntent = intents_.DiscreteIntentMessage.at(discreteIntent);

        //we choose this approach because of english scentence structure: Subject Verb Object.
        //Even more in spoken language, scentences are shorter and the main points are mentioned at the beginning.
        //TODO: add paper for this



    } else {
        
        //in case no matches were found --> express this by setting estimated intent to ELSE
        estimatedIntent = intents_.DiscreteIntentMessage.at(DiscreteIntents::ELSE);
    }

    return estimatedIntent;
    
}

        