#include <iostream>
#include <C:/SDL2-w64/include/SDL.h>
#include <C:/SDL2-w64/include/SDL_image.h>

class Game {
    public:
        Game();
        ~Game();

        // Main Functions
        void init(const char* title, int x, int y, int width, int height, bool fullScreen);
        void handleEvents();
        void update();
        void clear();
        void display();
        void clean();

        // Texture Manager
        SDL_Texture* LoadTexture(const char* filePath);
        void RenderTexture(SDL_Texture* tex);

        // return functions
        bool running() { return isRunning; }
        SDL_Window* getWindow() { return window; }
        SDL_Renderer* getRenderer() { return renderer; }

    private:
        bool isRunning = true;
        SDL_Window *window;
        SDL_Renderer *renderer;        
};