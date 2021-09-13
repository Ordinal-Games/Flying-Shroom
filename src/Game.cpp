#include "Game.hpp"

Game::Game() {}
Game::~Game() {}

void Game::init(const char* title, int x, int y, int width, int height, bool fullScreen) {
    int flags = 0;
    if (fullScreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "SDL Initialized Successfully" << std::endl;
        window = SDL_CreateWindow(title,x,y,width,height,fullScreen);

        if (window) {
            std::cout << "SDL Window Created!" << std::endl;
        }

        renderer = SDL_CreateRenderer(window, 1, 0);
        if (renderer) {
           std::cout << "SDL Renderer Created!" << std::endl; 
        }

        isRunning = true;
    } else {
        isRunning = false;
    }
}

void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
    }
}

void Game::update() {}

void Game::clear() {
    SDL_RenderClear(renderer);
}

void Game::display() {
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_QUIT;
}
