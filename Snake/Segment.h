#pragma once
#include "essentials.h"
class Segment
{
public:
	Segment(float startX, float startY);
	RectangleShape getShape();
	FloatRect getBounds();
	void move(Vector2f newPosition);
	Vector2f position;
	RectangleShape getInside();

private:
	RectangleShape segShape;
	RectangleShape inside;
};

