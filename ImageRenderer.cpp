#include "ImageRenderer.h"

#include <iostream>

ImageRenderer::ImageRenderer(SDL_Renderer* renderer, const std::string& filePath)
    : renderer(renderer), texture(nullptr)
{
    texture = IMG_LoadTexture(renderer, filePath.c_str());
    if (!texture) {
        std::cerr << "Failed to load image: " << IMG_GetError() << std::endl;
    }
}

ImageRenderer::~ImageRenderer() {
    if (texture) {
        SDL_DestroyTexture(texture);
    }
}

void ImageRenderer::Render(int x, int y, int width, int height) {
    if (texture) {
        SDL_Rect dstRect = { x, y, width, height };
        SDL_RenderCopy(renderer, texture, nullptr, &dstRect);
    }
}
