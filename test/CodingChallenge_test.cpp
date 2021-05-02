/*
  Testfile for #HeyMErcedes Coding Challenge
  Author: Patrick Madlindl
  April 2021
*/

#include "gtest/gtest.h"

#include "IntentEstimator.hpp"
#include "Intents.hpp"
#include "IntentMenu.hpp"



//Also contains edge cases, strange symbols, and some tricky stuff such as "I'd like to have an interesting fact about the weather in Paris".
void createInputs(std::map<std::string, std::string> & inputs) {

  std::string wheather = "Intent: Get Weather";
  std::string cityWeather = "Intent: Get Weather City";
  std::string fact = "Intent: Get Fact";
  std::string other = "No known intent.";

  //some simple semantic variations of inputs with intents
  inputs = {
    {"What is the weather like today?", wheather},
    {"Tell me the weather!", wheather},
    {"How is the weather going to be today?", wheather},
    {"How is the weather today?", wheather},
    {"What is the weather like in Paris today?", cityWeather},
    {"Tell me the weather in Amsterdam.", cityWeather},
    {"How is the the weather in Amsterdam at the moment?", cityWeather},
    {"What's the weather like in Berlin?", cityWeather},
    {"The weather forecast for Berlin please.", cityWeather},
    {"Please tell me something factful.", fact},
    {"Tell an interesting fact!", fact},
    {"Please give me a fact on Mercedes-Benz.", fact},
    {"Tell me an interesting fact.", fact},
    {"I'd like to have an interesting fact about the weather in Paris", fact},
    {"Tell me a fact about the average weather forecast in European cities.", fact},

    //and now some silly border/edge cases. To be greatly enhanced if we wanted to be on the safe side.
    
    {"", other},  //an empty line(no input)
    {"@@@{wef}", other}, //some strange signs...
    {"___main___:", other},
    {"ÄöÜü€^°°~~", other},
    {"sudo shutdown", other},  //just do nothing...

  };

}

//checks that the mapping from enum class DiscreteIntents to the putput strings is correct
TEST (IntentsTests, checkDiscreteIntentToString) {

  Intents intents;
  EXPECT_EQ(intents.DiscreteIntentMessage.at(DiscreteIntents::GET_WEATHER), "Intent: Get Weather");
  EXPECT_EQ(intents.DiscreteIntentMessage.at(DiscreteIntents::GET_WEATHER_CITY), "Intent: Get Weather City");
  EXPECT_EQ(intents.DiscreteIntentMessage.at(DiscreteIntents::GET_FACT), "Intent: Get Fact");
  EXPECT_EQ(intents.DiscreteIntentMessage.at(DiscreteIntents::ELSE), "No known intent.");

}

//Tests the IntentEstimator, using the inputs created in createInputs()
TEST (EstimatorTests, testFindEstimate) {

  auto testEstimator = std::make_unique<IntentEstimator>();

  std::map<std::string, std::string> testData;
  createInputs(testData);

  for (auto value : testData) {

    EXPECT_EQ(testEstimator->findBestEstimate(value.first), value.second);

  }

}


//Some kind of integration test (from user input to output message) would be great
//Problem: without changing signature of intentMenu.run() function (optionally passing it intput string)
//this will be hard
//As Menu etc. is still very simple, I leave this out for the moment.
/*
TEST (HeyMercedesCodingChallengeTest, integrationTest) {

  std::unique_ptr<IntentMenu> menu = std::make_unique<IntentMenu>(std::move(dummyEstimator));

  //...

}
*/

int main(int argc, char **argv) {

    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();

}

