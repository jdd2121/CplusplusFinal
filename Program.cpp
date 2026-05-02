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
        std::cout << cart[i].getName() << " ($" << cart[i].getPrice() << ")" << std::endl;
    }
}

void print_receipt(std::vector<product>& cart, const double total_price) {
    std::cout << "Thanks for shopping at our store, here's your receipt!" << std::endl;

    for (int i = 0; i < cart.size(); i++) {
        std::cout << cart[i].getName() << " ($" << cart[i].getPrice() << ")" << std::endl;
    }
    std::cout << "Total: $" << total_price << std::endl;
}

int main()
{
    //just gonna add some common grocery store items
    //we can add more in the future if need be
    product products[8]{
        product("banana", 0.30, 45, 1),
        product("milk", 4.00, 40, 2),
        product("bread", 2.25, 50, 3),
        product("rice", 3.15, 35, 4),
        product("chips", 3.75, 55, 5),
        product("water", 1.50, 70, 6),
        product("carrot", 0.40, 45, 7),
        product("ham", 4.50, 60, 8),
    };
    
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
            products->listInv(std::size(products));
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

    return 0;
}