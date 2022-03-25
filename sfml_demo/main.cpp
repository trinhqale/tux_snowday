#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Player.h"
#include "AttackUnit.h"
#include <vector>
#include <string>
static const float VIEW_HEIGHT = 288.0f;
static const float VIEW_WIDTH = 512.0f;

void ResizeView(sf::RenderWindow& window, sf::View& view)
{
    float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
    if(aspectRatio > 1.0f)
        view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
    else
        view.setSize(VIEW_WIDTH, VIEW_WIDTH * aspectRatio);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(512, 288), "SFML demo");
    sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_WIDTH, VIEW_HEIGHT));
    //sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));
    //player.setPosition(200.0f, 200.0f);
    sf::Texture unitTexture;
    sf::Texture bgTexture;
    bgTexture.loadFromFile("bg2.png");
    unitTexture.loadFromFile("tux.png");
    int score = 0;
    sf::Text scoreText;
    sf::Font font;
    font.loadFromFile("walkthemoon.ttf");
    scoreText.setFont(font);
    scoreText.setString("Score: 0");
    //scoreText.setCharacterSize()
    scoreText.setFillColor(sf::Color::Black);
    //player.setTexture(&playerTexture);
    sf::Sprite sprite;
    sprite.setTexture(bgTexture);
    sprite.setPosition(0, 0);
    //Player player(&playerTexture, sf::Vector2u(3, 4), 0.3f);

    /*textureSize.x /= 3;
    sf::Vector2u textureSize = playerTexture.getSize();
    textureSize.y /= 4;
    player.setTextureRect(sf::IntRect(playerTexture * 2, textureSize.y * 2, textureSize.x, textureSize.y));
    */

    float deltaTime = 0.0f;
    sf::Clock clock;
    
    AttackUnit unit(&unitTexture, sf::Vector2u(3, 9), 0.3f, 100.0f);
    while (window.isOpen())
    {
        sf::Event event;
        deltaTime = clock.restart().asSeconds();
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::Resized)
                ResizeView(window, view);
        }
        //if (move4ever)
          //  player.move(0.1f, 0.0f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            score++;
        
        //animation.Update(row, deltaTime, false);
        //player.setTextureRect(animation.uvRect);
        std::string str = "Score: ";
        str += std::to_string(score);
        scoreText.setString(str);
        view.setCenter(256.5f, 144.5f);
        window.clear(sf::Color::Black);
        //update + draw
        unit.Update(deltaTime, false);
        window.draw(sprite);
        window.setView(view);
        unit.Draw(window);
        window.draw(scoreText);
        window.display();
    }

    return 0;
}