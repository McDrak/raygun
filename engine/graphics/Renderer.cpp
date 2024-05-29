//
// Created by CaGua on 5/29/2024.
//

#include "Renderer.h"

#include <iostream>
#include "SDL.h"

namespace Raygun
{
//======================================================================================================================
	Renderer::Renderer(const int InWidth, const int InHeight)
		: Width(InWidth), Height(InHeight), Window(nullptr), ScreenSurface(nullptr)
	{
	}

//======================================================================================================================
	Renderer::~Renderer()
	{
		SDL_FreeSurface(ScreenSurface);
		ScreenSurface = nullptr;

		SDL_DestroyWindow(Window);
		Window = nullptr;

		SDL_Quit();
	}

//======================================================================================================================
	bool Renderer::Init(const char* WindowTitle)
	{
		if (SDL_Init(SDL_INIT_VIDEO) < 0) {
			std::cout << "Error: SDL failed to Init Video" << '\n';
			return false;
		}

		Window = SDL_CreateWindow(WindowTitle,
								  SDL_WINDOWPOS_CENTERED,
								  SDL_WINDOWPOS_CENTERED,
								  Width,
								  Height,
								  SDL_WINDOW_SHOWN);
		if (!Window) {
			std::cout << "Error: SDL failed to Init Window" << '\n';
			return false;
		}

		ScreenSurface = SDL_GetWindowSurface(Window);

		return true;
	}

//======================================================================================================================
	void Renderer::Update()
	{
	}
}