#include "App.h"

App::App():
	window(sf::VideoMode(WINDOW_W, WINDOW_H), "SFML window"),
	navLeft(sf::Vector2f(0,0), sf::Vector2f(350,600)),
	navRight(sf::Vector2f(450, 0), sf::Vector2f(350, 600))
{
	
}

void App::run()
{
	while (window.isOpen()) {
		processEvent();
		update();
		render();
	}

}

void App::render()
{

	window.clear();
	navLeft.render(window);
	navRight.render(window);
	window.display();

}

void App::processEvent()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
		navLeft.processEvent(event, window);
		navRight.processEvent(event, window);

		

	}

}

void App::update()
{

	

}

void App::moveElement()
{
}

void App::copyElement()
{
}

void App::removeElement()
{
}
