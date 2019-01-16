///
/// LoadState.cpp
/// jrpg
/// See License.txt
///

#include <sl/core/ServiceLocator.hpp>

#include "LoadState.hpp"

LoadState::LoadState()
{
	m_bounds.m_x = 0;
	m_bounds.m_y = 0;
	m_bounds.m_width = 1280;
	m_bounds.m_height = 720;
}

LoadState::~LoadState()
{
}

void LoadState::load()
{
}

void LoadState::unload()
{
}

void LoadState::event(ALLEGRO_EVENT* event)
{
}

void LoadState::update(const double dt)
{
	sl::Locator::stateMachine->pop();
}

void LoadState::render()
{
}