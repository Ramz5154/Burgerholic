#pragma once
#include "Scene.h"
#include "ImageRenderer.h"



class Scene0 : public Scene
{   
public:
    Scene0(SDL_Renderer* renderer);
    ~Scene0();

    void HandleEvents(SDL_Event& event) override;
    void Update(double deltaTime) override;
    void Render(SDL_Renderer* renderer) override;

  

};

