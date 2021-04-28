#pragma once

#include <string>
#include <map>
#include <algorithm>
#include <vector>



enum class DiscreteIntents {
    GET_WEATHER,
    GET_WEATHER_CITY,
    GET_FACT,
    ELSE,
};

struct Intents {

        //A mapping from input strings to Intents
        //Key is a string, eg. a variation of "... the weather like in Paris today?", and the value is the clear intent
        std::map<std::string, DiscreteIntents> intentMappings {
            {"what is the weather like in paris today?", DiscreteIntents::GET_WEATHER_CITY},
            {" weather like today in ", DiscreteIntents::GET_WEATHER_CITY},
            {" weather today in ", DiscreteIntents::GET_WEATHER_CITY},
            {" weather like in ", DiscreteIntents::GET_WEATHER_CITY},
            {" forecast in ", DiscreteIntents::GET_WEATHER_CITY},
            {" forecast for ", DiscreteIntents::GET_WEATHER_CITY},
            {" weather in ", DiscreteIntents::GET_WEATHER_CITY},
            

            {"what is the weather like today?", DiscreteIntents::GET_WEATHER},
            {" weather like today?", DiscreteIntents::GET_WEATHER},
            {" weather today?", DiscreteIntents::GET_WEATHER},
            {" weather going to be?", DiscreteIntents::GET_WEATHER},
            {" weather going to be today?", DiscreteIntents::GET_WEATHER},
            {" weather?", DiscreteIntents::GET_WEATHER},
            {" weather!", DiscreteIntents::GET_WEATHER},
            {" weather.", DiscreteIntents::GET_WEATHER},
            
            {"tell me an interesting fact.", DiscreteIntents::GET_FACT},
            {" an interesting fact", DiscreteIntents::GET_FACT},
            {" a fact", DiscreteIntents::GET_FACT},
            {" something factful", DiscreteIntents::GET_FACT},
        };

        //Maps the enum class elements to strings
        std::map<DiscreteIntents, std::string> DiscreteIntentToString {
            {DiscreteIntents::GET_WEATHER, "Intent: Get Weather"},
            {DiscreteIntents::GET_WEATHER_CITY, "Intent: Get Weather City"},
            {DiscreteIntents::GET_FACT, "Intent: Get Fact"},
            {DiscreteIntents::ELSE, "No known intent."}
        };


};