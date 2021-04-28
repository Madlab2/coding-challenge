#include "IntentMenu.hpp"


IntentMenu::IntentMenu() {

    setEstimator(std::make_unique<IntentEstimator>());
    
}

IntentMenu::IntentMenu(std::unique_ptr<Estimator> specialEstimator) {

    setEstimator(std::move(specialEstimator));

}

void IntentMenu::run() {

    std::string input;
    std::string intent;

    while(true) {

        std::cout << "Enter a command below or 'exit':" << std::endl;

        std::getline(std::cin, input);

        if (input == "exit") {
            std::cout << "exiting.." << std::endl;
            break;
        }

        else {
            intent = estimator_->findBestEstimate(input);
            std::cout << intent << std::endl;
        }

    }

}

void IntentMenu::setEstimator(std::unique_ptr<Estimator> specialEstimator) {
    
    estimator_ = std::move(specialEstimator);
}
