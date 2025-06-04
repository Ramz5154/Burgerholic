#pragma once
#include <SDL2/SDL.h>

class Scene {
public:
    bool status = true;
    virtual ~Scene() {}
    virtual void HandleEvents(SDL_Event& event) = 0;
    virtual  void Update(double deltaTime) = 0;
    virtual void Render(SDL_Renderer* renderer) = 0;
};
