
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

private:
    ImageRenderer* burgerImage;
    Customer* customer;
    Player player;
    ingredients ing;
};
