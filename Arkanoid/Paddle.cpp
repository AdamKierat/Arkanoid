#include "Paddle.h"



Paddle::Paddle(float x,float y)
{
	rectangle.setPosition(x, y);
	rectangle.setSize({ this->paddleWidth,this->paddleHeight });
	rectangle.setFillColor(Color::Yellow);
	rectangle.setOrigin(paddleWidth / 2.f, paddleHeight / 2.f);

}

void Paddle::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->rectangle, state);
}

void Paddle::update()
{
	this->rectangle.move(this->speed);
	if (Keyboard::isKeyPressed(Keyboard::Key::Left) && this->left() > 0)
	{
		speed.x = -paddleMovement;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Right) && this->right() < 800)
	{
		speed.x = paddleMovement;
	}
	else
	{
		speed.x = 0;
	}

}

float Paddle::left()
{
	return this->rectangle.getPosition().x - rectangle.getSize().x / 2.f;
}
float Paddle::right()
{
	return this->rectangle.getPosition().x + rectangle.getSize().x / 2.f;
}
float Paddle::top()
{
	return this->rectangle.getPosition().y - rectangle.getSize().y / 2.f;
}
float Paddle::bottom()
{
	return this->rectangle.getPosition().y + rectangle.getSize().y / 2.f;
}

Vector2f Paddle::getPosition()
{
	return rectangle.getPosition();
}