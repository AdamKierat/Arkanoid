#include "Gameover.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#define SFML_NO_DEPRECATED_WARNINGS



Gameover::Gameover(float width, float height)
{
	if (!font.loadFromFile("resources/times.TTF"))
	{
		//handle error
	}
	gameover[0].setFont(font);
	gameover[0].setFillColor(Color::Red);
	gameover[0].setString("RESTART");
	gameover[0].setPosition(Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	gameover[1].setFont(font);
	gameover[1].setFillColor(Color::White);
	gameover[1].setString("EXIT GAME");
	gameover[1].setPosition(Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	selectedItemIndex = 0;
}


Gameover::~Gameover()
{
}

void Gameover::draw(RenderWindow &gameoverWindow)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		gameoverWindow.draw(gameover[i]);
	}

}

void Gameover::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		gameover[selectedItemIndex].setFillColor(Color::White);
		selectedItemIndex--;
		gameover[selectedItemIndex].setFillColor(Color::Red);
	}
}
void Gameover::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		gameover[selectedItemIndex].setFillColor(Color::White);
		selectedItemIndex++;
		gameover[selectedItemIndex].setFillColor(Color::Red);
	}
}
