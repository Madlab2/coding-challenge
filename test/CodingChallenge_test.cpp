/*
  Testfile for #HeyMErcedes Coding Challenge
  Author: Patrick Madlindl
  April 2021
*/

#include "gtest/gtest.h"

#include "Menu.hpp"

TEST (HeyMercedesCodingChallengeTestbench, checkTest) {

  EXPECT_EQ(true, true);

}

int main(int argc, char **argv) {

    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();

}

