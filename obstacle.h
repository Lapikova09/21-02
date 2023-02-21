#pragma once
#include <SFML/Graphics.hpp>
#include "settings.h"
struct Obstacle {
	sf::Texture texture;
	sf::Sprite sprite;
	float speedY;
	float speedX;
};
void respawn(Obstacle& obs) {
	int choice1 = rand() % 5 + 1;
	if (choice1 == 1) { obs.texture.loadFromFile("obs.png"); }
	else if (choice1 == 2) { obs.texture.loadFromFile("caryellow.png"); }
	else if (choice1 == 3) { obs.texture.loadFromFile("carblue.png"); }
	else if (choice1 == 4) { obs.texture.loadFromFile("carwhite.png"); }
	else if (choice1 == 5) { obs.texture.loadFromFile("cargrey.png"); }
	sf::Vector2f first{ 150.f, -10.f };
	sf::Vector2f second{ 200.f, -10.f };
	sf::Vector2f third{ 250.f, -10.f };
	sf::Vector2f fourth{ 300.f, -10.f };
	int choice = rand() % 4 + 1;
	if (choice == 1) { obs.sprite.setPosition(first); }
	else if (choice == 2) { obs.sprite.setPosition(second); }
	else if (choice == 3) { obs.sprite.setPosition(third); }
	else if (choice == 4) { obs.sprite.setPosition(fourth); }
}

void obstacleInit(Obstacle& obs) {
	obs.texture.loadFromFile("car.png");
	obs.sprite.setTexture(obs.texture);
	respawn(obs);
	obs.speedY = 4.f;
	obs.speedX = 0.f;
}
void obstacleUpdate(Obstacle& obs) {
	obs.sprite.move(obs.speedX, obs.speedY);
	if (obs.sprite.getPosition().y >= WINDOW_HEIGHT + 100.f) {
		respawn(obs);
	}
}
void obstacleDraw(sf::RenderWindow& window, const Obstacle& obs) {
	window.draw(obs.sprite);
}
