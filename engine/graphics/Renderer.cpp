//
// Created by CaGua on 5/29/2024.
//

#include "Renderer.h"

#include <iostream>
#include "SDL.h"

namespace Raygun
{
//======================================================================================================================
	Renderer::Renderer(const int t_Width, const int t_Height)
		: m_Width(t_Width), m_Height(t_Height), m_Window(nullptr), m_ScreenSurface(nullptr), m_HelloWorld(nullptr)
	{
	}

//======================================================================================================================
	Renderer::~Renderer()
	{
		SDL_FreeSurface(m_HelloWorld);
		m_HelloWorld = nullptr;

		SDL_FreeSurface(m_ScreenSurface);
		m_ScreenSurface = nullptr;

		SDL_DestroyWindow(m_Window);
		m_Window = nullptr;

		SDL_Quit();
	}

//======================================================================================================================
	bool Renderer::Init(const char* t_WindowTitle)
	{
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			std::cout << "Error: SDL failed to Init Video" << '\n';
			return false;
		}

		m_Window = SDL_CreateWindow(t_WindowTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_Width, m_Height, SDL_WINDOW_SHOWN);
		if (!m_Window)
		{
			std::cout << "Error: SDL failed to Init Window" << '\n';
			return false;
		}

		m_ScreenSurface = SDL_GetWindowSurface(m_Window);

		return true;
	}

//======================================================================================================================
	void Renderer::Update()
	{
		LoadMedia();
		SDL_UpdateWindowSurface(m_Window);
	}

//======================================================================================================================
	void Renderer::LoadMedia()
	{
		m_HelloWorld = SDL_LoadBMP("../assets/hello_world.bmp");
		if(!m_HelloWorld)
		{
			std::cout << "Error: Couldn't load test image - " << SDL_GetError() << '\n';
			return;
		}

		SDL_BlitSurface(m_HelloWorld, nullptr, m_ScreenSurface, nullptr);
	}
}
