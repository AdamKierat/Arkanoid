#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace std;
using namespace sf;
class Paddle : public Drawable
{
public:
	Paddle(float x, float y);
	Paddle() = delete;
	~Paddle(); = default;

	void update();
private:

	void draw(RenderTarget& target, RenderStates state) const override;
	RectangleShape rectangle;

	const float paddleWidth{ 70.0f };
	const float paddleHeight{ 20.0f };
	const float paddleMovement{ 6.0f };

	Vector2f speed{ paddleMovement,0.f };

};

