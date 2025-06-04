#pragma once
#include "Scene.h"
#include "ImageRenderer.h"
#include "window.h"


class Scene0 : public Scene
{   
    ImageRenderer* mainMenu;
    SDL_Rect quit;
    SDL_Rect start;
   
public:
    int Scene = 0;
    int sceneState = -1;
    Scene0();
    Scene0(SDL_Renderer* renderer);
    ~Scene0();

    void HandleEvents(SDL_Event& event) override;
    void Update(double deltaTime) override;
    void Render(SDL_Renderer* renderer) override;
    int GetSceneState() override; 
  

};

