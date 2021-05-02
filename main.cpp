/* 

#HeyMercedes Coding Challenge
Patrick Madlindl
April 2021

*/

#include <memory>   //for smart ptrs

#include "IntentMenu.hpp"


int main() {

    //create an IntentMenu (that satisfies the requirements)...
    std::unique_ptr<Menu> myMenu = std::make_unique<IntentMenu>();

    //start the Menu by calling the run() function
    myMenu->run();

    return 0;
}