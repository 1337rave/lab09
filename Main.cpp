#include <iostream>
#include <vector>
#include <string>

class Worker {
private:
    std::string fullName;
    std::string position;
    int startYear;
    double salary;

public:
    explicit Worker(const std::string& name, const std::string& pos, int year, double sal)
        : fullName(name), position(pos), startYear(year), salary(sal) {}

    void displayInfo() const {
        std::cout << "Full Name: " << fullName << "\n";
        std::cout << "Position: " << position << "\n";
        std::cout << "Start Year: " << startYear << "\n";
        std::cout << "Salary: " << salary << "\n";
    }

    int getExperience(int currentYear) const {
        return currentYear - startYear;
    }

    double getSalary() const {
        return salary;
    }

    std::string getPosition() const {
        return position;
    }
};

int main() {
    std::vector<Worker> workers = {
        Worker("John Doe", "Manager", 2010, 50000),
        Worker("Jane Smith", "Developer", 2015, 60000),
        Worker("Alice Johnson", "Accountant", 2012, 55000),
        Worker("Bob Brown", "Manager", 2018, 70000)
    };

    int choice;
    std::string searchParam;
    int yearsExperience;
    double salaryLimit;

    do {
        std::cout << "Menu:\n"
            << "1. Search by Experience\n"
            << "2. Search by Salary\n"
            << "3. Search by Position\n"
            << "0. Exit\n"
            << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter minimum years of experience: ";
            std::cin >> yearsExperience;
            std::cout << "\nWorkers with more than " << yearsExperience << " years of experience:\n";
            for (const auto& worker : workers) {
                if (worker.getExperience(2023) > yearsExperience) {
                    worker.displayInfo();
                    std::cout << "---------------\n";
                }
            }
            break;

        case 2:
            std::cout << "Enter minimum salary: ";
            std::cin >> salaryLimit;
            std::cout << "\nWorkers with salary exceeding " << salaryLimit << ":\n";
            for (const auto& worker : workers) {
                if (worker.getSalary() > salaryLimit) {
                    worker.displayInfo();
                    std::cout << "---------------\n";
                }
            }
            break;

        case 3:
            std::cout << "Enter position to search: ";
            std::cin >> searchParam;
            std::cout << "\nWorkers with position " << searchParam << ":\n";
            for (const auto& worker : workers) {
                if (worker.getPosition() == searchParam) {
                    worker.displayInfo();
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
