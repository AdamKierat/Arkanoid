#include "Paddle.h"



Paddle::Paddle(float x,float y)
{
	rectangle.setPosition(x, y);
	rectangle.setSize({ this->paddleWidth,this->paddleHeight });
	rectangle.setFillColor(Color::Yellow);
	rectangle.setOrigin(paddleWidth / 2.f, paddleHeight / 2.f);

}
