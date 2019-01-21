///
/// GameState.cpp
/// jrpg
/// See License.txt
///

#include <allegro5/keycodes.h>

#include <sl/core/World.hpp>
#include <sl/graphics/Window.cpp>
#include <sl/systems/RenderSystem.hpp>
#include <sl/core/ServiceLocator.hpp>

#include "GameState.hpp"

GameState::GameState()
	:State({ 0, 0, 1280, 720 })
{
	m_map.load("maps/demo.tmx");
}

GameState::~GameState()
{
}

void GameState::load()
{
}

void GameState::unload()
{
}

void GameState::event(ALLEGRO_EVENT* event)
{
	switch (event->type)
	{
	case ALLEGRO_EVENT_KEY_DOWN:
		switch (event->keyboard.keycode)
		{
		case ALLEGRO_KEY_ESCAPE:
			sl::Locator::window->close();
			break;
		}
		break;
	}
}

void GameState::update(const double dt)
{
}

void GameState::render()
{
	sl::Locator::world->getSystem<sl::RenderSystem>()->render();
}