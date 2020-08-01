// iD Tech Game Plan - SFML Template

#include "essentials.h"
#include "Segment.h"
#include "Head.h"
#include "Apple.h"

/* DEFINE GAMESTATES HERE */

int main()
{
	// Create a Window to Display Graphics, Define Size and Window Name
	sf::RenderWindow window(sf::VideoMode(500, 200), "Snake");
	float horizPositions = floorf(window.getSize().x / 10);
	float vertPositions = floorf(window.getSize().y / 10);

	Font candal;
	candal.loadFromFile("Font/Candal.ttf");

	int points = 0;

	Text label;
	label.setString("Points : " + to_string(points));
	label.setFont(candal);
	label.setCharacterSize(20);
	label.setPosition(5,5);
	label.setFillColor(Color::Magenta);

	Clock timer;
	float time = 0;

	/* CREATE OBJECTS AND ASSIGN OBJECT ATTRIBUTES HERE */

	Head snakeHead(0,0);
	vector<Segment> tail;
	Segment firstSeg(0,0);
	tail.push_back(firstSeg);

	Apple apple;
	apple.newPosition(tail, snakeHead, horizPositions, vertPositions);
	/* DEFINE VARIABLES HERE */

	// Run the Program while the Window is Open
	while (window.isOpen())
	{
		
		for (int j = 0; j < tail.size(); j++) {
			if (tail[j].getBounds().intersects(snakeHead.getBounds()) && points > 0) {
				cout << "Reseting" << endl;
				Head temp(0, 0);
				snakeHead = temp;
				vector<Segment> tempTail;
				tail = tempTail;
				Segment tempSeg(0, 0);
				firstSeg = tempSeg;
				tail.push_back(firstSeg);
				apple.newPosition(tail, snakeHead, horizPositions, vertPositions);
				points = 0;
				label.setString("Points : " + to_string(points));
				break;
			}
		}

		sf::Event event;
		while (window.pollEvent(event))
		{
			// When X Button Clicked, Close Window
			if (event.type == sf::Event::Closed)
				window.close();

			/* DEFINE EVENTS (i.e. KEY PRESS & RELEASE) HERE */

			if ((Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up)) && snakeHead.direction != 2) {
				snakeHead.direction = 0;
			}
			else if ((Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left)) && snakeHead.direction != 1) {
				snakeHead.direction = 3;
			}
			else if ((Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::Down)) && snakeHead.direction != 0) {
				snakeHead.direction = 2;
			}
			else if ((Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right)) && snakeHead.direction != 3) {
				snakeHead.direction = 1;
			}
		}

		/* DEFINE ACTIONS (i.e. MOVEMENT) HERE */
		if (snakeHead.getBounds().intersects(apple.getBounds())) {
			cout << "Hit Apple" << endl;
			apple.newPosition(tail, snakeHead, horizPositions, vertPositions);
			Segment temp(tail[tail.size() - 1].position.x, tail[tail.size() - 1].position.y);
			tail.push_back(temp);
			points++;
			label.setString("Points : " + to_string(points));
		}

		time = timer.getElapsedTime().asSeconds();
		if (time >= .1) {
			if (tail.size() > 0) {
				for (int i = tail.size() - 1; i > 0; i--) {
					if (i == 0) {
						if (tail[i].position == snakeHead.position) {
							continue;
						}
						tail[i].move(tail[i - 1].position);
						continue;
					}
					if (tail[i].position == tail[i - 1].position) {
						continue;
					}
					tail[i].move(tail[i - 1].position);
				}
				tail[0].move(snakeHead.position);
			}
			snakeHead.move();
			timer.restart();
		}

		

		if (snakeHead.position.x < 0 || snakeHead.position.x > window.getSize().x - 10 || snakeHead.position.y < 0 || snakeHead.position.y > window.getSize().y - 10) {
			Head temp(0, 0);
			snakeHead = temp;
			vector<Segment> tempTail;
			tail = tempTail;
			Segment tempSeg(0, 0);
			firstSeg = tempSeg;
			tail.push_back(firstSeg);
			apple.newPosition(tail, snakeHead, horizPositions, vertPositions);
		}
		
		
		window.clear(Color::Green);
		window.draw(snakeHead.getShape());
		window.draw(snakeHead.getInside());
		for (Segment seg : tail) {
			window.draw(seg.getShape());
			window.draw(seg.getInside());
		}
		window.draw(apple.getShape());
		window.draw(label);
		window.display();
	}
}