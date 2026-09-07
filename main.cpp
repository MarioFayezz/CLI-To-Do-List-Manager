#include <iostream>
#include <limits>
#include <string>
#include <stdexcept>
#include <vector>
void printMenu();
struct Task {
    std::string title;
    std::string description;
    int id;
    bool isDone = false;
};
class TodoList {
    private:
    std::vector<Task> tasks;
    int nextId = 1; // starts at 1, never reused even after task removal, to keep IDs stable
    public:
    void addTask(const std::string& title, const std::string& description) {
        tasks.push_back(Task {title, description, nextId, false});
        nextId++;
    }
    void listTasks() const {
        if(tasks.size() == 0) {
            std::cout << "Tasks List is Empty\n";
        }
        else {
            for(const auto& task : tasks){
                std::cout << "-----------\n";
                std::cout << "Task Id #" << task.id << '\n';
                std::cout << "Task Title: " << task.title << '\n';
                std::cout << "Task Description: " << task.description << '\n';
                task.isDone ? std::cout << "Status: Done\n" : std::cout << "Status: Not Done\n";
                std::cout << "-----------\n";
            }
        }
    }
};
int main() {
    TodoList List;
    std::string input;
    std::string listTitleInput;
    std::string listDescriptionInput;
    std::size_t pos;
    int choice;
    while(true) {
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
        if(pos != input.length()) {
            std::cout << "Value's out of range try again!\n";
            continue;
        }
        if(choice < 1 || choice > 5) {
            std::cout << "Value's out of range try again!\n";
            continue;
        }
        if(choice == 1) {
            std::cout << "Enter a title: ";
            std::getline(std::cin, listTitleInput);
            std::cout << '\n';
            std::cout << "Enter a description: ";
            std::getline(std::cin, listDescriptionInput);
            List.addTask(listTitleInput, listDescriptionInput);
            std::cout << '\n';
        }
        else if(choice == 2) {
            List.listTasks();
            continue;
        }
        else if(choice == 5) {
            std::cout << "Program stopped !\n";
            break;
        }
    }
}
void printMenu() {
    std::cout << "--- To-Do List ---\n";
    std::cout << "1. Add task\n";
    std::cout << "2. List tasks\n";
    std::cout << "3. Mark task done\n";
    std::cout << "4. Remove task\n";
    std::cout << "5. Quit\n";
    std::cout << "Choose an option: ";
}