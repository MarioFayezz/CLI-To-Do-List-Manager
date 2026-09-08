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
    bool markDone(int ID) {
        for(auto& task : tasks) {
            if(task.id == ID) {
                task.isDone = true;
                return true;
            }
        }
        return false;
    }
    bool removeTask(int ID) {
        for(std::size_t i = 0; i < tasks.size(); i++) {
            if(tasks.at(i).id == ID) {
                tasks.erase(tasks.begin() + i);
                return true;
            }
        }
        return false;
    }
};
int main() {
    TodoList List;
    std::string input;
    std::string listTitleInput;
    std::string listDescriptionInput;
    std::string taskID;
    std::size_t pos;
    std::size_t IDpos;
    int choice;
    int ID;
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
        // stoi stops at the first non-numeric character; if pos doesn't reach the
        // end of the string, there's leftover junk after the number (e.g. "3x", "4klkl")
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
        else if(choice == 3) {
            std::cout << "Enter The Id Of The Task: " ;
            std::getline(std::cin, taskID);
            try {
                ID = std::stoi(taskID, &IDpos);
            }
            catch (std::invalid_argument&) {
                std::cout << "Value's out of range!\n";
                continue;
            }
            catch (std::out_of_range&) {
                std::cout << "Value's out of range!\n";
                continue;
            }
            if(IDpos != taskID.length()){
                std::cout << "Value's out of range try again!\n";
                continue;
            }
            if(List.markDone(ID)) {
                std::cout << "Task marked done successfully!\n";
                continue;
            }
            else {
                std::cout << "Task Doesn't Exist!\n";
                continue;
            }
        }
        else if(choice == 4) {
            std::cout << "Enter The Task's id you want to remove: ";
            std::getline(std::cin, taskID);
            try {
                ID = std::stoi(taskID, &IDpos);
            }
            catch (std::invalid_argument&) {
                std::cout << "Value's out of range!\n";
                continue;
            }
            catch (std::out_of_range&) {
                std::cout << "Value's out of range!\n";
                continue;
            }
            if(IDpos != taskID.length()){
                std::cout << "Value's out of range try again!\n";
                continue;
            }
            if(List.removeTask(ID)) {
                std::cout << "Task Was Removed Successfully! \n";
                continue;
            }
            else {
                std::cout << "Task Doesn't Exist!\n";
                continue;
            }
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