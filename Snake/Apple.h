#pragma once
#include "essentials.h"
#include "Segment.h"
#include "Head.h"
class Apple
{
public:
	Apple();
	void newPosition(vector<Segment> tail, Head head, float horizPositions, float vertPositions);
	bool checkCollisions(vector<Segment> tail, Head head, Vector2f tempPosition);
	RectangleShape getShape();
	FloatRect getBounds();
	Vector2f getPosition();
private:
	Vector2f position;
	RectangleShape shape;
};

