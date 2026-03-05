#include <iostream>
#include <fstream>
#include <string>

class TodoItem {
public:
    int itemNum;
    std::string itemDesc;
    
    friend std::ostream& operator<<(std::ostream& os, TodoItem& item);

    friend std::ofstream& operator<<(std::ofstream& ofs, TodoItem& item);
    friend std::ifstream& operator>>(std::ifstream& ifs, TodoItem& item);
};
std::ostream& operator<<(std::ostream& os, TodoItem& item) {
    os << item.itemNum << ". " << item.itemDesc << std::endl;
    return os;
}
std::ofstream& operator<<(std::ofstream& ofs, TodoItem& item) {
    ofs << item.itemNum << " " << item.itemDesc << std::endl;
    return ofs;
}
std::ifstream& operator>>(std::ifstream& ifs, TodoItem& item) {
    ifs >> item.itemNum;
    std::getline(ifs, item.itemDesc);
    return ifs;
}

void retrieveTodoList(std::string fileName) {
    std::ifstream ifs(fileName);
    if (!ifs.is_open()) {
        std::cout << "Error: file '" << fileName << "' not found." << std::endl;
        return;
    }
    bool eofReached = false;
    while (!ifs.eof()) {
        TodoItem item;
        ifs >> item;
        if (item.itemDesc != "")
            std::cout << item;
    }
    ifs.close();
    std::cout << "end of list." << std::endl;
}

void createTodoList(std::string fileName) {
    std::ofstream ofs(fileName, std::ios::trunc);

    int itemNum = 1;
    std::string itemDesc = "";
    bool endList = false;
    std::cout << "enter a todo item or type exit to stop entering items" << std::endl;

    while (!endList) {
        std::cout << "Item " << itemNum << ". ";
        std::getline(std::cin, itemDesc);
        if (itemDesc != "exit") {
            TodoItem i;
            i.itemNum = itemNum;
            i.itemDesc = itemDesc;

            ofs << i;
            itemNum++;
        }
        else {
            endList = true;
        }
    }

    ofs.close();
    std::cout << "exiting." << std::endl;
}

int main() {
    std::string menuOption;
    std::cout << "r - retrieve todo list" << std::endl;
    std::cout << "c - create todo list" << std::endl;

    try {
        std::cout << "enter an option: ";
        std::getline(std::cin, menuOption);

        std::string fileName;
        std::cout << "enter file name: ";
        std::getline(std::cin, fileName);

        if (menuOption == "r") {
            retrieveTodoList(fileName);
        }
        else if (menuOption == "c") {
            createTodoList(fileName);
        }
        else {
            throw 1;
        }
    }
    catch (...) {
        std::cout << "Error: invalid menu option. exiting." << std::endl;
        return 0;
    }

    return 0;
}