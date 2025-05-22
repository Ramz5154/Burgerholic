#include "Scene1.h"
#include <iostream>

Scene1::Scene1(SDL_Renderer* renderer) {
    burgerImage = new ImageRenderer(renderer, "assets/flappybird.png");
    customer = new Customer();
    customer->makeRandomOrder();
    for (int i = 0; i < customer->customerOrder.size(); ++i) { //prints the indexes for the customer's order
        std::cout << ' ' << customer->customerOrder[i];
    }
}

Scene1::~Scene1() {
    delete burgerImage;
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
    burgerImage->Render(100, 100, 100, 100);
}
