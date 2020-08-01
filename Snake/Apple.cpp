#include "Apple.h"

Apple::Apple() {
	position.x = 0;
	position.y = 0;
	shape.setFillColor(Color::Red);
	shape.setSize(Vector2f(10, 10));
	shape.setPosition(position);
}

void Apple::newPosition(vector<Segment> tail, Head head, float horizPositions, float vertPositions) {
	Vector2f newPos;
	do {
		newPos.x = fmodf(rand(), horizPositions) * 10;
		newPos.y = fmodf(rand(), vertPositions) * 10;
		shape.setPosition(newPos);
	} while (!checkCollisions(tail, head, newPos));
	cout << "Apple Position : " << shape.getPosition().x << ", " << shape.getPosition().y << endl;
}

RectangleShape Apple::getShape() {
	return shape;
}

FloatRect Apple::getBounds() {
	return shape.getGlobalBounds();
}

Vector2f Apple::getPosition() {
	return position;
}

bool Apple::checkCollisions(vector<Segment> tail, Head head, Vector2f tempPosition) {
	shape.setPosition(tempPosition);
	if (head.getBounds().intersects(shape.getGlobalBounds())) {
		return false;
	}
	for (int i = 0; i < tail.size(); i++) {
		if (tail[i].getBounds().intersects(shape.getGlobalBounds())) {
			return false;
		}
	}
	return true;
}
