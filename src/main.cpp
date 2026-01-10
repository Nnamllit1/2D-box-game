#include <iostream>
#include <SDL.h>

int SCREEN_WIDTH = 640;
int SCREEN_HEIGHT = 480;

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
        SDL_CreateWindow("Hello, world!", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    SDL_Renderer* renderer =
        SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Event event;
    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            handle_events(&event);
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
