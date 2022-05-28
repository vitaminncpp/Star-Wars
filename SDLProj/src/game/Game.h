#pragma once
#include <unordered_map>
#include <SDL.h>
#include <SDL_ttf.h>
#include "..\sim\Ship.h"
#include "..\sim\Maze.h"
#include "..\dsa\State.h"
#include "..\sim\Planet.h"

#ifndef NDEBUG
#include <iostream>
#define LOG(msg) std::cout<<__FILE__<<":"<<__LINE__<<"::"<<msg<<std::endl
#else
#define LOG(msg)
#endif // !NDEBUG

class Game
{
private:
	bool isRunning;
	SDL_Window *window;
	SDL_Renderer* renderer;
	
	//Maze maze;
	SDL_Texture* message;
	State state;
	TTF_Font * font;

private:
	Ship ship;
	Planet earth;
	std::unordered_map<Object,Object> map;

public:
	Game(const char* title, int top, int left, int width, int height);
	~Game();
	void Go();
	void Init(const char* title,int top,int left, int width,int height);
	void Update();
	void Interact();
	void Render();
	void Clean();
	void HandleEvents();
	inline bool IsRunning() {
		return this->isRunning;
	}
	void Reset();
	void PostProcessing();
};

