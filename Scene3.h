#pragma once
#include "Scene.h"
#include "ImageRenderer.h"
#include "Customer.h"
#include "Player.h"
#include "ingredients.h"
#include <SDL2/SDL_ttf.h>
#include "Scene0.h"
#include "Scene1.h"

class Scene3 : public Scene {

    Scene1 scene1;
    Scene0 scene0;
    TTF_Font* font;
    ImageRenderer* scoreBoard;
    void renderText(SDL_Renderer* renderer, TTF_Font* font, std::string text, int x, int y);
public:
 Scene3();
    Scene3(SDL_Renderer* renderer);

    ~Scene3();
    void HandleEvents(SDL_Event& event) override;
    void Update(double deltaTime) override;
    void Render(SDL_Renderer* renderer) override;
    int GetSceneState() override;
   
};