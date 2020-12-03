#include "Game.h"
#include <iostream>

Game::Game() : mWindow(sf::VideoMode(1080, 720), "SFML Application")
{
}

Game::Game(int x, int y, std::string title, std::string path) : mWindow(sf::VideoMode(x, y), title)
{
	mTexture.loadFromFile(path);
	mPlayer.setTexture(mTexture);
	mPlayer.setPosition(10.0f, 10.0f);
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