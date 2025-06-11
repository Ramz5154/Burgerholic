#pragma once
#include <string>
#include <vector>
class ingredients {

public:
	enum ingredientsType
	{
		//ENUM FOR THE INGRIDENTS 
		//THESE ARE THE VALUES STORED IN THE PLAYER AND CUSTOMERS ORDER VECTORS
		BUN,
		RAWBURGER,
		LETTUCE,
		TOMATO,
		CHEESE,
		KETCHUP,
		COOKEDBURGER

	};
	
	
	std::string ingredientsOrder;
    ingredients();
    ~ingredients();

	static bool ingredientsMatch(std::vector<ingredients::ingredientsType> customer, std::vector<ingredients::ingredientsType> player);

	


	inline std::string toString(ingredientsType type) {
		switch (type) {
		case BUN: return "bun";
		case RAWBURGER: return "raw burger";
		case LETTUCE: return "lettuce";
		case TOMATO: return "tomato";
		case CHEESE: return "cheese";
		case KETCHUP: return "ketchup";
		default: return "unknown";
		}
	}

};
