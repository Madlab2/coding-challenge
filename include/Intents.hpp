/* 

#HeyMercedes Coding Challenge
Patrick Madlindl
April 2021

*/

#pragma once

#include <string>
#include <map>
#include <algorithm>    //for std::transform



//The intent categories (also called "discrete intents") for this specific problem
enum class DiscreteIntents {
    GET_WEATHER,
    GET_WEATHER_CITY,
    GET_FACT,
    ELSE,   //if none of the above can be assigned
};

//holds data on intents and input -> intent mappings
struct Intents {

        //DEFINITION: An intent fraction is a tuple of words and optionally punctuation signs
        //that can be assigend to an discrete intent with high probability.
        //Thus, an input will very likely be of the discrete intent of an intent fraction it contains.



        //A mapping from intent fractions to Discrete Intents
        //Key is a string, eg. a variation/fraction of "... the weather like in Paris today?", and the value is the discrete intent
        std::map<std::string, DiscreteIntents> intentMappings {
            
            //*************************************************************************
            //Note that some of these fractions are included in others. 
            //At this stage of implementation, this does seem superficial.

            //However, a sensible next step would be to introduce some rating for 
            //which intent will be the likeliest based on the number of intent-fractions
            //and the specificity of each intent-fraction appearing in the input
            //(how "exact" or "general" is each and every intent-fraction).

            //Effectively, this approach could be made ever finer until intent-fractions 
            //consist of single words or very short word tuples only.
            
            //Another approach would be to use and train (difficult with such a narrow problem)
            //a Natural Language Processing (NLP) Package, such as MITIE (some kind of overkill though)

            //**************************************************************************

            //intent-fractions for Get Weather City
            {"what is the weather like in paris today?", DiscreteIntents::GET_WEATHER_CITY},
            {" weather like today in ", DiscreteIntents::GET_WEATHER_CITY},
            {" weather today in ", DiscreteIntents::GET_WEATHER_CITY},
            {" weather like in ", DiscreteIntents::GET_WEATHER_CITY},
            {" forecast in ", DiscreteIntents::GET_WEATHER_CITY},
            {" forecast for ", DiscreteIntents::GET_WEATHER_CITY},
            {" weather in ", DiscreteIntents::GET_WEATHER_CITY},

            //intent-fractions for Get Weather
            {"what is the weather like today?", DiscreteIntents::GET_WEATHER},
            {" weather like today?", DiscreteIntents::GET_WEATHER},
            {" weather today?", DiscreteIntents::GET_WEATHER},
            {" weather going to be?", DiscreteIntents::GET_WEATHER},
            {" weather going to be today?", DiscreteIntents::GET_WEATHER},
            {" forecast?", DiscreteIntents::GET_WEATHER},
            {" forecast!", DiscreteIntents::GET_WEATHER},
            {" forecast.", DiscreteIntents::GET_WEATHER},
            {" weather?", DiscreteIntents::GET_WEATHER},
            {" weather!", DiscreteIntents::GET_WEATHER},
            {" weather.", DiscreteIntents::GET_WEATHER},
            
            //intent-fractions for Get Fact
            {"tell me an interesting fact.", DiscreteIntents::GET_FACT},
            {" an interesting fact", DiscreteIntents::GET_FACT},
            {" a fact", DiscreteIntents::GET_FACT},
            {" something factful", DiscreteIntents::GET_FACT},
        };

        //Maps the enum class elements to actual strings the we use in the output
        std::map<DiscreteIntents, std::string> DiscreteIntentMessage {
            {DiscreteIntents::GET_WEATHER, "Intent: Get Weather"},
            {DiscreteIntents::GET_WEATHER_CITY, "Intent: Get Weather City"},
            {DiscreteIntents::GET_FACT, "Intent: Get Fact"},
            {DiscreteIntents::ELSE, "No known intent."}
        };


};