///
/// GameState.hpp
/// jrpg
/// See License.txt
///

#ifndef JRPG_GAMESTATE_HPP_
#define JRPG_GAMESTATE_HPP_

#include <sl/mapping/TiledMap.hpp>
#include <sl/core/StateMachine.hpp>

class GameState : public sl::State
{
public:
	GameState();
	~GameState() override;

	void load() override;
	void unload() override;

	void event(ALLEGRO_EVENT* event) override;
	void update(const double dt) override;
	void render() override;

private:
	sl::TiledMap m_map;
};

#endif