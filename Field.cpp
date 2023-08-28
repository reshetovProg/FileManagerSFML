#include "Field.h"
#include "config.h"



Field::Field(sf::Vector2f size, sf::Vector2f position, sf::Color colorBack, sf::Color colorFont, int fontSize) :
	rectangle(size)
{
	this->active = false;
	this->colorBack = colorBack;
	this->colorFont = colorFont;
	this->fontSize = fontSize;
	this->position = position;
	rectangle.setFillColor(colorBack);
	rectangle.setPosition(position);
	text.setFillColor(colorFont);
	text.setCharacterSize(fontSize);
	text.setPosition(position.x+10, position.y + BUTTON_SIZE / 2 - fontSize / 2);





}

void Field::render(sf::RenderWindow& window)
{
	window.draw(rectangle);
	text.setFont(font);
	font.loadFromFile("arial.ttf");
	window.draw(text);


}

void Field::setText(std::string str)
{
	this->text.setString(str);
	this->str = str;
}

std::string Field::getText()
{
	return str;
}

void Field::changeBackColor(sf::Color colorBack)
{
	rectangle.setFillColor(colorBack);
}

void Field::setFontColor(sf::Color color)
{
	this->colorFont = color;
	text.setFillColor(color);
}

sf::RectangleShape& Field::getRectangle()
{
	return rectangle;
}

sf::Color Field::getFontColor()
{
	return colorFont;
}

sf::Color Field::getBackColor()
{
	return rectangle.getFillColor();
}

bool Field::getActive()
{
	return active;
}

void Field::setActive(bool status)
{
	active = status;
	(!active)?rectangle.setFillColor(colorBack):rectangle.setFillColor(sf::Color::Magenta);
	
}
