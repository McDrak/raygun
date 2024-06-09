//
// Created by CaGua on 5/28/2024.
//

#include "Application.h"

#include <iostream>
#include "SDL_timer.h"

namespace Raygun
{
//======================================================================================================================
	Application::Application(const Raygun::ApplicationSpecification& Spec)
		: AppSpecification(Spec), Renderer(Spec.Width, Spec.Height)
	{
	}

//======================================================================================================================
	void Application::Run()
	{
		if (!Renderer.Init(AppSpecification.Title))
		{
			std::cout << "Error: Renderer failed to Init" << '\n';
			return;
		}

		// This should be run on a while(WindowIsNotClose)
		Loop();

		SDL_Delay(3000);
	}

//======================================================================================================================
	void Application::Loop()
	{
		OnUpdate();
		OnRender();
	}

//======================================================================================================================
	void Application::OnUpdate()
	{
	}

//======================================================================================================================
	void Application::OnRender()
	{
		Renderer.Update();
	}
}
