//
// Created by CaGua on 5/29/2024.
//

#pragma once

class SDL_Window;
class SDL_Surface;

namespace Raygun
{
	class Renderer
	{
	public:
		Renderer(int t_Width, int t_Height);
		~Renderer();

		bool Init(const char* t_WindowTitle);
		void Update();
		// TODO: Remove this function when proper update is done
		void LoadMedia();

	private:
		int m_Width, m_Height;
		SDL_Window* m_Window;
		SDL_Surface* m_ScreenSurface;
		// TODO: Remove this as well
		SDL_Surface* m_HelloWorld;
	};
}
