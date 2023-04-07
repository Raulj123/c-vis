//g++ -o program platformer.cpp -I/usr/include/SDL2 -lSDL2
//
#include<iostream>
#include <vector>
#include <random>

#include <algorithm>
#include <SDL.h>
using namespace std;

int main() {

	random_device rando;				   // creating random device object
	uniform_int_distribution<int> d(1, 99); // generates ints uniformally between 1-99
	vector<int> v;

	for (int i=0; i <100; i++){
		v.push_back(d(rando));
	}
	
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	SDL_CreateWindowAndRenderer(100*10, 100*10,0, &window, &renderer);		//create a window with a size of 100x100 pixels multiplied by a scaling factor of 10.
	SDL_RenderSetScale(renderer,10,10);		//ets the scale of the renderer to 10x10, which means that anything drawn using this renderer will be scaled up by a factor of 10 in both the x and y directions.
	
	//sorting..
	for(int i =0; i <v.size() -1; i++){		// minus one because no need to loop last element (loop counter)
		for(int j =0; j< v.size() - i -1; j++){		// minus i - 1 since largest int will bubble up each iteration 
			if(v[j] > v[j+1]){				
				swap(v[j], v[j+1]);
			}
		}
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
	// SDL_Init(SDL_INIT_EVERYTHING);
	// SDL_Window *window= SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,800,600, SDL_WINDOW_SHOWN);
	// SDL_Renderer *renderer = SDL_CreateRenderer(window, -1,0);
	// SDL_SetRenderDrawColor(renderer, 0 ,244,0,244);
	// SDL_RenderClear(renderer);
	// SDL_RenderPresent(renderer);
	// SDL_Delay(3000);

 	return 0;
}
