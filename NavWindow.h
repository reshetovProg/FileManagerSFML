#pragma once
#include <SFML/Graphics.hpp>
#include "Element.h"
#include "Field.h"
#include "InputField.h"
#include <vector>
class NavWindow
{
	Element* activeElement = nullptr;
	std::vector<Element> elements;

	sf::RectangleShape rectangle;
	sf::Font font;
	sf::Text text;
	sf::Vector2f position;
	sf::Vector2f size;
	int fontSize;

	InputField inputField;


public:
	NavWindow(sf::Vector2f position, sf::Vector2f size);
	void render(sf::RenderWindow& window);
	void removeElement();
	void addElement(Element);
	
};

