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
	inputField.setText("lorem");
	
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

void NavWindow::processEvent(sf::Event event, sf::RenderWindow& window)
{
	if (event.type == sf::Event::MouseButtonPressed) {

		sf::Vector2f localPosition(event.mouseButton.x, event.mouseButton.y);

		if (inputField.getRectangle().getGlobalBounds().contains(localPosition)) {
			inputField.setActive(true);
		}
		else {
			inputField.setActive(false);
		}
	}
	if (inputField.getActive()) {
		if (event.type == sf::Event::TextEntered)
		{
			std::cout << "in type.event" << std::endl;
			if (event.KeyPressed)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
					inputField.setText(inputField.getText().erase(inputField.getText().size() - 1));
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
					inputField.setActive(false);
				}
				else {
					char buf = static_cast<char>(event.text.unicode);
					std::cout << buf<< std::endl;
					inputField.setText(inputField.getText() + buf);
				}
			}
		}
	}
	
}
