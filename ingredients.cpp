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
	 if (player.size() == customer.size()) {// COMPARES VECTORS IF THEY ARE THE SAME;
		
			 if (player == customer) {
				 return true;
			 }

			 else {
				 return false;
			 }
	 }
	return false;
}

