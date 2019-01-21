///
/// MenuState.cpp
/// jrpg
/// See License.txt
///

#include <functional>

#include <sl/graphics/Window.hpp>
#include <sl/ui/widgets/Button.hpp>
#include <sl/core/ServiceLocator.hpp>
#include <sl/events/KeyDownEvent.hpp>
#include <sl/libs/entt/signal/dispatcher.hpp>

#include "MenuState.hpp"

MenuState::MenuState()
	:State({0, 0, 1280, 720})
{
	m_menu.createFromScript("menuUI.lua", &m_widgetStorage, &m_themeStorage);

	dynamic_cast<sl::Button*>(m_widgetStorage["new"])->registerCallback([]() -> void
	{
		sl::Locator::stateMachine->push("game");
	});

	dynamic_cast<sl::Button*>(m_widgetStorage["load"])->registerCallback([]() -> void
	{
		LOG_S(INFO) << "Load game here...";
	});

	dynamic_cast<sl::Button*>(m_widgetStorage["options"])->registerCallback([]() -> void
	{
		LOG_S(INFO) << "Open options menu here...";
	});

	dynamic_cast<sl::Button*>(m_widgetStorage["quit"])->registerCallback([]() -> void
	{
		sl::Locator::window->close();
	});
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
	switch (event->type)
	{
	case ALLEGRO_EVENT_MOUSE_AXES:
		sl::Locator::dispatcher->trigger<sl::MouseMovedEvent>(event->mouse.x, event->mouse.y, event->mouse.dx, event->mouse.dy, event->mouse.pressure);
		break;

	case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
		sl::Locator::dispatcher->trigger<sl::MousePressedEvent>(event->mouse.x, event->mouse.y, event->mouse.button);
		break;

	case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
		sl::Locator::dispatcher->trigger<sl::MouseReleasedEvent>(event->mouse.x, event->mouse.y, event->mouse.button);
		break;

	case ALLEGRO_EVENT_KEY_DOWN:
		sl::Locator::dispatcher->trigger<sl::KeyDownEvent>(event->keyboard.keycode);
		switch (event->keyboard.keycode)
		{
		case ALLEGRO_KEY_ESCAPE:
			sl::Locator::window->close();
			break;
		}
		break;
	}
}

void MenuState::update(const double dt)
{
	m_menu.update(dt);
}

void MenuState::render()
{
	m_menu.render();
}