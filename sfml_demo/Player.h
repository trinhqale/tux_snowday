#pragma once
#include "Animation.h";
#include <SFML/Graphics.hpp>
class Player
{
public: 
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	~Player();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);

private:
	sf::RectangleShape body;
	Animation animation;
	unsigned int row;
	float speed;
};

