#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

struct Task {
    std::string description;
    bool completed;

    Task(const std::string& desc) : description(desc), completed(false) {}
};

class TodoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& description) {
        tasks.push_back(Task(description));
        std::cout << "Task added: " << description << std::endl;
    }

    void viewTasks() const {
        std::cout << "Task List:" << std::endl;
        std::cout << std::setw(5) << "ID" << std::setw(15) << "Description" << std::setw(15) << "Status" << std::endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << std::setw(5) << i + 1 << std::setw(15) << tasks[i].description << std::setw(15)
                      << (tasks[i].completed ? "Completed" : "Pending") << std::endl;
        }
    }

    void markCompleted(size_t taskId) {
        if (taskId > 0 && taskId <= tasks.size()) {
            tasks[taskId - 1].completed = true;
            std::cout << "Task marked as completed: " << tasks[taskId - 1].description << std::endl;
        } else {
            std::cout << "Invalid task ID." << std::endl;
        }
    }

    void removeTask(size_t taskId) {
        if (taskId > 0 && taskId <= tasks.size()) {
            std::cout << "Task removed: " << tasks[taskId - 1].description << std::endl;
            tasks.erase(tasks.begin() + taskId - 1);
        } else {
            std::cout << "Invalid task ID." << std::endl;
        }
    }
};

int main() {
    TodoList todoList;
    int choice;
    std::string taskDescription;
    size_t taskId;

    do {
        std::cout << "\nTodo List Manager" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. View Tasks" << std::endl;
        std::cout << "3. Mark Task as Completed" << std::endl;
        std::cout << "4. Remove Task" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter task description: ";
                std::cin.ignore(); 
                std::getline(std::cin, taskDescription);
                todoList.addTask(taskDescription);
                break;
            case 2:
                todoList.viewTasks();
                break;
            case 3:
                std::cout << "Enter the ID of the task to mark as completed: ";
                std::cin >> taskId;
                todoList.markCompleted(taskId);
                break;
            case 4:
                std::cout << "Enter the ID of the task to remove: ";
                std::cin >> taskId;
                todoList.removeTask(taskId);
                break;
            case 5:
                std::cout << "Exiting the Todo List Manager." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please enter a valid option." << std::endl;
        }
    } while (choice != 5);

    return 0;
}
