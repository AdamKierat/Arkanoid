#include "Block.h"
using namespace std;
using namespace sf;
int points = 0;

Block::Block(float x,float y,float width,float height)
{
	rectangleblock.setPosition(x, y);
	rectangleblock.setSize({ width,height });
	rectangleblock.setFillColor(Color::Green);
	rectangleblock.setOrigin(width / 2.f, height / 2.f);
}

void Block::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->rectangleblock, state);
}

float Block ::left()
{
	return this->rectangleblock.getPosition().x - rectangleblock.getSize().x / 2.f;
}
float Block::right()
{
	return this->rectangleblock.getPosition().x + rectangleblock.getSize().x / 2.f;
}
float Block::top()
{
	return this->rectangleblock.getPosition().y - rectangleblock.getSize().y / 2.f;
}
float Block::bottom()
{
	return this->rectangleblock.getPosition().y + rectangleblock.getSize().y / 2.f;
}

Vector2f Block::getPosition()
{
	return rectangleblock.getPosition();
}

bool Block::isDestroyed() {

	return this->destroyed;
}
void Block::destroy()
{
	this->destroyed = true;
}
Vector2f Block::getSize()
{
	return rectangleblock.getSize();
}

void Block::update() 
{

}
