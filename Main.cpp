#include <iostream>
#include <vector>
#include <string>

class Book {
private:
    std::string author;
    std::string title;
    std::string publisher;
    int year;
    int pageCount;

public:
    explicit Book(const std::string& a, const std::string& t, const std::string& p, int y, int pc)
        : author(a), title(t), publisher(p), year(y), pageCount(pc) {}

    void displayInfo() const {
        std::cout << "Author: " << author << "\n";
        std::cout << "Title: " << title << "\n";
        std::cout << "Publisher: " << publisher << "\n";
        std::cout << "Year: " << year << "\n";
        std::cout << "Page Count: " << pageCount << "\n";
    }

    int getYear() const {
        return year;
    }

    std::string getAuthor() const {
        return author;
    }

    std::string getPublisher() const {
        return publisher;
    }
};

int main() {
    std::vector<Book> books = {
        Book("Author1", "Title1", "Publisher1", 2000, 300),
        Book("Author2", "Title2", "Publisher2", 2010, 250),
        Book("Author1", "Title3", "Publisher1", 2015, 400),
        Book("Author3", "Title4", "Publisher3", 2020, 350)
    };

    int choice;
    std::string searchParam;

    do {
        std::cout << "Menu:\n"
            << "1. Search by Author\n"
            << "2. Search by Publisher\n"
            << "3. Search by Year\n"
            << "0. Exit\n"
            << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter author to search: ";
            std::cin >> searchParam;
            std::cout << "\nBooks by author " << searchParam << ":\n";
            for (const auto& book : books) {
                if (book.getAuthor() == searchParam) {
                    book.displayInfo();
                    std::cout << "---------------\n";
                }
            }
            break;

        case 2:
            std::cout << "Enter publisher to search: ";
            std::cin >> searchParam;
            std::cout << "\nBooks by publisher " << searchParam << ":\n";
            for (const auto& book : books) {
                if (book.getPublisher() == searchParam) {
                    book.displayInfo();
                    std::cout << "---------------\n";
                }
            }
            break;

        case 3:
            int yearToSearch;
            std::cout << "Enter year to search: ";
            std::cin >> yearToSearch;
            std::cout << "\nBooks published after " << yearToSearch << ":\n";
            for (const auto& book : books) {
                if (book.getYear() > yearToSearch) {
                    book.displayInfo();
                    std::cout << "---------------\n";
                }
            }
            break;

        case 0:
            std::cout << "Exiting program.\n";
            break;

        default:
            std::cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
