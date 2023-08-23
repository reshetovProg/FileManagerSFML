#include "Button.h"

Button::Button(sf::Vector2f size, sf::Vector2f position, sf::Color colorBack, sf::Color colorFont, int fontSize):
	rectangle(size)
{
	this->colorFont = colorFont;
	this->fontSize = fontSize;
	rectangle.setFillColor(colorBack);
	rectangle.setPosition(position);
	rectangle.setOutlineColor(colorFont);
	rectangle.setOutlineThickness(2);


}

void Button::render(sf::RenderWindow &window)
{
	window.draw(rectangle);

	sf::Font font;
	text.setFont(font);
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(24);
	text.setPosition(position.x - 50, position.y - 50);
	text.setString("0");

	window.draw(text);

}

void Button::setText(std::string str)
{
	this->text.setString(str);
}

void Button::changeBackColor(sf::Color colorBack)
{
	rectangle.setFillColor(colorBack);
}
