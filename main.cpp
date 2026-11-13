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
    std::cout << "***** Welcome to cpp-toolkit *****" << std::endl;
    int ipi = readInt("Pick 1-5: ", 1, 5);
    return 0;
}