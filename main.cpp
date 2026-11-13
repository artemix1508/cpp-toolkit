#include <iostream>
#include <limits>
#include <string>

int readInt(std::string prompt, int min, int max){
    int input;
    while(true){
        std::cout << prompt;
        std::cin >> input;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if(input < min || input > max){
            std::cout << "Enter an integer in the valid range" << std::endl;
        }
        else{
            return input;
        }
    }
}

int main(){
    std::cout << "Welcome to cpp-toolkit." << std::endl;
    std::cout << "Options:" << std::endl;
    std::cout << "[1]. Unit Converter" << std::endl;
    std::cout << "[6]. Exit" << std::endl;
    int option;
    do{
        option = readInt("Enter a number corresponding to a function you want to use: ", 1, 6);
        switch(option){
            case 1:
                break;
            case 6:
                return 0;
        }
    }while(option != 6);
    return 0;
}