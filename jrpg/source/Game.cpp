///
/// Game.cpp
/// jrpg
/// See License.txt
///

#include <sl/core/Keys.hpp>
#include <sl/tags/CameraTag.hpp>
#include <sl/systems/RenderSystem.hpp>
#include <sl/systems/AnimationSystem.hpp>

#include "states/LoadState.hpp"
#include "states/MenuState.hpp"

#include "Game.hpp"

Game::Game(const std::string& config, std::function<void(std::ofstream&)> newConfig)
	:sl::Application(config, newConfig)
{
	m_world->registerSystem<sl::RenderSystem>(20, 100);
	m_world->registerSystem<sl::AnimationSystem>();

	m_stateMachine->createState<LoadState>("load");
	m_stateMachine->createState<MenuState>("menu");
	m_stateMachine->push("menu");
	m_stateMachine->push("load");

	entt::DefaultRegistry::entity_type cameraEntity = m_world->m_registry.create();
	m_world->m_registry.assign<sl::CameraTag>(entt::tag_t{}, cameraEntity, sl::Rect<float, int>{ 0, 0, 640, 480 }); // 1280, 720

	sl::Keys::UI_CONFIRM = ALLEGRO_KEY_ENTER;
}