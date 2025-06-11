#pragma once
#include "Scene.h"
#include "ImageRenderer.h"
#include "window.h"


class Scene0 : public Scene
{   
    ImageRenderer* mainMenu; //IMAGE
    SDL_Rect quit;//QUIT BUTTON
    SDL_Rect start;// START BUTTON
   
public:
    int Scene = 0;
    int sceneState = -1;//EVERY SCENE HAS THIS FOR SCENE SWITCHIBNG -1 = NO CHANGE
    Scene0();
    Scene0(SDL_Renderer* renderer);
    ~Scene0();

    void HandleEvents(SDL_Event& event) override;
    void Update(double deltaTime) override;
    void Render(SDL_Renderer* renderer) override;
    int GetSceneState() override; 
  

};

