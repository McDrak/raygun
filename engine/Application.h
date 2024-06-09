//
// Created by CaGua on 5/28/2024.
//

#pragma once

#include "graphics/Renderer.h"

namespace Raygun
{
	struct ApplicationSpecification
	{
		int Width = 1280;
		int Height = 720;
		const char* Title = "Project Raygun";
	};

	class Application
	{
	public:
		explicit Application(const ApplicationSpecification& Spec = ApplicationSpecification());
		~Application() = default;

		void Run();
		void Loop();
		void OnUpdate();
		void OnRender();

	private:
		ApplicationSpecification AppSpecification;
		Renderer Renderer;
	};
}
