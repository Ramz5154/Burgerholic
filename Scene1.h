#pragma once
#include "Scene.h"
#include "ImageRenderer.h"
#include "Customer.h"
#include "Player.h"
#include "ingredients.h"
#include <SDL2/SDL_ttf.h>

class Scene1 : public Scene {
public:
    Scene1(SDL_Renderer* renderer);
    ~Scene1();
   
    void HandleEvents(SDL_Event& event) override;
    void Update() override;
    void Render(SDL_Renderer* renderer) override;
    void VectorToImage();
    void custumerLineUp();
    void lineUp();
    void renderText(SDL_Renderer* renderer, TTF_Font* font, std::string text, int x, int y);
    int level = 3;
    int ordersFinished = 0;
private:
    bool reset = true;
    int customerpos1 = 0;
    int customerpos2 = 300;
    int customerpos3 = 600;
    TTF_Font* font;
    ImageRenderer* burgerShop;
    ImageRenderer* topBun;
    ImageRenderer* lettuce;
    ImageRenderer* tomato;
    ImageRenderer* cheese;
    ImageRenderer* ketchup;
    ImageRenderer* cookedBurger;
    ImageRenderer* rawBurger;
    ImageRenderer* bottomBun;
    ImageRenderer* customerHappy;
    ImageRenderer* customerAngry;
    Customer* customer;
    Player player;
    ingredients ing;
};
