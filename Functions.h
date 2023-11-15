#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Product.h"
void showInventory(std::vector<Product> inventory);
void sortByPrice(std::vector<Product>& inventory);
void sortAlphabetically(std::vector<Product>& inventory);
void filter(std::vector<Product> inventory);
bool isValidNumber(std::string number, bool isFloat);
