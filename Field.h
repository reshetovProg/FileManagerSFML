#pragma once
#include <SFML/Graphics.hpp>

class Field
{
	sf::RectangleShape rectangle;
	sf::Font font;
	sf::Text text;
	sf::Vector2f position;
	sf::Vector2f size;
	sf::Color colorFont;
	int fontSize;
public:
	Field(sf::Vector2f size, sf::Vector2f position, sf::Color colorBack, sf::Color colorFont, int fontSize);
	void render(sf::RenderWindow& window);
	void setText(std::string str);
	void changeBackColor(sf::Color colorBack);
	void setFontColor(sf::Color color);
	sf::RectangleShape& getRectangle();
	sf::Color getFontColor();
	sf::Color getBackColor();

};

