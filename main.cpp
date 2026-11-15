#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <ctime>

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
int readDouble(std::string prompt, double min, double max){
    double input;
    while(true){
        std::cout << prompt;
        std::cin >> input;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if(input < min || input > max){
            std::cout << "Enter a double in the valid range" << std::endl;
        }
        else{
            return input;
        }
    }
}

void numberGuessingGame(int diff){
    srand(time(0));
    int tries;
    int used_tries = 0;
    int random_num;
    int guess = 0;
    bool won;
    if(diff == 1){
        tries = 20;
        random_num = rand() % 100 + 1;
    }
    else if(diff == 2){
        tries = 15;
        random_num = rand() % 200 + 1;
    }
    else{
        tries = 10;
        random_num = rand() % 300 + 1;
    }
    while(guess != random_num){
        switch(diff){
            case 1:
                guess = readInt("Enter a number between 1-100: ", 1, 100);
                break;
            case 2:
                guess = readInt("Enter a number between 1-200: ", 1, 200);
                break;
            case 3:
                guess = readInt("Enter a number between 1-300: ", 1, 300);
                break;
        }
        used_tries++;
        if(guess == random_num){
            won = true;
            break;
        }
        if(used_tries >= tries){
            won = false;
            break;
        }
        if(guess > random_num){
            std::cout << "Too high! Try again.\n";
        }
        else if(guess < random_num){
            std::cout << "Too low! Try again.\n";
        }
    }
    won ? std::cout << "You won in " << used_tries << " tries. There was only " << tries - used_tries << " left! Try again? (1. Yes, 2. No): " : std::cout << "You ran out of tries! (" << used_tries << '/' << tries << ") Try again? (1. Yes, 2. No): ";
    int playAgain = readInt("", 1, 2);
    switch(playAgain){
        case 1: {
            int difficulty = readInt("Enter the difficulty of the game, it will change the number ranges and the number of tries: ", 1, 3);
            numberGuessingGame(difficulty);
        }
        case 2:
            return;
    }
}

double kmToMiles(double km) {
    const double KM_PER_MILE = 0.621371;
    return km * KM_PER_MILE;
}
double milesToKm(double miles){
    const double MILE_PER_KM = 0.621371;
    return miles / MILE_PER_KM;
}
double kgToLb(double kg){
    const double KG_PER_LB = 2.20462262185;
    return kg * KG_PER_LB;
}
double lbToKg(double lb){
    const double LB_PER_KG = 2.20462262185;
    return lb / LB_PER_KG;
}
double cToF(double C){
    return (C * 9/5) + 32;
}
double fToC(double F){
    return (F - 32) * 5/9;
}


int main(){
    int option;
    do{ 
        std::cout << "***** Welcome to cpp-toolkit *****\n";
        std::cout << "Options:\n";
        std::cout << "[1]. Unit Converter\n";
        std::cout << "[2]. Number guessing game\n";
        std::cout << "[6]. Exit\n";
        option = readInt("Enter a number corresponding to a function you want to use: ", 1, 6);
        switch(option){
            case 1: {
                double converted_value = 0;
                double value_to_convert = 0;
                std::cout << "[1]. Km -> Miles\n[2]. Miles -> Km\n[3]. Kg -> Lb\n[4]. Lb -> Kg\n[5]. °C -> °F\n[6]. °F -> °C\n";
                int conv_option = readInt("What conversion would you like to perform?: ", 1, 6);
                switch (conv_option) {
                    case 1:
                        value_to_convert = readDouble("Enter a value to convert: ", 0, 99999999999);
                        converted_value = kmToMiles(value_to_convert);
                        std::cout << std::fixed << std::setprecision(2) << value_to_convert << "km is " << converted_value << " in miles.\n";
                        break;
                    case 2:
                        value_to_convert = readDouble("Enter a value to convert: ", 0, 99999999999);
                        converted_value = milesToKm(value_to_convert);
                        std::cout << std::fixed << std::setprecision(2) << " miles is " << converted_value << " in km.\n";
                        break;
                    case 3:
                        value_to_convert = readDouble("Enter a value to convert: ", 0, 99999999999);
                        converted_value = kgToLb(value_to_convert);
                        std::cout << std::fixed << std::setprecision(2) << value_to_convert << " kg is " << converted_value << " lb.\n";
                        break;
                    case 4:
                        value_to_convert = readDouble("Enter a value to convert: ", 0, 99999999999);
                        converted_value = lbToKg(value_to_convert);
                        std::cout << std::fixed << std::setprecision(2) << value_to_convert << " lb is " << converted_value << " kg.\n";
                        break;
                    case 5:
                        value_to_convert = readDouble("Enter a value to convert: ", -273.15, 1000);
                        converted_value = cToF(value_to_convert);
                        std::cout << std::fixed << std::setprecision(2) << value_to_convert << " °C is " << converted_value << " °F.\n";
                        break;
                    case 6:
                        value_to_convert = readDouble("Enter a value to convert: ", -273.15, 1000);
                        converted_value = fToC(value_to_convert);
                        std::cout << std::fixed << std::setprecision(2) << value_to_convert << " °F is " << converted_value << " °C.\n";
                        break;
                }
                break;
            }
            case 2: {
                int difficulty = readInt("Enter the difficulty of the game, it will change the number ranges and the number of tries: ", 1, 3);
                numberGuessingGame(difficulty);
                break;
            }
        }
    }while(option != 6);
    std::cout << "Goodbye!" << '\n';
    return 0;
}