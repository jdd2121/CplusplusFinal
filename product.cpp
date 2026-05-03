#include <iostream>
#include <string>
#include <iomanip>
#include "product.h"

product::product(std::string name, double price, int stock, int ID) {
	setName(name);
	setPrice(price);
	setStock(stock);
	setID(ID);
}
product::product() {
	this->name = "N/A";
	this->price = 0.00;
	this->stock = 0;
	this->ID = 0;
}

void product::setName(std::string newName) {
	if (newName.length() <= 0) {
		throw std::exception("Invalid Name - name cannot be empity");
	}
	else {
		this->name = newName;
	}
}
void product::setPrice(double newPrice) {
	if (newPrice <= 0) {
		throw std::exception("Invalid Price price must be more than 0");
	}
	else {
		this->price = newPrice;
	}
}
void product::setStock(int newStock) {
	if (newStock < 0) {
		throw std::exception("Invalid Stock - stock cannot be less than 0");
	}
	else {
		this->stock = newStock;
	}
}
void product::setID(int newID) {
	this->ID = newID;
}

void product::increaseStock(int x) {
	setStock(this->stock + x);
}
void product::decreaseStock(int x) {
	setStock(this->stock - x);
}

const std::string product::getName() {
	return this->name;
}
const double product::getPrice() {
	return this->price;
}
const int product::getStock() {
	return this->stock;
}

const void product::listProduct() {
	std::cout << std::fixed<<std::setprecision(2)<<getName() << "\t\t$" << getPrice() << "\tStock:" << getStock() << std::endl;
}

const void product::listInv(int x) {

	for (int i = 0;i < x;i++) {
		this[i].listProduct();
	}
}