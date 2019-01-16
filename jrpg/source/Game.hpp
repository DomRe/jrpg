///
/// Game.hpp
/// jrpg
/// See License.txt
///

#include <sl/core/Application.hpp>

#ifndef JRPG_GAME_HPP_
#define JRPG_GAME_HPP_

class Game : public sl::Application
{
public:
	Game(const std::string& config, std::function<void(std::ofstream&)> newConfig);
};

#endif