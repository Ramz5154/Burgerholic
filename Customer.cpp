#include "Customer.h"
#include <SDL2/SDL.h>
#include <time.h>

Customer::Customer()
{
   
}

std::vector<ingredients::ingredientsType> Customer::getCustomersOrder() const
{
    return customerOrder;
}

void Customer::makeRandomOrder()
{
  
  
   
    customerOrder.push_back(ingredients::ingredientsType::BUN);

     for (int i = 0; i < 6; ++i) {
        random_index = rand() % enumSize;
    
      
            switch (random_index) {
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

     customerOrder.push_back(ingredients::ingredientsType::BUN);

}
