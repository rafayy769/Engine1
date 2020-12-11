#pragma once
// #include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <time.h>

// class Game
// {
// 	sf::RenderWindow mWindow;
// 	sf::Texture mBgTexture;
// 	sf::Sprite mBackground;
// 	sf::Texture mPTexture;
// 	sf::Sprite mPlayer;

// 	enum State
// 	{
// 		PAUSED,
// 		NOT_PAUSED
// 	};

// 	void processEvents();
// 	void update();
// 	void render();
// 	void handleInput(sf::Keyboard::Key);

// public:
// 	Game();
// 	Game(int x, int y, std::string title, std::string path);

// 	void run();
// };

class Player
{
private:
	/* 0: Unarmed combat,
	   2: Defense, 3: Thievery
	*/
	std::string mName;
	int mUnarmedAttack, mDefense, mThievery;
	int mBaseAttr;
	int mHP;
	bool isBot = false;
	
	int getBaseAttr()
	{
		srand(time(NULL));
		return rand() % 16 + 3;
	}
public:
	bool defending = false;
	Player(std::string name, int uA, int cD, int sT);
	Player(std::string name);
	void setSkill(int& skillType, int value);
	int getUnarmedAttack() const;
	std::string getName() const;
	int getDefense() const;
	int getThievery() const;
	void setAllSkills();
	int getRoll();
	bool dealDamage(int damageDealt);
	//below method are for non player fighters
	void setAllSkills(int spUnarmed, int spDefense, int spThievery);
	bool getBot() const;
};

//console prototypes
bool isPlayer1First(Player p1, Player p2);
void fight(Player player1, Player player2);
void runBattle(Player p1, Player p2);
void printPhrase(int attackType, std::string attackerName);
void turn(Player attacker, Player defender, bool &gameStatus);

// row 0: failed attack; row 1: weak attack; row 2: strong attack 
std::string phrases[3][3] = {
	{
		" got confused and hit themself!",
		" forgot who they were punching so they punched themselves!",
		" wrote C++ code and went crazy enough to hit themselves!"
	},
	{
		" said something rude and did minimal damage!",
		" reminded their opponent of a forgotten assignment and did minimal damage!",
		" called their opponent an SSE student and did minimal damage!"
	},
	{
		" gave a strong upper-cut which did maximum damage!",
		" gave a strong jab to the head for maximum damage!",
		" punched their opponent hard enough for maximum damage!"
	}
}

