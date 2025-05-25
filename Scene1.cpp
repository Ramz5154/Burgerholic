#include "Scene1.h"
#include <iostream>

Scene1::Scene1(SDL_Renderer* renderer) {
    burgerShop = new ImageRenderer(renderer, "assets/burgerStoreCounter.png");
    topBun = new ImageRenderer(renderer, "assets/TopBun.png");
    lettuce = new ImageRenderer(renderer, "assets/lettuce.png");
    tomato = new ImageRenderer(renderer, "assets/tomato.png");
    cheese = new ImageRenderer(renderer, "assets/cheese.png");
    ketchup = new ImageRenderer(renderer, "assets/ketchup.png");
    bottomBun = new ImageRenderer(renderer, "assets/bottomBun.png");
    cookedBurger = new ImageRenderer(renderer, "assets/cookedBurger.png");
    rawBurger = new ImageRenderer(renderer, "assets/rawBurger.png");
    customerHappy = new ImageRenderer(renderer, "assets/customerHappy.png");
    customerAngry = new ImageRenderer(renderer, "assets/customerAngry.png");
    customer = new Customer();
    lineUp();
   
}

Scene1::~Scene1() {
    delete burgerShop;
    delete customer;
}

void Scene1::HandleEvents(SDL_Event& event) {
    player.PlaceOrder(event);
    if (event.type == SDL_QUIT || player.quit) {
       
    }

    if (player.enter) {
        for (int i = 0; i < customer->LineUp[i].size(); ++i) {
            if (ing.ingredientsMatch(customer->LineUp[i], player.playerOrder)) {
                std::cout << "orders match\n";
                customer->LineUp[i].clear();
                i = 0;
                break;
            }

            else {
                std::cout << "orders don't match\n";
               
            }
           
        }
        
        player.playerOrder.clear();
        player.enter = false;
    }

}

void Scene1::Update() {
   
}

void Scene1::Render(SDL_Renderer* renderer) {
    burgerShop->Render(0, 0, 1080, 720);
    

    if (player.playerOrder.size() > 0 || customer->customerOrder.size() > 0) {
        VectorToImage();
    }
}

void Scene1::VectorToImage()
{
    int currentY = player.firstIng;
    

   

    for (int i = 0; i < player.playerOrder.size(); ++i) {

        int yPos = currentY - (i * 25);
            // Special handling for bun at the first index
            if (player.playerOrder[i] == ingredients::ingredientsType::BUN) {
                if (i == 0) {
                    bottomBun->Render(0, yPos, 1080, 720);
                   
                }
                else {
                    topBun->Render(0, yPos, 1080, 720);
                    
                }
            }
            else {

                switch (player.playerOrder[i]) {
                case ingredients::ingredientsType::TOMATO:
                    
                    tomato->Render(0, yPos, 1080, 720);
                 
                    break;
                case ingredients::ingredientsType::LETTUCE:
                    lettuce->Render(0, yPos, 1080, 720);
                   
                    break;
                case ingredients::ingredientsType::CHEESE:
                    cheese->Render(0, yPos, 1080, 720);
                   
                    break;
                case ingredients::ingredientsType::KETCHUP:
                    ketchup->Render(0, yPos, 1080, 720);
                   
                    break;
                case ingredients::ingredientsType::RAWBURGER:
                    rawBurger->Render(0, yPos, 1080, 720);
                   
                    break;
                case ingredients::ingredientsType::COOKEDBURGER:
                    cookedBurger->Render(0, yPos, 1080, 720);
                  
                    break;
                }
            }
            
    }
    int currentx = 0;
   

    for (int i = 0; i < customer->LineUp.size(); ++i) {
        int xpos = currentx + (i * 200);
        for (int y = 0; y < customer->LineUp[i].size(); ++y)
        {
            int yPos = currentY - (y * 20);
            // Special handling for bun at the first index
            if (customer->LineUp[i][y] == ingredients::ingredientsType::BUN) {
                if (y == 0) {
                    bottomBun->Render(xpos, yPos, 500, 500);

                }
                else {
                    topBun->Render(xpos, yPos, 500, 500);

                }
            }
            else {

                switch (customer->LineUp[i][y]) {
                case ingredients::ingredientsType::TOMATO:

                    tomato->Render(xpos, yPos, 500, 500);

                    break;
                case ingredients::ingredientsType::LETTUCE:
                    lettuce->Render(xpos, yPos, 500, 500);

                    break;
                case ingredients::ingredientsType::CHEESE:
                    cheese->Render(xpos, yPos, 500, 500);

                    break;
                case ingredients::ingredientsType::KETCHUP:
                    ketchup->Render(xpos, yPos, 500, 500);

                    break;
                case ingredients::ingredientsType::COOKEDBURGER:
                    cookedBurger->Render(xpos, yPos, 500, 500);

                    break;
                }
            }
        }
    }



}

void Scene1::lineUp()
{
    for (int i = 0; i < 3; ++i) { // or however many customers
        customer->makeRandomOrder();
        customer->LineUp.push_back(customer->customerOrder);
        for (int i = 0; i < customer->customerOrder.size(); ++i) { //prints the indexes for the customer's order
            std::cout << ' ' << customer->customerOrder[i];
        }
        std::cout << '\n';
    }
}
