#include <iostream>
#include "ingredients.h"
#include "Customer.h"
#include "string"

int main() {
	std::cout << "welcome to burgerholic";
	
	Customer customer;
	ingredients ingredientsMenu;

	customer.customerOrder.push_back(ingredients::BUN);
	customer.customerOrder.push_back(ingredients::BUN);

	std::cout << customer.customerOrder[0];
	std::cout << ingredientsMenu.toString( ingredients::CHEESE);

	return 0;
	
}