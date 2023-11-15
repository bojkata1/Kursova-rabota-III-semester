#include <iostream>
#include <vector>
#include "Product.h"
#include "Functions.h"

int main() {
	std::string command;
	std::vector<Product> inventory;
	do {
		std::cout << "Choose one of the commands: 'Add product (1)', 'Show Inventory (2)', 'Sort by price (3)', 'Sort alphabetically (4)', 'Filter by price (5)', 'exit (6)'" << std::endl;
		std::getline(std::cin, command);
		if (command == "1") {
			Product p;
			inventory.push_back(p);
		}
		else if (command == "2") {
			showInventory(inventory);
		}
		else if (command == "3") {
			sortByPrice(inventory);
			showInventory(inventory);
		}
		else if (command == "4") {
			sortAlphabetically(inventory);
			showInventory(inventory);
		}
		else if (command == "5") {
			filter(inventory);
		}
		else if (command == "6") {
			break;
		}
		else {
			std::cout << "Unknown command!!!" << std::endl;
		}
	} while (true);
	return 0;
}
