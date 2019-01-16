///
/// LoadState.hpp
/// jrpg
/// See License.txt
///

#ifndef JRPG_LOADSTATE_HPP_
#define JRPG_LOADSTATE_HPP_

#include <sl/core/StateMachine.hpp>

class LoadState : public sl::State
{
public:
	LoadState();
	~LoadState() override;

	void load() override;
	void unload() override;

	void event(ALLEGRO_EVENT* event) override;
	void update(const double dt) override;
	void render() override;
};

#endif