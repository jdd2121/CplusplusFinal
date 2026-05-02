//Our program file for this project
#include <iostream>
#include <string>
#include<iomanip>
#include"product.h"
#include <fstream>
#include <vector>

void random() {

}

void printReceipt() {

}

int main()
{
    ////Print out a message to the user
    //std::cout << "Hello, World!" << std::endl;

    //std::cout << "Testing (JD)" << std::endl;
    //std::cout << "Test #2" << std::endl;
    //std::cout << "Test #3" << std::endl;

    product products[3];
    for (int i = 0;i < 3;i++) {
        products[i].product::product();
    }
    products->listInv(std::size(products));
    //use line above to display all products in the array :)

    return 0;
}