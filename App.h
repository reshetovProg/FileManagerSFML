#pragma once
#include <SFML/Graphics.hpp>
#include "UI.h"
#include "NavWindow.h"
#include "Config.h"


class App
{
private:
	sf::RenderWindow window;
	UI buttons;
	NavWindow navLeft;
	NavWindow navRight;

public:
	App();
	void run();
private:
	void render();
	void processEvent();
	void update();
	void moveElement();
	void copyElement();
	void removeElement();
	


};

