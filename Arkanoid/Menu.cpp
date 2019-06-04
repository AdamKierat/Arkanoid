#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#define SFML_NO_DEPRECATED_WARNINGS



Menu::Menu(float width,float height)
{
	if (!font.loadFromFile("times.TTF"))
	{
		//handle error
	}
	menu[0].setFont(font);
	menu[0].setFillColor(Color::Red);
	menu[0].setString("Start Game");
	menu[0].setPosition(Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS +1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(Color::White);
	menu[1].setString("Set level");
	menu[1].setPosition(Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(Color::White);
	menu[2].setString("Exit game");
	menu[2].setPosition(Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

}


Menu::~Menu()
{
}

void Menu :: draw(RenderWindow &menuWindow)
{
	for(int i = 0;i < MAX_NUMBER_OF_ITEMS;i ++)
	{
		menuWindow.draw(menu[i]);
	}

}
