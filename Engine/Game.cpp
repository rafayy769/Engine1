#include "Game.h"
#include <iostream>

Game::Game() : mWindow(sf::VideoMode(640, 480), "SFML Application")
{
	mBgTexture.loadFromFile("./Resources/Desert.png");
	mBackground.setTexture(mBgTexture);
	mBackground.setPosition(0, 0);
}

Game::Game(int x, int y, std::string title, std::string path) : mWindow(sf::VideoMode(x, y), title)
{
	mPTexture.loadFromFile(path);
	mPlayer.setTexture(mPTexture);
	mPlayer.setPosition(10.0f, 10.0f);
	mBgTexture.loadFromFile("./Resources/Desert.png");
	mBackground.setTexture(mBgTexture);
	mBackground.setPosition(0, 0);
}

void Game::handleInput(sf::Keyboard::Key)
{

}

void Game::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			handleInput(event.key.code);
			break;
		case sf::Event::Closed:
			mWindow.close();
			break;
		}
	}
}

void Game::update()
{

}

void Game::render()
{
	mWindow.clear();
	mWindow.draw(mBackground);
	mWindow.draw(mPlayer);
	mWindow.display();
}

void Game::run()
{
	while (mWindow.isOpen())
	{
		processEvents();
		update();
		render();
	}
}