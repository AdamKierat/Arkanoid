#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Ball.h"

using namespace std;
using namespace sf;

int const WindowSizeWidth = 800;
int const WindowSizeHeight = 600;


int main()
{
	Ball ball(400, 300);
	RenderWindow window(VideoMode(WindowSizeWidth, WindowSizeHeight), "Arkanoid-Game");
	window.setFramerateLimit(60);

	Event event;
	while (1) {
		window.clear(Color::Black);
		window.pollEvent(event);

		if (event.type == Event::Closed)
		{
			window.close();
			break;
		}
		ball.update();
		window.draw(ball); 
		window.display();
	}
	return 0;
}