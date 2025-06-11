#pragma once
#include <SDL2/SDL.h>

class Scene {
public:
    bool status = true;
    virtual ~Scene() {} // USED SO THE DERIVED CLASS DESTRUCTORS ALSO RUNS SO NO MEMORY LEAKS 
    virtual void HandleEvents(SDL_Event& event) = 0; //ABSTRACT
    virtual  void Update(double deltaTime) = 0;//ABSTART
    virtual void Render(SDL_Renderer* renderer) = 0;//ABSTARCT
    virtual int GetSceneState() { return -1; }  // -1 = no change
};
