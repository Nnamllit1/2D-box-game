#include <iostream>
#include <SDL.h>
#include <vector>
#include <cstdint>

constexpr int SCREEN_WIDTH = 640;
constexpr int SCREEN_HEIGHT = 480;

bool running = true;

constexpr int CELL_SIZE = 4;
constexpr int GRID_WIDTH = SCREEN_WIDTH / CELL_SIZE;
constexpr int GRID_HEIGHT = SCREEN_HEIGHT / CELL_SIZE;

std::vector<uint8_t> grid(GRID_WIDTH * GRID_HEIGHT, 0);

inline int idx(int x, int y)
{
    return y * GRID_WIDTH + x;
}

void update_powder(std::vector<uint8_t>& grid)
{
    for (int y = GRID_HEIGHT - 2; y >= 0; --y)
    {
        for (int x = 1; x < GRID_WIDTH - 1; ++x)
        {
            int i = idx(x, y);
            if (grid[i] != 1)
                continue;

            int below = idx(x, y + 1);

            if (grid[below] == 0)
            {
                grid[below] = 1;
                grid[i] = 0;
                continue;
            }

            bool left_free  = grid[idx(x - 1, y + 1)] == 0;
            bool right_free = grid[idx(x + 1, y + 1)] == 0;

            if (left_free && right_free)
            {
                int nx = (rand() & 1) ? x - 1 : x + 1;
                grid[idx(nx, y + 1)] = 1;
                grid[i] = 0;
            }
            else if (left_free)
            {
                grid[idx(x - 1, y + 1)] = 1;
                grid[i] = 0;
            }
            else if (right_free)
            {
                grid[idx(x + 1, y + 1)] = 1;
                grid[i] = 0;
            }
        }
    }
}

void draw_powder(std::vector<uint8_t>& grid, int mouse_x, int mouse_y)
{
    int gx = mouse_x / CELL_SIZE;
    int gy = mouse_y / CELL_SIZE;

    if (gx < 0 || gx >= GRID_WIDTH || gy < 0 || gy >= GRID_HEIGHT)
        return;

    grid[idx(gx, gy)] = 1;
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
            if (event.type == SDL_QUIT)
            {
                running = false;
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN || 
                (event.type == SDL_MOUSEMOTION && (event.motion.state & SDL_BUTTON_LMASK)))
            {
                draw_powder(grid, event.motion.x, event.motion.y);
            }
        }

        update_powder(grid);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 200, 200, 50, 255);

        for (int y = 0; y < GRID_HEIGHT; ++y)
        {
            for (int x = 0; x < GRID_WIDTH; ++x)
            {
                if (grid[idx(x, y)] == 1)
                {
                    SDL_Rect r{
                        x * CELL_SIZE,
                        y * CELL_SIZE,
                        CELL_SIZE,
                        CELL_SIZE
                    };
                    SDL_RenderFillRect(renderer, &r);
                }
            }
        }

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
