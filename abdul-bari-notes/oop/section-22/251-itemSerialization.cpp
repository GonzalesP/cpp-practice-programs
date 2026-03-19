#include <iostream>
#include <fstream>
#include <string>

class Item {
private:
    std::string name;
    float price;
    int quantity;
public:
    Item(std::string n = "", float p = 0.00f, int q = 0);
    friend std::ofstream& operator<<(std::ofstream& ofs, Item& item);
    friend std::ifstream& operator>>(std::ifstream& ifs, Item& item);

    friend std::ostream& operator<<(std::ostream& os, Item& item);
};
std::ofstream& operator<<(std::ofstream& ofs, Item& item) {
    ofs << item.name << std::endl;
    ofs << item.price << std::endl;
    ofs << item.quantity << std::endl;
    return ofs;
}
std::ifstream& operator>>(std::ifstream& ifs, Item& item) {
    ifs >> item.name >> item.price >> item.quantity;
    return ifs;
}
std::ostream& operator<<(std::ostream& os, Item& item) {
    std::cout << "Name: " << item.name << std::endl;
    std::cout << "Price: " << item.price << std::endl;
    std::cout << "Quantity: " << item.quantity << std::endl;
}

int main() {
    Item item1("Juice", 3.25f, 2);

    std::ofstream ofs("Item.txt", std::ios::trunc);
    ofs << item1;
    ofs.close();


    Item item2;
    
    std::ifstream ifs("Item.txt");
    ifs >> item2;
    ifs.close();

    std::cout << item2;

    return 0;
}

Item::Item(std::string n = "", float p = 0.00f, int q = 0) {
    name = n;
    price = p;
    quantity = q;
}