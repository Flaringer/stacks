#include <iostream>
#include <stack>
#include <string>

class Book {
private:
    std::string title;
    std::string author;

public:
    Book(const std::string& title, const std::string& author)
        : title(title), author(author) {}

    void displayInfo() const {
        std::cout << "Title: " << title << ", Author: " << author << std::endl;
    }
};

class BookStack {
private:
    std::stack<Book> stack;

    void displayAllHelper(std::stack<Book> tempStack) {
        if (tempStack.empty()) return;
        Book topBook = tempStack.top();
        tempStack.pop();
        displayAllHelper(tempStack);
        topBook.displayInfo();
    }

public:
    void push(const Book& book) {
        stack.push(book);
    }

    void pop() {
        if (isEmpty()) {
            std::cerr << "Error: Cannot pop from an empty stack." << std::endl;
            return;
        }
        stack.pop();
    }

    void top() const {
        if (isEmpty()) {
            std::cerr << "Error: Stack is empty." << std::endl;
            return;
        }
        stack.top().displayInfo();
    }

    bool isEmpty() const {
        return stack.empty();
    }

    int size() const {
        return stack.size();
    }

    void displayAll() {
        if (isEmpty()) {
            std::cerr << "Error: Stack is empty." << std::endl;
            return;
        }
        displayAllHelper(stack);
    }
};

void displayMenu() {
    std::cout << "1. Add a book to the stack\n";
    std::cout << "2. Remove a book from the stack\n";
    std::cout << "3. Display the top book\n";
    std::cout << "4. Check if the stack is empty\n";
    std::cout << "5. Display the total number of books\n";
    std::cout << "6. Display all books\n";
    std::cout << "7. Exit\n";
}

int main() {
    BookStack bookStack;
    int choice;
    std::string title, author;

    while (true) {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter book title: ";
                std::cin.ignore();
                std::getline(std::cin, title);
                std::cout << "Enter book author: ";
                std::getline(std::cin, author);
                bookStack.push(Book(title, author));
                break;

            case 2:
                bookStack.pop();
                break;

            case 3:
                bookStack.top();
                break;

            case 4:
                if (bookStack.isEmpty()) {
                    std::cout << "The stack is empty." << std::endl;
                } else {
                    std::cout << "The stack is not empty." << std::endl;
                }
                break;

            case 5:
                std::cout << "Total number of books: " << bookStack.size() << std::endl;
                break;

            case 6:
                bookStack.displayAll();
                break;

            case 7:
                return 0;

            default:
                std::cerr << "Invalid choice. Please try again." << std::endl;
        }
    }
}
