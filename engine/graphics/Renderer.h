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
		Renderer(int InWidth, int InHeight);
		~Renderer();

		bool Init(const char* WindowTitle);
		void Update();

	private:
		int Width, Height;
		SDL_Window* Window;
		SDL_Surface* ScreenSurface;
	};
}
