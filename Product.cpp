#include "Product.h"
#include "Functions.h"
Product::Product(){
	setName();
	setCode();
	setCategory();
	setPrice();
}

// Getters
std::string Product::getName() { return name; }
int Product::getCode() { return code; }
std::string Product::getCategory() { return category; }
float Product::getPrice() { return price; }


// Setters
void Product::setName() {
	std::cout << "Enter product's name: "; std::getline(std::cin, name);
}
void Product::setCode() {
	std::string code;
	do {
		std::cout << "Enter product's code: "; std::getline(std::cin, code);
	} while (!isValidNumber(code, false)); // checking if the number is valid
	this->code = stoi(code);
}
void Product::setCategory() {
	std::cout << "Enter product's category: "; std::getline(std::cin, category);
}
void Product::setPrice() {
	std::string price;
	do {
		std::cout << "Enter product's price: "; std::getline(std::cin, price);
	} while (!isValidNumber(price, true)); // checking if the number is valid
	this->price = stof(price);
}

void Product::showDetails() {
	std::cout << "Name: " << name << std::endl;
	std::cout << "Code: " << code << std::endl;
	std::cout << "Category: " << category << std::endl;
	std::cout << "Price: " << price << std::endl << std::endl;
}
