#pragma once
#include <iostream>
#include <string>

class product {
std::string name;
double price;
int stock;
int ID; //The ID is what position it is in the array

public:

product(std::string name,double price,int stock,int ID);
product();

void setName(std::string name);

void setPrice(double newPrice);

void setID(int newID);
void setStock(int newStock);
void increaseStock(int x);
void decreaseStock(int x);

void const listProduct();
std::string const getName();
double const getPrice();
int const getStock();
};