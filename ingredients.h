#pragma once
#include <string>
#include <vector>
class ingredients {
public:
	enum ingredientsType
	{
		
		BUN,
		BURGER,
		LETTUCE,
		TOMATO,
		CHEESE,
		KETCHUP,

	};
	
	
	std::string ingredientsOrder;
    ingredients();
    ~ingredients();

	inline std::string toString(ingredientsType type) {
		switch (type) {
		case BUN: return "bun";
		case BURGER: return "burger";
		case LETTUCE: return "lettuce";
		case TOMATO: return "tomato";
		case CHEESE: return "cheese";
		case KETCHUP: return "ketchup";
		default: return "unknown";
		}
	}

};
