#if defined(linux)
#include <iostream>
// SDL2
#include <SDL2/SDL.h>
#endif

#if defined(__WIN32__)

#include <iostream>
// SDL2
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#endif

using namespace std;


SDL_Window *window = nullptr;

void InitSDL() {

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "SDL Error: ", SDL_GetError(), nullptr);
        throw;
    }

    window = SDL_CreateWindow(
            "Blood Fight In Shanghai",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            1280,
            720,
            0
    );

    if (window == nullptr) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "SDL Error: Windows is not create!", SDL_GetError(), nullptr);
        SDL_Quit();
        throw;
    }
}

void DrawFrame() {

}

int main(int argv, char **args) {

    try {
        bool isLoop = true;
        long long loopCount = 1;
        SDL_Event event;

        InitSDL();

        SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (renderer == nullptr) {
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "SDL Error: ", SDL_GetError(), nullptr);
            throw;
        }

        // Load image
        IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
        SDL_Texture *texture = IMG_LoadTexture(renderer, "..\\assets\\background.bmp");


        // Main loop
        while (isLoop) {
            while (SDL_PollEvent(&event)) {
                switch (event.type) {
                    case SDL_QUIT: {
                        isLoop = false;
                        break;
                    }
                }
            }

            SDL_RenderCopy(renderer, texture, nullptr, nullptr);
            SDL_RenderPresent(renderer);
            DrawFrame();
            loopCount++;
        }

        SDL_DestroyTexture(texture);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();

        cout << "Loop counter value: " << loopCount << "\n";

    } catch (exception &e) {
        cout << e.what() << "\n";
    }

    return 0;
}