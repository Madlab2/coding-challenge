#include "Menu.hpp"

void Menu::run() {

    std::string input;

    while(true) {

        std::cout << "Enter a command below..." << std::endl;

        std::cin >> input;

        if (input == "exit") {
            std::cout << "exiting.." << std::endl;
            break;
        }

        else {
            std::cout << "[Echo] " << input << std::endl;
        }

    }

}

void Menu::sleep() {
    //TODO
    
}


void Menu::wakeUp() {
    //TODO
    
}