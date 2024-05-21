#if defined(linux)
// SDL2
#include <SDL2/SDL.h>
#include <iostream>
#endif

#if defined(__WIN32__)
// SDL2
#include <SDL2/SDL.h>
#include <iostream>
#endif

using namespace std;


SDL_Window *window = nullptr;

void InitSDL() {

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "SDL Error: ", SDL_GetError(), 0);
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

        while (isLoop) {
            while (SDL_PollEvent(&event)) {
                switch (event.type) {
                    case SDL_QUIT: {
                        isLoop = false;
                        break;
                    }
                }
            }

            DrawFrame();
            loopCount++;
        }

        cout << "Loop counter value: " << loopCount << "\n";
        SDL_DestroyWindow(window);
        SDL_Quit();

    } catch (exception &e) {
        cout << e.what() << "\n";
    }

    return 0;
}