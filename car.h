#pragma once
#include <SFML/Graphics.hpp>
#include "settings.h"
struct Car {
	sf::Texture texture;
	sf::Sprite sprite;
	float speedX;
	int score;
	int canscore;
};
void carInit(Car& car, sf::Vector2f pos, std::string filename) {
	car.texture.loadFromFile(filename);
	car.sprite.setTexture(car.texture);
	car.sprite.setPosition(pos);
	car.score = 3;
	car.canscore = 0;
}
void carControl(Car& car) {

	car.speedX = 0.f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		car.speedX = -CAR_SPEEDX;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		car.speedX = CAR_SPEEDX;
	}
	car.sprite.move(car.speedX, 0.f);
}
void carUpdate(Car& car) {
	carControl(car);
	if (car.sprite.getPosition().x < ROAD_POS.x) {
		car.sprite.setPosition(ROAD_POS.x, 600.f);
	}
	if (car.sprite.getPosition().x > ROAD_POS.x + 240.f) {
		car.sprite.setPosition(ROAD_POS.x + 240.f, 600.f);
	}
}
void carDraw(sf::RenderWindow& window, const Car& car) {
	window.draw(car.sprite);
}
