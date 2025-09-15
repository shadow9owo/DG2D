#include <iostream>
#include <string>
#include "std/STD.hpp"

int main() {
    while (true)
    {
        std::string command;
        std::cout << "Enter command (set/get/exit): ";
        std::cin >> command;

        if (command == "set") {
            std::string key, value;
            std::cout << "Enter key: ";
            std::cin >> key;
            std::cout << "Enter value: ";
            std::cin >> value;

            if (DG2D::SmartTableDatabase::SetValue(key, value)) {
                std::cout << "Value set successfully." << std::endl;
            } else {
                std::cout << "Failed to set value." << std::endl;
            }
        } else if (command == "get") {
            std::string key;
            std::cout << "Enter key: ";
            std::cin >> key;

            std::string value = DG2D::SmartTableDatabase::LoadValue(key);
            if (!value.empty()) {
                std::cout << "Value: " << value << std::endl;
            } else {
                std::cout << "Key not found." << std::endl;
            }
        } else if (command == "exit") {
            break;
        } else {
            std::cout << "Unknown command." << std::endl;
        }
    }
    
    return 0;
}