///
/// LoadState.cpp
/// jrpg
/// See License.txt
///

#include <sl/core/ServiceLocator.hpp>

#include "LoadState.hpp"

LoadState::LoadState()
	:State({ 0, 0, 1280, 720 })
{
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
	sl::Locator::stateMachine->push("menu");
}

void LoadState::render()
{
}

/*
	https://opengameart.org/content/rpg-tiles-0
	https://opengameart.org/content/oga-16x16-jrpg-sprites-tiles
	https://opengameart.org/content/dawnlike-16x16-universal-rogue-like-tileset-v181
	https://opengameart.org/content/trees-bushes
	https://opengameart.org/content/rpg-town-pixel-art-assets
*/