#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Item {
private:
    std::string name;
    float price;
    int quantity;
public:
    Item(std::string, float, int);
    std::string getName() { return name; }
    float getPrice() { return price; }
    int getQuantity() { return quantity; }

    friend std::ofstream& operator<<(std::ofstream& ofs, Item& i);
    friend std::ifstream& operator>>(std::ifstream& ifs, Item& i);

    friend std::ostream& operator<<(std::ostream& os, Item& i);
};

Item::Item(std::string n = "", float p = 0.00f, int q = 0) {
    name = n;
    price = p;
    quantity = q;
}

std::ofstream& operator<<(std::ofstream& ofs, Item& i) {
    ofs << i.name << " " << i.price << " " << i.quantity << std::endl;
    return ofs;
}
std::ifstream& operator>>(std::ifstream& ifs, Item& i) {
    ifs >> i.name >> i.price >> i.quantity;
    return ifs;
}

std::ostream& operator<<(std::ostream& os, Item& i) {
    os << i.name << " " << i.price << " " << i.quantity;
    return os;
}

int main() {
    int totalItems = 0;
    std::cout << "How many items will you save?: ";
    std::cin >> totalItems;

    std::vector<Item> itemList;

    std::cout << "Enter an item(s) name, price, and quantity." << std::endl;
    for (int i = 0; i < totalItems; i++) {
        std::string n;
        float p;
        int q;

        std::cout << "Item #" << i + 1 << ": ";
        std::cin >> n >> p >> q;
        Item it(n, p, q);

        itemList.push_back(it);
    }

    std::ofstream ofs("items.txt", std::ios::trunc);
    for (Item i : itemList)
        ofs << i;
    ofs.close();

    std::cout << "Retrieving items.txt..." << std::endl;

    std::ifstream ifs("items.txt");
    while (!ifs.eof()) {
        Item it;
        ifs >> it;

        if (it.getName() != "")
            std::cout << it << std::endl;
    }
    ifs.close();

    return 0;
}