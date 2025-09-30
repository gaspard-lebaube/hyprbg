#include <SDL2/SDL.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    int width = 1920, height = 1080;

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_Window *window = SDL_CreateWindow(
        "hyprbg", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width,
        height, // will be resized by xwinwrap anyway
        SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS | SDL_WINDOW_ALLOW_HIGHDPI);

    if (!window) {
        SDL_Log("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *renderer =
        SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        SDL_Log("Renderer could not be created! SDL_Error: %s\n",
                SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    bool quit = false;
    SDL_Event e;
    const int frameDelay = 1000 / 24; // 24 FPS

    int colors[3][3] = {
        {255, 0, 0}, // red
        {0, 255, 0}, // green
        {0, 0, 255}  // blue
    };
    int currentColor = 0;
    Uint32 lastSwitch = SDL_GetTicks();

    while (!quit) {
        Uint32 frameStart = SDL_GetTicks();

        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT)
                quit = true;
        }

        if (SDL_GetTicks() - lastSwitch >= 1000) {
            currentColor = (currentColor + 1) % 3;
            lastSwitch = SDL_GetTicks();
        }

        SDL_SetRenderDrawColor(renderer, colors[currentColor][0],
                               colors[currentColor][1], colors[currentColor][2],
                               255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);

        Uint32 frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
