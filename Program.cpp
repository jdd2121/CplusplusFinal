//Our program file for this project
#include <iostream>
#include <string>
#include<iomanip>
#include"product.h"
#include <fstream>
#include <vector>

void random() {

}

void print_receipt() {

}

void main_menu() {
    std::cout << "Welcome to our store!" << std::endl;
    std::cout << "To add an item to your cart, type '1'" << std::endl;
    std::cout << "To view items in your cart, type '2'" << std::endl;
    std::cout << "To view all items available for purchase, type '3'" << std::endl;
    std::cout << "To check out, type '4'" << std::endl;
    std::cout << "To exit the store, type '5'" << std::endl;
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
    //products->listInv(std::size(products));
    //use line above to display all products in the array :)

    //resizable shopping cart for the user
    std::vector<product> cart;

    //while (1) {
        main_menu();
    //}

    return 0;
}