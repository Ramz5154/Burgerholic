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
	ingredientsType type;
	
	std::string ingredientsOrder;
	std::vector<std::string > order;

    ingredients(ingredientsType t) : type(t) {
        switch (type) {
        case ingredientsType::BUN:
            ingredientsOrder = "bun";
            break;
        case ingredientsType::BURGER:
            ingredientsOrder = "burger";
            break;
        case ingredientsType::LETTUCE:
            ingredientsOrder = "lettuce";
            break;
        case ingredientsType::TOMATO:
            ingredientsOrder = "tomato";
            break;
        case ingredientsType::CHEESE:
            ingredientsOrder = "cheese";
            break;
        case ingredientsType::KETCHUP:
            ingredientsOrder = "ketchup";
            break;
        default:
          
            break;
        }
    }

	
	
	

};
