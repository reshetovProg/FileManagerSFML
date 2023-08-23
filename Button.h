#pragma once
#include <SFML/Graphics.hpp>
class Button
{
private:
	sf::RectangleShape rectangle;

	sf::Text text;
	sf::Vector2f position;
	sf::Vector2f size;
	sf::Color colorFont;
	int fontSize;

public:
	Button(sf::Vector2f size, sf::Vector2f position, sf::Color colorBack, sf::Color colorFont, int fontSize);
	void render(sf::RenderWindow &window);
	void setText(std::string str);
	void changeBackColor(sf::Color colorBack);

};

