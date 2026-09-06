#include <iostream>
#include <limits>
#include <string>
#include <stdexcept>
void printMenu();
int main(){
    std::string input;
    std::size_t pos;
    int choice;
    while(true){
        printMenu();
        std::getline(std::cin, input);
        try {
            choice = std::stoi(input, &pos);
        }
        catch (std::invalid_argument&) {
            std::cout << "Value's out of range try again!\n";
            continue;
        }
        catch (std::out_of_range&) {
            std::cout << "Value's out of range try again!\n";
            continue;
        }
        if(pos != input.length()){
            std::cout << "Value's out of range try again!\n";
            continue;
        }
        if(choice == 5){
            std::cout << "Program stopped !";
            break;
        }
        else if(choice < 1 || choice > 5){
            std::cout << "Value's out of range try again!\n";
            continue;
        }
    }

}
void printMenu(){
    std::cout << "--- To-Do List ---\n";
    std::cout << "1. Add task\n";
    std::cout << "2. List tasks\n";
    std::cout << "3. Mark task done\n";
    std::cout << "4. Remove task\n";
    std::cout << "5. Quit\n";
    std::cout << "Choose an option: ";
}