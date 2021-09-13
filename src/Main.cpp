#include "Game.hpp"

Game *game;

int main(int argc, char* argv[]) {
    game = new Game();
    game->init("Flying Shroom", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, false);

    while (game->running()) {
        game->handleEvents();
        game->update();
        game->clear();
        game->display();
    }

    game->clean();

    return 0;
}