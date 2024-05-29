//
// Created by CaGua on 5/28/2024.
//

#pragma once

#include <string>

namespace Raygun
{
	struct ApplicationSpecification
	{
		int Width = 640;
		int Height = 480;
		std::string Title = "Project Raygun";
	};

	class Application
	{
	public:
		explicit Application(const ApplicationSpecification& Spec = ApplicationSpecification());
		~Application() = default;

		void Run();
		void OnUpdate();

	private:
		ApplicationSpecification AppSpecification;
	};

}