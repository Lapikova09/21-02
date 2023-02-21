#pragma once
#include <SFML/Graphics.hpp>
#include "settings.h"
struct Can {
	sf::Texture texture;
	sf::Sprite sprite;
	float speedY;
	float speedX;
};
void respawncan(Can& can) {
	sf::Vector2f first{ 150.f, -1150.f };
	sf::Vector2f second{ 200.f, -655.f };
	sf::Vector2f third{ 250.f, -1570.f };
	sf::Vector2f fourth{ 300.f, -450.f };
	int choice = rand() % 4 + 1;
	if (choice == 1) { can.sprite.setPosition(first); }
	else if (choice == 2) { can.sprite.setPosition(second); }
	else if (choice == 3) { can.sprite.setPosition(third); }
	else if (choice == 4) { can.sprite.setPosition(fourth); }
}

void canInit(Can& can) {
	can.texture.loadFromFile("can.png");
	can.sprite.setTexture(can.texture);
	respawncan(can);
	can.speedY = 3.f;
	can.speedX = 0.f;
}
void canUpdate(Can& can) {
	can.sprite.move(can.speedX, can.speedY);
	if (can.sprite.getPosition().y >= WINDOW_HEIGHT + 100.f) {
		respawncan(can);
	}
}
void canDraw(sf::RenderWindow& window, const Can& can) {
	window.draw(can.sprite);
}
