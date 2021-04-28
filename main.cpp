/* 

#HeyMercedes Coding Challenge
Patrick Madlindl
April 2021

*/

#include <memory>

#include "IntentMenu.hpp"


int main() {

    std::unique_ptr<Menu> myMenu = std::make_unique<IntentMenu>();
    myMenu->run();

    return 0;
}