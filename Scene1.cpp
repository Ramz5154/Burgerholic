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
    customer = new Customer();
    customer->makeRandomOrder();
    for (int i = 0; i < customer->customerOrder.size(); ++i) { //prints the indexes for the customer's order
        std::cout << ' ' << customer->customerOrder[i];
    }
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
        if (ing.ingredientsMatch(customer->customerOrder, player.playerOrder)) {
            std::cout << "orders match\n";
        }
        else {
            std::cout << "orders don't match\n";
        }

        player.playerOrder.clear();
        player.enter = false;
    }
}

void Scene1::Update() {
   
}

void Scene1::Render(SDL_Renderer* renderer) {
    burgerShop->Render(0, 0, 1080, 720);
    if (player.playerOrder.size() > 0) {
        VectorToImage();
    }
}

void Scene1::VectorToImage()
{
    for (int i = 0; i < player.playerOrder.size(); ++i) {
        // Special handling for bun at the first index
        if (player.playerOrder[i] == ingredients::ingredientsType::BUN) {
            if (i == 0) {
                bottomBun->Render(0, 200, 1080, 720);
            }
            else {
                topBun->Render(0, 200, 1080, 720);
            }
        }
        else {
           
            switch (player.playerOrder[i]) {
            case ingredients::ingredientsType::TOMATO:
                tomato->Render(0, 0, 1080, 720);
                break;
            case ingredients::ingredientsType::LETTUCE:
                lettuce->Render(0, 0, 1080, 720);
                break;
            case ingredients::ingredientsType::CHEESE:
                cheese->Render(0, 0, 1080, 720);
                break;
            case ingredients::ingredientsType::KETCHUP:
                ketchup->Render(0, 0, 1080, 720);
                break;
            case ingredients::ingredientsType::RAWBURGER:
                rawBurger->Render(0, 0, 1080, 720);
                break;
            case ingredients::ingredientsType::COOKEDBURGER:
                cookedBurger->Render(0, 0, 1080, 720);
                break;
            }
        }
    }
}
