#include <iostream>
#include <SDL.h>

bool running = true;

void handle_events(SDL_Event* event)
{
    if (event->type == SDL_QUIT)
    {
        running = false;
    }
}

int main(int argc, char* argv[])
{
    std::cout << "Hello, world!" << std::endl;

    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window* window =
        SDL_CreateWindow("Hello, world!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);

    SDL_Renderer* renderer =
        SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Event event;
    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            handle_events(&event);
        }
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
