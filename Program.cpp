//Our program file for this project
#include <iostream>
#include <string>
#include<iomanip>
#include"product.h"
#include <fstream>
#include <vector>

void main_menu() {
    std::cout << "Welcome to our store!" << std::endl;
    std::cout << "1: add an item to your cart" << std::endl;
    std::cout << "2: view items in your cart" << std::endl;
    std::cout << "3: view all items available for purchase" << std::endl;
    std::cout << "4: check out" << std::endl;
    std::cout << "5: exit the store" << std::endl;
}

void add_item(product* products, int size, std::vector<product>& cart, double& total_price) {
    std::cout << "What would you like to add to your cart?: ";
    
    std::string input;
    std::getline(std::cin, input);
    
    bool in_cart = false;
    int product_index = 0;
    for (int i = 0; i < size; i++) {
        if (products[i].getName() == input) {
            in_cart = true;
            product_index = i;
            break;
        }
    }

    if (in_cart) {
        if (products[product_index].getStock() == 0) {
            std::cout << "'" << products[product_index].getName() << "' isn't in stock." << std::endl;
            return;
        }

        //add to cart, decrease stock, add price to user total
        cart.push_back(products[product_index]);
        products[product_index].decreaseStock(1);
        total_price += products[product_index].getPrice();
        std::cout << "'" << products[product_index].getName() << "' was successfully added to your cart!" << std::endl;
    }
    else {
        std::cout << "'" << input << "' isn't avaiable" << std::endl;
    }
}

void view_cart(std::vector<product>& cart, const double total_price) {
    if (cart.size() == 0) {
        std::cout << "Cart is empty!" << std::endl;
        return;
    }

    for (int i = 0; i < cart.size(); i++) {
        std::cout << std::fixed << std::setprecision(2) << cart[i].getName() << " ($" << cart[i].getPrice() << ")" << std::endl;
    }
}

void print_receipt(std::vector<product>& cart, const double total_price) {
    std::ofstream receipt("receipt.txt",std::ios::app);
    std::cout << "Thanks for shopping at our store, here's your receipt!" << std::endl;

    for (int i = 0; i < cart.size(); i++) {
        std::cout << cart[i].getName() << " ($" << cart[i].getPrice() << ")" << std::endl;
    }
    std::cout << "Total: $" << total_price << std::endl;
   
   receipt<< "Thanks for shopping at our store, here's your receipt!" << std::endl;

    for (int i = 0; i < cart.size(); i++) {
        receipt << cart[i].getName() << " ($" << cart[i].getPrice() << ")" << std::endl;
    }
    receipt << "Total: $" << total_price << std::endl;
    receipt<<"Thank you for shopping at Totally Real Company Inc. have a good day!"<<std::endl;
    receipt.close();

    std::cout<<"A copy of your receipt will be in the file receipt.txt"<<std::endl;


}

void intializeInv(product* Inventory) {
std::ifstream inv("inventory.txt");
std::string x;
std::string word;
std::string name;
double price;
int stock;
int ID;
int lineCount=0;
while (std::getline(inv, x)) {
    lineCount++;
}
lineCount--;
inv.close();
std::ifstream y("inventory.txt");
if(y.is_open()){
std::getline(y,x);
    for(int i = 0;i<lineCount;i++ ){
    try {
y>>name;
y>>word;
price = std::stod(word);
y>>word;
stock = std::stoi(word);
y>>word;
ID=std::stoi(word);
}
catch (std::exception& e) {
    throw std::exception("inventory.txt is not formated correctly");
}
Inventory[i].setName(name);
Inventory[i].setPrice(price);
Inventory[i].setStock(stock);
Inventory[i].setID(ID);
}

}


}

int main()
{
    std::ifstream file("inventory.txt");
    int lineCount = 0;
    std::string dummyString;
    while (std::getline(file, dummyString)) {
        lineCount++;
    }
    file.close();
    lineCount--;
    //std::vector<product> products;
    //intializeInv(products);
    //just gonna add some common grocery store items
    //we can add more in the future if need be
    product* products = new product [lineCount];//{
    //    product("banana", 0.30, 45, 1),
    //    product("milk", 4.00, 40, 2),
    //    product("bread", 2.25, 50, 3),
    //    product("rice", 3.15, 35, 4),
    //    product("chips", 3.75, 55, 5),
    //    product("water", 1.50, 70, 6),
    //    product("carrot", 0.40, 45, 7),
    //    product("ham", 4.50, 60, 8),
    //};
    try{
    intializeInv(products);
    }
    catch (std::exception e) {
    }
    //resizable shopping cart for the user
    std::vector<product> cart;
    double total_price = 0;

    while (1) {
        main_menu();

        std::string input;
        std::getline(std::cin, input);
        int choice;
        try {
            choice = std::stoi(input);
        }
        catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }

        if (choice == 1) {
            std::cout << std::endl;
            add_item(products, 8, cart, total_price);
        }
        if (choice == 2) {
            std::cout << std::endl;
            view_cart(cart, total_price);
        }
        if (choice == 3) {
            std::cout << std::endl;
          products->listInv(lineCount);
        }
        if (choice == 4) {
            std::cout << std::endl;
            print_receipt(cart, total_price);
        }
        if (choice == 5) {
            std::cout << std::endl;
            std::cout << "Goodbye!" << std::endl;
            return 0;
        }

        std::cout << std::endl;
    }

    delete[] products;

    return 0;
}