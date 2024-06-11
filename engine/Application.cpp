//
// Created by CaGua on 5/28/2024.
//

#include "Application.h"

#include <iostream>
#include "SDL_timer.h"

namespace Raygun
{
//======================================================================================================================
	Application::Application(const Raygun::ApplicationSpecification& t_Specification)
		: m_AppSpecification(t_Specification), m_Renderer(t_Specification.Width, t_Specification.Height)
	{
	}

//======================================================================================================================
	void Application::Run()
	{
		if (!m_Renderer.Init(m_AppSpecification.Title))
		{
			std::cout << "Error: Renderer failed to Init" << '\n';
			return;
		}

		// TODO: This should be run on a while(WindowIsNotClose)
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
		m_Renderer.Update();
	}
}
