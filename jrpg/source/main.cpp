///
/// main.cpp
/// jrpg
/// See License.txt
///

#include <allegro5/allegro_native_dialog.h>

#include "Game.hpp"

int main(int argc, char **argv)
{
	bool restart = false;

	do
	{
		restart = false;

		{
			try
			{
				Game game("config.cfg", [](std::ofstream& newConfig)
				{
					newConfig << "[graphics]\n";
					newConfig << "width = 1280\n";
					newConfig << "height = 720\n";
					newConfig << "fullscreen = false\n";
					newConfig << "msaa = true\n";
					newConfig << "msaaValue = 2\n";
					newConfig << "grabMouse = true\n";
					newConfig << "title = JRPG\n";
					newConfig << "icon = icon.png\n";
					newConfig << "atlasPowerOf = 13\n";
					newConfig << "shaderScript = shaders.lua\n";
					newConfig << "nullTexture = null\n";
					newConfig << std::endl;

					newConfig << "[box2d]\n";
					newConfig << "gravity = 0.0\n";
					newConfig << "ups = 60.0\n";
					newConfig << "velocityIterations = 8\n";
					newConfig << "positionIterations = 3\n";
					newConfig << std::endl;

					newConfig << "[font]\n";
					newConfig << "fontScript = fonts.lua\n";
					newConfig << std::endl;

					newConfig << "[audio]\n";
					newConfig << "musicScript = music.lua\n";
					newConfig << "soundScript = sound.lua\n";
					newConfig << "reserveSamples = 32\n";
					newConfig << "nullMusic = null\n";
					newConfig << "nullSound = null\n";
					newConfig << std::endl;

					newConfig << "[fs]\n";
					newConfig << "writeDir = assets/\n";
					newConfig << "scriptFolderPath = scripts/\n";
					newConfig << "textureFolderPath = textures/\n";
					newConfig << "musicFolderPath = music/\n";
					newConfig << "soundFolderPath = sound/\n";
					newConfig << std::endl;

					newConfig << "[archives]\n";
					newConfig << "assets/";
					newConfig << std::endl;
				});

				restart = game.run();
			}
			catch (const std::exception& e)
			{
				LOG_S(INFO) << "EXCEPTION OUTPUT: " << e.what();
				al_show_native_message_box(nullptr, "Runtime Exception", "Error Message:", e.what(), nullptr, ALLEGRO_MESSAGEBOX_ERROR);
			}
			catch (...)
			{
				LOG_S(WARNING) << "Threw an unknown exception. Why are you not inheriting from std::exception?";
			}
		}

	} while (restart);

	return EXIT_SUCCESS;
}