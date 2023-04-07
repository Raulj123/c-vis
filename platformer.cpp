//g++ -o program platformer.cpp -I/usr/include/SDL2 -lSDL2
//
#include<iostream>
#include <vector>
#include <random>

#include <algorithm>
#include <SDL.h>
using namespace std;
void drawState(vector<int> v, SDL_Renderer* renderer, int loopCounter, int swap);
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
	SDL_RenderSetScale(renderer,10,10);		//sets the scale of the renderer to 10x10, which means that anything drawn using this renderer will be scaled up by a factor of 10 in both the x and y directions.
	
	//sorting..
	for(int i =0; i <v.size() -1; i++){		// minus one because no need to loop last element (loop counter)
		for(int j =0; j< v.size() - i -1; j++){		// minus i - 1 since largest int will bubble up each iteration 
			if(v[j] > v[j+1]){				
				swap(v[j], v[j+1]);
			}
			//clear Screen
			SDL_SetRenderDrawColor(renderer,0,0,0,255);		//ombination of these two functions will set the entire renderer to black.
			SDL_RenderClear(renderer);
			drawState(v, renderer, i,j);	//calling function to draw lines
			SDL_RenderPresent(renderer);
			SDL_Delay(1);
		}
		
	}

 	return 0;
}

void drawState(vector<int> v, SDL_Renderer* renderer, int loopCounter, int swap){
	int index = 0;
	for(int i : v){
		if(index == loopCounter){
			SDL_SetRenderDrawColor(renderer, 255,165,0,255);
		} else if(index == swap) {
			SDL_SetRenderDrawColor(renderer, 255,192,202,255);
		}else{
			SDL_SetRenderDrawColor(renderer, 255,255,255,255);		//function sets the render draw color to white
		}
		SDL_RenderDrawLine(renderer, index, 99, index, i);
		/*Parameters for DrawLine function: makes vertical lines depending on i value 
		renderer =  object that you want to draw the line on
		x = The x-coordinate of the starting point of the line.
		y = The y-coordinate of the starting point of the line.
		x= The x-coordinate of the ending point of the line
		y= 	The y-coordinate of the ending point of the line.				
		*/
		index++;
	}
}