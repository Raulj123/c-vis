//g++ -o program platformer.cpp -I/usr/include/SDL2 -lSDL2

#include<iostream>
#include <string>
#include <SDL.h>
using namespace std;

int main() {

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window *window= SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,600,400, SDL_WINDOW_SHOWN);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1,0);
	SDL_SetRenderDrawColor(renderer, 0 ,244,0,244);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	SDL_Delay(3000);

 	return 0;
}
