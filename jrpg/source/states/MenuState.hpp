///
/// MenuState.hpp
/// jrpg
/// See License.txt
///

#ifndef JRPG_MENUSTATE_HPP_
#define JRPG_MENUSTATE_HPP_

#include <sl/ui/UI.hpp>
#include <sl/mapping/TiledMap.hpp>
#include <sl/core/StateMachine.hpp>

class MenuState : public sl::State
{
public:
	MenuState();
	~MenuState() override;

	void load() override;
	void unload() override;

	void event(ALLEGRO_EVENT* event) override;
	void update(const double dt) override;
	void render() override;

private:
	sl::UI m_menu;
	sl::TiledMap m_map;
	sl::ThemeStorage m_themeStorage;
	sl::WidgetStorage m_widgetStorage;
};

#endif