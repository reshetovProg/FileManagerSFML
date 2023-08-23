#include "NavWindow.h"
#include "Config.h"

NavWindow::NavWindow(sf::Vector2f position, sf::Vector2f size):
	rectangle(size),
	inputField(
		sf::Vector2f(size.x, BUTTON_SIZE),
		position,
		sf::Color::Color(217, 217, 217, 255),
		sf::Color::Color(74, 74, 74, 255),
		24)
{
	rectangle.setFillColor(sf::Color::White);
	rectangle.setPosition(position);
	rectangle.setOutlineColor(sf::Color::Black);
	rectangle.setOutlineThickness(2);
	
}

void NavWindow::render(sf::RenderWindow& window)
{
	window.draw(rectangle);
	inputField.render(window);
}



void NavWindow::removeElement()
{
}

void NavWindow::addElement(Element)
{
}
