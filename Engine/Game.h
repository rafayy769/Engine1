#pragma once
#include <SFML/Graphics.hpp>

class Game
{
	sf::RenderWindow mWindow;
	sf::Texture mTexture;
	sf::Sprite mPlayer;

	enum State
	{
		PAUSED,
		NOT_PAUSED
	};

	void processEvents();
	void update();
	void render();
	void handleInput(sf::Keyboard::Key);

public:
	Game();
	Game(int x, int y, std::string title, std::string path);

	void run();
};