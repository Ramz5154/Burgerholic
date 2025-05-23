
#pragma once
#include "Scene.h"
#include "ImageRenderer.h"
#include "Customer.h"
#include "Player.h"
#include "ingredients.h"

class Scene1 : public Scene {
public:
    Scene1(SDL_Renderer* renderer);
    ~Scene1();
   
    void HandleEvents(SDL_Event& event) override;
    void Update() override;
    void Render(SDL_Renderer* renderer) override;
    void VectorToImage();
private:
    bool reset = true;
  
    ImageRenderer* burgerShop;
    ImageRenderer* topBun;
    ImageRenderer* lettuce;
    ImageRenderer* tomato;
    ImageRenderer* cheese;
    ImageRenderer* ketchup;
    ImageRenderer* cookedBurger;
    ImageRenderer* rawBurger;
    ImageRenderer* bottomBun;
    Customer* customer;
    Player player;
    ingredients ing;
};
