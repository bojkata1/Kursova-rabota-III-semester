#include "Functions.h"

void showInventory(std::vector<Product> inventory) { 
	for (int i = 0; i != inventory.size(); i++) { // going through every element in the vector
		inventory[i].showDetails(); //showing the details of the element
	}
}

void sortByPrice(std::vector<Product>& inventory) { // '&' to update the values of the vector structure
	
	int left = 0; // start of sorting
	int right = inventory.size() - 1; // end of sorting
	bool swapped = true; // checking if vectors swapped
	while (swapped)
	{
		swapped = false;
		for (int i = left; i < right; i++) // searching for biggest price
		{
			if (inventory[i].getPrice() < inventory[i + 1].getPrice()) { std::swap(inventory[i], inventory[i + 1]); swapped = true; }
		}
		if (!swapped) {// checking if vectors have swapped
			break;
		}
		right--;// moving the end near the center
		swapped = false;
		for (int i = right-1; i >= left; i--) //searching for smallest price 
		{
			if (inventory[i].getPrice() < inventory[i + 1].getPrice()) { std::swap(inventory[i], inventory[i + 1]); swapped = true; }
		}
		left++;// moving the start near the center
	}
}

void sortAlphabetically(std::vector<Product>& inventory) { // '&' to update the values of the vector structure
	int maxSymbols;
	for (int i = 0; i < inventory.size()-1; i++) // going through every vector
	{
		for (int j = i+1; j < inventory.size(); j++) // comparing previous vector with the others
		{
			(inventory[i].getName().size() >= inventory[j].getName().size() ? maxSymbols = inventory[i].getName().size() : maxSymbols = inventory[j].getName().size()); // getting maximum symbols to work with
			for (int k = 0; k < maxSymbols; k++) // Looking through every symbol
			{
				
				if (inventory[i].getName()[k] > inventory[j].getName()[k]) { std::swap(inventory[i], inventory[j]); break; } // swapping the vectors if needed
				else {
					if (inventory[i].getName()[k] < inventory[j].getName()[k]) { break; }
				}
			}
		}
	}
}

void filter(std::vector<Product> inventory) {
	std::string lowerLimit_s, upperLimit_s;
	std::vector<Product> sortedInventory = inventory;
	sortByPrice(sortedInventory);
	float lowerLimit, upperLimit;
	std::cout << "Enter lower limit: "; std::getline(std::cin, lowerLimit_s);
	std::cout << "Enter upper limit: "; std::getline(std::cin, upperLimit_s);
	if (isValidNumber(lowerLimit_s, true) && isValidNumber(upperLimit_s, true)) { // checks if the limits are valid
		lowerLimit = stof(lowerLimit_s);
		upperLimit = stof(upperLimit_s);
		for (int i = inventory.size() - 1; i >= 0; i--) {
			if (lowerLimit >= upperLimit) {
				std::cout << "Lower limit is equel or bigger than upper limit!" << std::endl;
				break;
			}
			if (lowerLimit <= inventory[i].getPrice() && inventory[i].getPrice() <= upperLimit) {
				inventory[i].showDetails();
			}
		}
	}
	else {
		std::cout << "Invalid number!!!" << std::endl;
	}
}

bool isValidNumber(std::string number, bool isFloat) {
	bool isNegative = false;
	int start = 0; // represents the starting index
	int decimalPoint = 0; // counts the number of decimal points found

	if (number.size() == 0) { // checks if the input is an empty string
		return false;
	}
	if (number[0] == '-') { // checks if the number is negative
		if (number.size() == 1) { // checks if the input consists of '-' only
			return false;
		}
		isNegative = true;
		start = 1; // moves the starting index so the '-' is skipped during validation
	}
	for (int i = start; i < number.size(); i++) { // goes through every character in the input

		if (number[i] == '.' && isFloat) { // checks if the input is float
			decimalPoint++;
			if (decimalPoint > 1) { // checks if the number of decimal points is valid
				return false;
			}
			if (isNegative && i == 1) { // checks if the character after the '-' is '.'
				return false;
			}
			continue;
		}
		if (!isdigit(number[i])) {
			return false;
		}
	}
	return true;
}
