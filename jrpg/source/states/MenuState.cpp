///
/// MenuState.cpp
/// jrpg
/// See License.txt
///

#include <sl/core/World.hpp>
#include <sl/core/ServiceLocator.hpp>
#include <sl/systems/RenderSystem.hpp>

#include "MenuState.hpp"

MenuState::MenuState()
{
	m_bounds.m_x = 0;
	m_bounds.m_y = 0;
	m_bounds.m_width = 1280;
	m_bounds.m_height = 720;


	m_menu.createFromScript("menuUI.lua");
}

MenuState::~MenuState()
{
}

void MenuState::load()
{
}

void MenuState::unload()
{
}

void MenuState::event(ALLEGRO_EVENT* event)
{
}

void MenuState::update(const double dt)
{
}

void MenuState::render()
{
	sl::Locator::world->getSystem<sl::RenderSystem>()->render();
}