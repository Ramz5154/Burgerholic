#pragma once
#include "Scene.h"
#include "ImageRenderer.h"
#include "Customer.h"
#include "Player.h"
#include "ingredients.h"
#include <SDL2/SDL_ttf.h>
#include "Scene0.h"

class Scene1 : public Scene {
public:

    Scene1(SDL_Renderer* renderer);
    ~Scene1();
   
    void HandleEvents(SDL_Event& event) override;
    void Update(double deltaTime) override;
    void Render(SDL_Renderer* renderer) override;
    int GetSceneState() override;
    void VectorToImage();
    void custumerLineUp();
    void MouseCommand(int mouseX, int mouseY);
    void lineUp();
    void cookBurger(double deltatime);
    void renderText(SDL_Renderer* renderer, TTF_Font* font, std::string text, int x, int y);
    void renderTimer(SDL_Renderer* renderer, TTF_Font* font, std::string text, int x, int y);
    int level = 1;
    int ordersFinished = 0;
private:
    bool burgerCooked = false;
    bool panPressed = false;
    double timer = 30.0;
    bool timerDone = false;
    double cookTimer = 3.0;
    bool cookTimerDone = false;
    bool reset = true;
    int customerpos1 = 0;
    int customerpos2 = 300;
    int customerpos3 = 600;

    Scene0 scene;

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
    ImageRenderer* bell;
    ImageRenderer* pan;


    ImageRenderer* cheeseTin;
    ImageRenderer* ketchupBottle;
    ImageRenderer* burgerTin;
    ImageRenderer* bunTin;
    ImageRenderer* tomatoTin;
    ImageRenderer* plate;
    ImageRenderer* lettuceTin;

    SDL_Rect cheeseT;
    SDL_Rect bunT;
    SDL_Rect tomatoT;
    SDL_Rect burgerT;
    SDL_Rect lettuceT;
    SDL_Rect ketchupB;
    SDL_Rect bellRect;
    SDL_Rect panRect;
   


    Customer* customer;
    Player player;
    ingredients ing;
};
