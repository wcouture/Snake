#pragma once
#include "essentials.h"

class Head
{
public:
	Vector2f position;
	int direction;
	Head(float startX, float startY);
	void move();
	RectangleShape getShape();
	FloatRect getBounds();
	RectangleShape getInside();

private:
	RectangleShape shape;
	RectangleShape inside;
	float moveDistance = 10;
};

