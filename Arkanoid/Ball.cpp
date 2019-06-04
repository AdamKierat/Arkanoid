#include "Ball.h"


Ball::Ball(float x,float y)
{
	circle.setPosition(x, y);
	circle.setRadius(this->ballRadius);
	circle.setFillColor(Color::White);
	circle.setOrigin(this->ballRadius, this->ballRadius);
}

void Ball::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->circle, state);
}

void Ball::update() 
{
	circle.move(this->speed);
	
	if (this->left() < 0)
	{
		speed.x = ballMovement;
	}
	else if (this->right() > 800) // width
	{
		speed.x = -ballMovement;
	}
	else if (this->top() < 0) 
	{
		speed.y = ballMovement;
	}
	else if (this->bottom() > 600) // height
	{
		speed.y = -ballMovement;
	}
}

float Ball::left()
{
	return this->circle.getPosition().x - circle.getRadius();
}
float Ball::right()
{
	return this->circle.getPosition().x + circle.getRadius();
}
float Ball::top()
{
	return this->circle.getPosition().y - circle.getRadius();
}
float Ball::bottom()
{
	return this->circle.getPosition().y + circle.getRadius();
}
