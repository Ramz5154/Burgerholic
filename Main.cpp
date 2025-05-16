#include <iostream>
#include "ingredients.h"
#include "Customer.h"

int main() {
	std::cout << "welcome to burgerholic";
	
	Customer customer;
	ingredients ingredientsMenu;

	customer.customerOrder.push_back(ingredients::BUN);
	customer.customerOrder.push_back(ingredients::BUN);

	std::cout << customer.customerOrder.size();


	return 0;
	
}