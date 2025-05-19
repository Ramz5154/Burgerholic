#include "ingredients.h"
#include "Customer.h"
#include "Player.h"
#include <iostream>

ingredients::ingredients()
{
}

ingredients::~ingredients()
{
}

 bool ingredients::ingredientsMatch(std::vector<ingredients::ingredientsType>  customer, std::vector<ingredients::ingredientsType>  player)
{
	

	for (int i = 0; i < customer.size(); ++i) {
		if (player[i] == customer[i]) {
			std::cout << "orders match" << '\n';
			
		}
		else {
			std::cout << "orders dont match " << '\n';
			
		}

	}
	return true;
}

