#include <iostream>
#include "ingredients.h"
#include "Customer.h"

int main() {
	std::cout << "welcome to burgerholic";
	
	Customer customer;
	ingredients ingredientsMenu;

	customer.customerOrder.push_back(ingredientsMenu.BUN);
	
	for (int i = 0; i < customer.customerOrder.size(); ++i) {
		std::cout << customer.customerOrder[i];
	}
}