#include "TextureManager.hpp"

SDL_Texture* TextureManager::LoadTexture(const char* fileName, SDL_Renderer* ren) {
    SDL_Texture* tex = NULL;
    tex = IMG_LoadTexture(ren, fileName);

    if (tex == NULL) {
        std::cout << "Error. Couldn't load texture... Error: " << SDL_GetError() << std::endl;
    }

    return tex;
}