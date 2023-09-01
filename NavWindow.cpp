#include "NavWindow.h"
#include <iostream>
#include "Config.h"
#include <filesystem>
namespace fs = std::filesystem;

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
	inputField.setText("C:/Users/Admin/Desktop/testcon");
	
	/*this->fields.push_back(Field(sf::Vector2f(size.x, BUTTON_SIZE),
		sf::Vector2f(position.x, position.y + (0 + 1) * (BUTTON_SIZE + 2)),
		sf::Color::Color(130, 78, 100, 255),
		sf::Color::Color(255, 255, 255, 255),
		24));
	this->fields[fields.size() - 1].setText("89898");*/
	
}



void NavWindow::render(sf::RenderWindow& window)
{
	window.draw(rectangle);
	inputField.render(window);
	for (auto el : fields) {
		el.getText();
		el.render(window);
	}
}



void NavWindow::removeField()
{
	for (int i = 0; i < fields.size(); i++) {
		if (fields[i].getActive()) {
			fields.erase(fields.begin() + i);
			break;
		}
	}
}

void NavWindow::addField(Field field)
{
}

void NavWindow::processEvent(sf::Event event, sf::RenderWindow& window)
{
	if (event.type == sf::Event::MouseButtonPressed) {

		sf::Vector2f localPosition(event.mouseButton.x, event.mouseButton.y);

		if (inputField.getRectangle().getGlobalBounds().contains(localPosition)) {
			inputField.setActive(true);
			activeText = inputField.getText();
		}
		else {
			inputField.setActive(false);
			activeText = "";
		}
		for (auto& x : fields) {

			if (x.getRectangle().getGlobalBounds().contains(localPosition)) {
				x.setActive(true);
				activeText = x.getText();
				break;
				//activeField = &x;

			}
			else {
				x.setActive(false);
				activeText = "";
			}
		}
	}
	if (inputField.getActive()) {
		if (event.type == sf::Event::TextEntered)
		{
			if (event.KeyPressed)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
					inputField.setText(inputField.getText().erase(inputField.getText().size() - 1));
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
					inputField.setActive(false);
					activeText = "";
				}
				else {
					char buf = static_cast<char>(event.text.unicode);
					inputField.setText(inputField.getText() + buf);
				}
			}
		}
	}

	
}

Field* NavWindow::getActiveField()
{
	return activeField;
}



void NavWindow::createFields(std::vector<std::string>& fieldTexts)
{
	/*std::string activeFieldPath = "";
	if(activeText !="")
		activeFieldPath = activeField->getText();*/
	fields.clear();

	for (const auto& text : fieldTexts) {
		
		Field newField(
			sf::Vector2f(rectangle.getSize().x, BUTTON_SIZE),
			sf::Vector2f(rectangle.getPosition().x, rectangle.getPosition().y + (fields.size() + 1) * (BUTTON_SIZE + 2)),
			sf::Color::Color(130, 78, 100, 255),
			sf::Color::Color(255, 255, 255, 255),
			24
		);
		if (text == activeText) {
			newField.setActive(true);
			//activeField = &newField;
		}
		newField.setText(text);
		fields.push_back(newField);
	}


	/*updateField();*/
}


void NavWindow::updateFields()
{
	if (!inputField.getActive()) {
		fs::path folderPath = inputField.getText(); // Текущая папка

		std::vector<std::string> fieldTexts;
		{
			for (const auto& entry : fs::directory_iterator(folderPath))
			{
				//!--------- вылетает исключение при изменении пути первичного
				if (entry.is_regular_file())
				{
					std::string filename = entry.path().filename().string();
					fieldTexts.push_back(filename);
				}

			}
		}
		createFields(fieldTexts);
	}
	
}



