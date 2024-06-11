//
// Created by CaGua on 5/28/2024.
//

#pragma once

#include "graphics/Renderer.h"

namespace Raygun
{
	struct ApplicationSpecification
	{
		int Width = 960;
		int Height = 540;
		const char* Title = "Project Raygun";
	};

	class Application
	{
	public:
		explicit Application(const ApplicationSpecification& t_Specification = ApplicationSpecification());
		~Application() = default;

		void Run();
		void Loop();
		void OnUpdate();
		void OnRender();

	private:
		ApplicationSpecification m_AppSpecification;
		Renderer m_Renderer;
	};
}
