/*
  Testfile for #HeyMErcedes Coding Challenge
  Author: Patrick Madlindl
  April 2021
*/

#include "gtest/gtest.h"

#include "IntentEstimator.hpp"
#include "Intents.hpp"
#include "IntentMenu.hpp"


//TODO: edge cases, strange symbols, "I'd like to have an interesting fact about the weather in Paris".


void createInputs(std::map<std::string, std::string> & inputs) {

  std::string wheather = "Intent: Get Weather";
  std::string cityWeather = "Intent: Get Weather City";
  std::string fact = "Intent: Get Fact";

  inputs = {
    {"What is the weather like today?", wheather},
    {"Tell me the weather!", wheather},
    {"How is the weather going to be today?", wheather},
    {"How is the weather today?", wheather},
    {"What is the weather like in Paris today?", cityWeather},
    {"Tell me the weather in Amsterdam.", cityWeather},
    {"How is the the weather in Amsterdam at the moment?", cityWeather},
    {"What's the weather like in Berlin?", cityWeather},
    {"Please tell me something factful.", fact},
    {"Tell an interesting fact!", fact},
    {"Please give me a fact on Mercedes-Benz.", fact},
    {"Tell me an interesting fact.", fact}
  };

}

//TODo
TEST (IntentsTests, checkDiscreteIntentToString) {


  //Intents intents;
  //EXPECT_EQ((std::string) Intents.DiscreteIntentToString.at(DiscreteIntents::GET_WEATHER), (std::string) "Intent: Get Weather");


}
//TODO
TEST (IntentsTests, checkTest2) {

  EXPECT_EQ(true, true);

}

TEST (EstimatorTests, testFindEstimate) {

  std::string input = "Tell me a fact";
  std::string expectedEstimate = "Intent: Get Fact";
  IntentEstimator testEstimator = IntentEstimator();

  std::map<std::string, std::string> testData;
  createInputs(testData);

  for (auto value : testData) {

    if(testEstimator.findBestEstimate(value.first)!= value.second) {
      std::cout << "[Value] " << value.first << ", " << value.second << std::endl;
    }
    EXPECT_EQ(testEstimator.findBestEstimate(value.first), value.second);

  }

}

//TODO
TEST (EstimatorTests, checkTest3) {

  EXPECT_EQ(true, true);

}

//TODO
TEST (HeyMercedesCodingChallengeTest, checkTest4) {

  EXPECT_EQ(true, true);

}

int main(int argc, char **argv) {

    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();

}

