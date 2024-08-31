#include <iostream>
#include <string>
#include <vector>  // No fixed array size, used emplace.back and .empty
#include <iomanip> // setw
#include <cctype>  // Auto Upper case the lower case for searching

// Classes and Objects For Adding Books
class Book
{
private:
    std::string title;
    std::string author;
    int year;

public: // Constructor and Getter
    Book(std::string t, std::string a, int y) : title(t), author(a), year(y)
    {
        std::cout << "Resource Book added successfully!" << std::endl;
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

    void ConvertUpper(std::string &title) const
    {
        for (int i = 0; i < title.length(); i++)
        {
            title[i] = toupper(title[i]);
        }
    }
    // Add of title, author, year
    void AddBook()
    {
        std::string title, author;
        int year;

        std::cout << "Enter Book Title: ";
        std::cin.ignore();
        std::getline(std::cin, title);
        ConvertUpper(title);

        // Iterate over each Book  in the books vector.
        for (const Book &book : books)
        {
            if (book.getTitle() == title)
            {

                std::cout << "Book already exists." << std::endl;
                return;
            }
        }

        std::cout << "Enter Book Author: ";
        std::getline(std::cin, author);

        std::cout << "Enter Book Year: ";
        std::cin >> year;

        books.emplace_back(title, author, year);
        std::cout << "Book added successfully!" << std::endl;
    }
    // data of books
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
    // searching for books
    void SearchBook() const
    {
        std::string title;
        std::cout << "Enter the title of the book to search: ";
        std::cin.ignore();
        std::getline(std::cin, title);
        ConvertUpper(title);

        bool found = false;
        for (const Book &book : books)
        {
            if (book.getTitle() == title)
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
// Main Menu
void Menu(Library &lib)
{
    int bookchoice;
    bool condition = true;
    while (condition)
    {
        std::cout << "\n"
                  << "Menu" << std::endl;
        std::cout << "1 - Add a Book" << std::endl;
        std::cout << "2 - Display Books" << std::endl;
        std::cout << "3 - Search a Book" << std::endl;
        std::cout << "4 - Exit." << std::endl;
        std::cin >> bookchoice;

        switch (bookchoice)
        {
        case 1:
            system("cls");
            lib.AddBook();
            break;
        case 2:
            system("cls");
            lib.BooksLibrary();
            break;
        case 3:
            system("cls");
            lib.SearchBook();
            break;
        case 4:
            system("cls");
            std::cout << "Exited the progam." << std::endl;
            condition = false;
            return;
        default:
            system("cls");
            std::cout << "Invalid selection, please try again." << std::endl;
            std::cin.clear();
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
