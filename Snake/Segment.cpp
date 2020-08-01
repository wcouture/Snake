#include "Segment.h"

Segment::Segment(float startX, float startY) {
	position.x = startX;
	position.y = startY;
	segShape.setFillColor(Color::Black);
	segShape.setSize(Vector2f(10,10));
	segShape.setPosition(position);
	this->inside.setSize(Vector2f(8, 8));
	this->inside.setFillColor(Color::White);
	this->inside.setPosition(Vector2f(position.x + 2, position.y + 2));
}

RectangleShape Segment::getShape() {
	return segShape;
}

RectangleShape Segment::getInside() {
	return inside;
}

FloatRect Segment::getBounds() {
	return segShape.getGlobalBounds();
}

void Segment::move(Vector2f newPosition) {
	position = newPosition;
	segShape.setPosition(newPosition);
	Vector2f unit(2, 2);
	this->inside.setPosition(position + unit);
}




