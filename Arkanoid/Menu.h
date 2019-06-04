#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#define MAX_NUMBER_OF_ITEMS 3

using namespace sf;
class Menu
{
public:
	Menu(float width,float height);
	~Menu();

	void draw(RenderWindow &menuWindow);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }

private:
	int selectedItemIndex;
	Font font;
	Text menu[MAX_NUMBER_OF_ITEMS];

};

