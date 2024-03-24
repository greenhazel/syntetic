#include <SDL.h>
#include <stdlib.h>
#include <stdbool.h>

//ебаные костыли устаревших намертво сищников
#define false 0
#define true 1
 

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
#define mapX  8      //map width
#define mapY  8      //map height
#define mapS 64      //map cube size
int map[8][8]=           //the map array. Edit to change level but keep the outer walls
{
 {1,1,1,1,1,1,1,1},
 {1,0,1,0,0,0,0,1},
 {1,0,1,0,0,0,0,1},
 {1,0,1,0,0,0,0,1},
 {1,0,0,0,0,0,0,1},
 {1,0,0,0,0,1,0,1},
 {1,0,0,0,0,0,0,1},
 {1,1,1,1,1,1,1,1},	
};
void draw2dMap(SDL_Renderer *renderer) 
{
    int x, y, xo, yo;
    for (y = 0; y < mapY; y++) {
        for (x = 0; x < mapX; x++) {
            if (map[y][x] == 1) {
                SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
            } else {
                SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF); // Set color to black for empty spaces
            }
            xo = x * mapS; // Corrected calculation for xo
            yo = y * mapS;
            SDL_Rect rect = {xo, yo, mapS, mapS};
            SDL_RenderFillRect(renderer, &rect); // Fill rectangle instead of drawing lines
        }
    }
}

void drawPlayer(SDL_Renderer *renderer){ 
    SDL_SetRenderDrawColor(renderer, 0x00, 0x10, 0x10, 0xFF);
    SDL_Rect rect = {100, 100, 100,100};
    SDL_RenderFillRect(renderer, &rect);
}


int main() { 
    SDL_Window *window;
  
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("!!CRASH SDL_INIT_VIDEO FAILED!!!");
    };

    window = SDL_CreateWindow("Hello, SDL 2!",SDL_WINDOWPOS_UNDEFINED, 
    SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 
    SDL_WINDOW_SHOWN);
    
    if (window == NULL) {
        return 1;
    }
    








    
    bool run;
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
      SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    drawPlayer(renderer);
    draw2dMap(renderer);
    SDL_RenderPresent(renderer);

    SDL_Delay(5000);


    SDL_DestroyWindow(window);

    SDL_Quit();
}