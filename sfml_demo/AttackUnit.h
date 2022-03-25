#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
class AttackUnit
{
public:
	AttackUnit(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	~AttackUnit();

	void Update(float, bool);
	void Draw(sf::RenderWindow& window);
	sf::Vector2f getPosition();
private:
	sf::RectangleShape body;
	Animation animation;
	unsigned int row;
	float speed;
	bool faceRight;
	

	bool jumping;
	float velocity;
	float gravity;
};

