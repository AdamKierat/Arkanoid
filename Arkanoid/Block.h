#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace std;
using namespace sf;
class Block: public Drawable
{
public:
	Block(float x,float y,float width,float height);
	Block() = delete;
	~Block() = default;

	void update();
	Vector2f getPosition();

	float left();
	float right();
	float top();
	float bottom();

	bool isDestroyed();
	void destroy();
	
	Vector2f getSize();

private:
	virtual void draw(RenderTarget& target, RenderStates states) const override;
	RectangleShape rectangleblock;
	bool destroyed{ false };

};

