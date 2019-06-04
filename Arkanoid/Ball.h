#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;
class Ball : public Drawable
{
public:
	Ball(float x, float y);
	Ball() = delete;
	~Ball() = default;

	void update();

	void moveUp();
	void moveLeft();
	void moveRight();
	void moveBottom();

	bool isOutside();

	Vector2f getPosition();

	float left();
	float right();
	float bottom();
	float top();
private:
	CircleShape circle;
	const float ballRadius{ 10.0f };
	const float ballMovement{ 5.0f };
	Vector2f speed{ ballMovement,ballMovement };


	void draw(RenderTarget& target, RenderStates state) const override;

};

