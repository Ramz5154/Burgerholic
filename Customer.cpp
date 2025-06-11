#include "Customer.h"
#include <SDL2/SDL.h>
#include <time.h>

Customer::Customer()
{
   
}

Customer::~Customer()
{
}

std::vector<ingredients::ingredientsType> Customer::getCustomersOrder() const
{
    return customerOrder;//RETURNS ORDER
}

void Customer::makeRandomOrder()
{
  
    customerOrder.clear();// ERASES THE LAST ORDER OR THEY WILL STACK ON TOP OF EACH OTHER
   
    customerOrder.push_back(ingredients::ingredientsType::BUN);//PUSHES FIRST BUN

     for (int i = 0; i < burgerSize; ++i) {//SIZE OF BURGER BURGERSIZE WILL GROW WITH LEVEL TO MAKE DIFFCULT
        random_index = rand() % enumSize;// RANDOM INGRIDNETGS 
    
      
            switch (random_index) {//MAKES BURGER AND PUSHES TO VECTOR
            case 1:
                customerOrder.push_back(ingredients::ingredientsType::COOKEDBURGER);
                break;
            case 2:
                customerOrder.push_back(ingredients::ingredientsType::LETTUCE);
                break;
            case 3:
                customerOrder.push_back(ingredients::ingredientsType::TOMATO);
                break;
            case 4:
                customerOrder.push_back(ingredients::ingredientsType::KETCHUP);
                break;
            case 0:
                customerOrder.push_back(ingredients::ingredientsType::CHEESE);
                break;
            }

        }

     customerOrder.push_back(ingredients::ingredientsType::BUN);//LAST BUN TO CLOSE

}
