#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

class ImageRenderer {
public:
    ImageRenderer(SDL_Renderer* renderer, const std::string& filePath);
    ~ImageRenderer();

    void Render(int x, int y, int width, int height);

private:
    SDL_Renderer* renderer;
    SDL_Texture* texture;
};
