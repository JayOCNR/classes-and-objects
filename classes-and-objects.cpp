#include <iostream>
#include <string>

class Book
{
private:
    std::string title;
    std::string author;
    int year;

public: //Constructor and Destructor
    Book(std::string t, std::string a, std::string y) : title(t), author (a), year(y){
        std::cout << "Resource Book added successfully!" << std::endl;
    }
    ~Book(){
        std::cout << "Resource Book released!" << std::endl;
    }
}

void
Menu()
{
    int book;
    std::cout << "Enter '1' to Add a Book, Enter '2' to Display a Book, Enter '3' to Search a Book, Enter '4' to Exit." << std::endl;
    std::cin >> book;

    switch (book)
    {
    case 1:
        std::string title, author;
        int year;
        std::cout << "Add a Book" << std::endl;
        std::cout << "Enter book title: ";
        std::cin.ignore();
        std::getline(std::cin, title);

        std::cout << "Enter author ";
        std::getline(std::cin, author);

        std::cout << "Enter year:";
        std::cin >> year;

        std::cout << "Book added successfully!" << std::endl;

        break;
    case 2:
        std::cout << "Display a Book" << std::endl;

        break;
    case 3:
        std::cout << "Search a Book" << std::endl;

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

int main()
{
    ResourceManager rm(10);
    Menu();
    return 0;
}
