#include "AttackUnit.h"

AttackUnit::AttackUnit(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) : animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	velocity = 0.0f;
	gravity = 2.0f;
	faceRight = true;
	jumping = false;
	body.setSize(sf::Vector2f(50.0f, 50.0f));
	//body.setOrigin(0.0f, 0.0f);
	
	body.setPosition(0.0f, 230.0f);
	body.setTexture(texture);
}

AttackUnit::~AttackUnit()
{
}


void AttackUnit::Update(float deltaTime, bool stay)
{
	sf::Vector2f movement;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
		movement.x -= speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		movement.x += speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && !jumping) // jump
	{
		velocity = -400.0f;
		gravity = 1000.0f;
		jumping = true;
	}
	movement.y = velocity ;
	velocity += gravity * deltaTime;
	
	if (movement.x == 0.0f)
		row = 0;
	else
	{
		row = 4;
		if (movement.x > 0.0f)
			faceRight = true;
		else
			faceRight = false;
	}
	if (jumping)
		row = 7;
	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(movement * deltaTime);
	if (getPosition().y >= 230.0f)
	{
		body.setPosition(getPosition().x, 230.0f);
		jumping = false;
	}
	if (getPosition().x < -1.0f)
		body.setPosition(472.0f, getPosition().y);
	else if (getPosition().x > 472.0f)
		body.setPosition(-1.0f, getPosition().y);

}

void AttackUnit::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

sf::Vector2f AttackUnit::getPosition()
{
	return body.getPosition();
}
