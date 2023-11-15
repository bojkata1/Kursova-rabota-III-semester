#pragma once
#include <iostream>
#include <string>
class Product
{
	std::string name;
	int code;
	std::string category;
	float price;
public:
	Product();
	std::string getName();
	int getCode();
	std::string getCategory();
	float getPrice();
	void setName();
	void setCode();
	void setCategory();
	void setPrice();
	void showDetails();
};

