#include "Head.h"

Head::Head(float startX, float startY) {
	this->position.x = startX;
	this->position.y = startY;
	this->shape.setFillColor(Color::Black);
	this->shape.setSize(Vector2f(10,10));
	this->shape.setPosition(position);
	this->inside.setSize(Vector2f(8,8));
	this->inside.setFillColor(Color::White);
	this->inside.setPosition(Vector2f(position.x + 2, position.y + 2));
	direction = (rand() % 2) + 1;
}

void Head::move() {
	Vector2f unit(2, 2);
	switch (direction) {
		case 0: position.y -= this->moveDistance;
			break;
		case 1: position.x += this->moveDistance;
			break;
		case 2: position.y += this->moveDistance;
			break;
		case 3: position.x -= this->moveDistance;
			break;
	}
	this->shape.setPosition(this->position);
	this->inside.setPosition(position + unit);
}

RectangleShape Head::getInside() {
	return inside;
}

RectangleShape Head::getShape() {
	return this->shape;
}

FloatRect Head::getBounds() {
	return shape.getGlobalBounds();
}