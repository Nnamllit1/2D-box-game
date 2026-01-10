#include <SDL.h>

void render_grid(SDL_Renderer* renderer, int cells, int screen_width, int screen_height)
{
    if (cells <= 0)
        return;

    int cell_width  = screen_width  / cells;
    int cell_height = screen_height / cells;

    // Background
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);   // Black color
    SDL_RenderClear(renderer);

    // Grid lines
    SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);

    for (int i = 0; i <= cells; ++i)
    {
        int x = i * cell_width;
        SDL_RenderDrawLine(renderer, x, 0, x, screen_height);
    }

    for (int i = 0; i <= cells; ++i)
    {
        int y = i * cell_height;
        SDL_RenderDrawLine(renderer, 0, y, screen_width, y);
    }

    SDL_RenderPresent(renderer);
}
