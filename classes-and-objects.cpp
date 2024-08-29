#include <iostream>

void Menu() {
    int book;
    std::cout << "Enter '1' to Add a Book, Enter '2' to Display a Book, Enter '3' to Search a Book, Enter '4' to Exit." << std::endl;
    std::cin >> book;

    switch (book) {
        case 1:
            std::cout << "Add a Book." << std::endl;
           
            break;
        case 2:
            std::cout << "Display a Book." << std::endl;
        
            break;
        case 3:
            std::cout << "Search a Book." << std::endl;
           
            break;
        case 4:
            std::cout << "Exiting..." << std::endl;
            exit(0);
            break;
        default:
            std::cout << "Invalid selection, please try again." << std::endl;
            break;
    }
}

int main() {
    Menu();
    return 0;
}
