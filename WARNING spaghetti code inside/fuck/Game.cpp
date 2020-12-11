#include "Game.h"
#include <iostream>

// Game::Game() : mWindow(sf::VideoMode(640, 480), "SFML Application")
// {
// 	mBgTexture.loadFromFile("./Resources/Desert.png");
// 	mBackground.setTexture(mBgTexture);
// 	mBackground.setPosition(0, 0);
// }

// Game::Game(int x, int y, std::string title, std::string path) : mWindow(sf::VideoMode(x, y), title)
// {
// 	mPTexture.loadFromFile(path);
// 	mPlayer.setTexture(mPTexture);
// 	mPlayer.setPosition(10.0f, 10.0f);
// 	mBgTexture.loadFromFile("./Resources/Desert.png");
// 	mBackground.setTexture(mBgTexture);
// 	mBackground.setPosition(0, 0);
// }

// void Game::handleInput(sf::Keyboard::Key)
// {

// }

// void Game::processEvents()
// {
// 	sf::Event event;
// 	while (mWindow.pollEvent(event))
// 	{
// 		switch (event.type)
// 		{
// 		case sf::Event::KeyPressed:
// 			handleInput(event.key.code);
// 			break;
// 		case sf::Event::Closed:
// 			mWindow.close();
// 			break;
// 		}
// 	}
// }

// void Game::update()
// {

// }

// void Game::render()
// {
// 	mWindow.clear();
// 	mWindow.draw(mBackground);
// 	mWindow.draw(mPlayer);
// 	mWindow.display();
// }

// void Game::run()
// {
// 	while (mWindow.isOpen())
// 	{
// 		processEvents();
// 		update();
// 		render();
// 	}
// }

Player::Player(std::string name, int uA, int cD, int sT)
{
	mBaseAttr = getBaseAttr();
	mName = name;
	setAllSkills(uA, cD, sT);
}

Player::Player(std::string name)
{
	mBaseAttr = getBaseAttr();
	mName = name;
	setAllSkills();
}

void Player::setSkill(int& skillType, int value)
{
	skillType = value;
}

std::string Player::getName() const
{
	return mName;
}

int Player::getUnarmedAttack() const
{
	return mUnarmedAttack;
}

int Player::getDefense() const
{
	return mDefense;
}

int Player::getThievery() const
{
	return mThievery;
}

void Player::setAllSkills()
{
	using namespace std;
	int skillPointsLeft = 20;
	int spUnarmed, spDefense, spThievery;
	cout << "You have a total of 20 Skill points\nUse them wisely." << endl;
	do {
	if(skillPointsLeft < 0) 
	{
		cout << "try again, too many points allocated";
		skillPointsLeft = 20;
	}
	cout << "Give points for unarmed attack: ";
	cin >> spUnarmed;
	skillPointsLeft -= spUnarmed;
	cout << "Give points for melee attack: ";
	cin >> spDefense;
	skillPointsLeft -= spDefense;
	cout << "Give points for melee attack: ";
	cin >> spThievery;
	skillPointsLeft -= spThievery;
	} while(skillPointsLeft < 0);

	mUnarmedAttack = mBaseAttr - 10 + spUnarmed;
	mDefense = mBaseAttr - 10 + spDefense;
	mThievery = mBaseAttr - 10 + spThievery;
	HP = 10 + mDefense;
	isBot = false;
}


void Player::setAllSkills(int spUnarmed, int spDefense, int spThievery)
{
	mUnarmedAttack = mBaseAttr - 10 + spUnarmed;
	mDefense = mBaseAttr - 10 + spDefense;
	mThievery = mBaseAttr - 10 + spThievery;
	HP = 10 + mDefense;
	isBot = true;
}


int Player::getRoll()
{
	srand(time(NULL));
	int value = (rand() % 20) + 1;
	std::cout << mName << " rolls a " << value << "!" << std::endl;
	return value;
}

bool Player::dealDamage(int damageDealt)
{
	if(mHP > 0)
	{
		mHP -= damageDealt;
		return false;
	} else
	{
		return true; // game over scenario
	}
	
}

bool Player::getBot() const
{
	return isBot;
}