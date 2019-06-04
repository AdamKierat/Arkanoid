#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Ball.h"
#include "Paddle.h"
#include "Block.h"
#include "Menu.h"
using namespace std;
using namespace sf;

int const WindowSizeWidth = 800;
int const WindowSizeHeight = 600;

template <class T1, class T2> bool isIntersecting(T1& A, T2& B)
{
	return A.right() >= B.left() && A.left() <= B.right() 
		&& A.bottom() >= B.top()&& A.top() <= B.bottom();
}

bool collisionTest(Paddle& paddle, Ball& ball)
{
	if (!isIntersecting(paddle, ball)) return false;

	ball.moveUp();

	if (ball.getPosition().x < paddle.getPosition().x)
	{
		ball.moveLeft();
	}
	else if (ball.getPosition().x > paddle.getPosition().x)
	{
		ball.moveRight();
	}

}
bool collisionTest(Block& block, Ball& ball)
{
	if (!isIntersecting(block, ball)) return false;
	block.destroy();

	float overlapLeft{ ball.right() - block.left() };
	float overlapRight{ block.right() - ball.left() };
	float overlapTop{ ball.bottom() - block.top() };
	float overlapBottom{ block.bottom() - ball.top() };

	bool ballFromLeft(abs(overlapLeft) < abs(overlapRight));
	bool ballFromTop(abs(overlapTop) < abs(overlapBottom));

	float minOverlapX{ ballFromLeft ? overlapLeft : overlapRight };
	float minOverlapY{ ballFromTop ? overlapTop : overlapBottom };

	if (abs(minOverlapX) < abs(minOverlapX))
	{
		ballFromLeft ? ball.moveLeft() : ball.moveRight();
	}
	else
	{
		ballFromTop ? ball.moveUp() : ball.moveBottom();
	}


}


void play_arkanoid() 
{
	Ball ball(400, 300);
	Paddle paddle(400, 550);

	RenderWindow window(VideoMode(WindowSizeWidth, WindowSizeHeight), "Arkanoid-Game");
	window.setFramerateLimit(60);
	unsigned blocksX{ 10 }, blocksY{ 5 }, blockWidth{ 60 }, blockHeight{ 20 };

	vector<Block> blocks;

	for (int i = 0; i < blocksY; i++)
	{
		for (int j = 0; j < blocksX; j++)
		{
			blocks.emplace_back((j + 1) *(blockWidth + 10), (i + 2)*(blockHeight + 2), blockWidth, blockHeight);
		}
	}
	Event eventgame;
	while (1) {
		window.clear(Color::Black);
		window.pollEvent(eventgame);

		if (eventgame.type == Event::Closed)
		{
			window.close();
			break;
		}
		ball.update();
		paddle.update();
		collisionTest(paddle, ball);

		for (auto& block : blocks) if (collisionTest(block, ball)) break;

		auto iterator = remove_if(begin(blocks), end(blocks), [](Block& block) {return block.isDestroyed(); });
		blocks.erase(iterator, end(blocks));

		window.draw(ball);
		window.draw(paddle);
		for (auto& block : blocks)
		{
			window.draw(block);
		}
		window.display();


	}
}

int main()
{
	RenderWindow menuWindow(VideoMode(800, 600), "MAIN MENU");
	Menu menu(menuWindow.getSize().x,menuWindow.getSize().y);
	menu.draw(menuWindow);

	while (menuWindow.isOpen())
	{
		Event menuevent;

		while (menuWindow.pollEvent(menuevent))
		{
			switch (menuevent.type)
			{
			case Event::KeyReleased:
				switch (menuevent.key.code)
				{
				case Keyboard::Up:
					menu.MoveUp();
					break;
				case Keyboard::Down:
					menu.MoveDown();
					break;
				case Keyboard::Return:
					switch (menu.GetPressedItem())
					{
					case 0:
						play_arkanoid();			//game
						break;
					case 1:
											//options
						break;
					case 2:
						menuWindow.close();
						break;
					}
					break;
				}
				break;
			case Event::Closed:
					menuWindow.close();
					break;
			}
		}
		menuWindow.clear();
		menu.draw(menuWindow);
		menuWindow.display();
	}

	return 0;
}