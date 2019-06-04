#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#define MAX_NUMBER_OF_ITEMS 2

using namespace sf;
class Gameover
{
public:
	Gameover(float width, float height);
	~Gameover();

	void draw(RenderWindow &gamemoverWindow);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }

private:
	int selectedItemIndex;
	Font font;
	Text gameover[MAX_NUMBER_OF_ITEMS];

};

