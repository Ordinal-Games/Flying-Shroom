#include "Game.hpp"

Game *game;

int main(int argc, char* argv[]) {
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    game = new Game();
    game->init("Flying Shroom", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, false);

    SDL_Texture* shroomTex = game->LoadTexture("res/Shroom/Shroom.png");

    while (game->running()) {
        frameTime = SDL_GetTicks();

        game->handleEvents();
        game->update();

        // render
        game->clear();
        game->RenderTexture(shroomTex);
        game->display();

        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    game->clean();

    return 0;
}