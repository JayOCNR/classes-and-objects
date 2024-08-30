#include <iostream>
#include <string> 
#include <vector> // No fixed array size, used emplace.back and .empty
#include <iomanip> // setw

// Classes and Objects For Adding Books
class Book
{
private:
    std::string title;
    std::string author;
    int year;

public: // Constructor and Destructor
    Book(std::string t, std::string a, int y) : title(t), author(a), year(y)
    {
        std::cout << "Resource Book added successfully!" << std::endl;
    }
    ~Book()
    {
        std::cout << "Resource Book released!" << std::endl;
    }
    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    int getYear() const { return year; }
};

// Classes and Objects for the Book Data
class Library
{
private:
    std::vector<Book> books;

public:
    Library() = default;
    ~Library() = default;

    void AddBook()
    {
        std::string title, author;
        int year;

        std::cout << "Enter Book Title: ";
        std::cin.ignore();
        std::getline(std::cin, title);

        std::cout << "Enter Book Author: ";
        std::getline(std::cin, author);

        std::cout << "Enter Book Year: ";
        std::cin >> year;

        books.emplace_back(title, author, year);
        std::cout << "Book added successfully!" << std::endl;
    }

    void BooksLibrary() const
    {
        if (books.empty())
        {
            std::cout << "There are no books available in the library." << std::endl;
        }
        else
        {
            std::cout << "Book List: " << std::endl;
            std::cout << std::left << std::setw(30) << "Title"
                      << std::setw(25) << "Author" << "Year" << std::endl;
            for (const Book &book : books)
            {
                std::cout << std::left << std::setw(30) << book.getTitle()
                          << std::setw(25) << book.getAuthor()
                          << book.getYear() << std::endl;
            }
        }
    }

    void SearchBook() const
    {
        std::string searchTitle;
        std::cout << "Enter the title of the book to search: ";
        std::cin.ignore(); // Clear the input buffer
        std::getline(std::cin, searchTitle);

        bool found = false;
        for (const Book &book : books)
        {
            if (book.getTitle() == searchTitle)
            {
                std::cout << "Book found!" << std::endl;
                std::cout << "Title: " << book.getTitle() << std::endl;
                std::cout << "Author: " << book.getAuthor() << std::endl;
                std::cout << "Year: " << book.getYear() << std::endl;
                found = true;
                break;
            }
        }

        if (!found)
        {
            std::cout << "Book not found!" << std::endl;
        }
    }
};

void Menu(Library &lib)
{
    int bookchoice;
    while (true)
    {
        std::cout << "Enter '1' to Add a Book, Enter '2' to Display Books, Enter '3' to Search a Book, Enter '4' to Exit." << std::endl;
        std::cin >> bookchoice;

        switch (bookchoice)
        {
        case 1:
            lib.AddBook();
            break;
        case 2:
            lib.BooksLibrary();
            break;
        case 3:
            lib.SearchBook();
            break;
        case 4:
            std::cout << "Exited the program." << std::endl;
            return;
        default:
            std::cout << "Invalid selection, please try again." << std::endl;
            break;
        }
    }
}

int main()
{
    Library lib;
    Menu(lib);
    return 0;
}
