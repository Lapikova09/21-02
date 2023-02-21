#pragma once
#include <SFML/Graphics.hpp>
#include "settings.h"
struct RoadObj {
	sf::Texture texture;
	sf::Sprite sprite;
	float speedY;
	float speedX;
};
void roadObjInit(RoadObj& obj, sf::Vector2f pos, std::string filename) {
	obj.texture.loadFromFile(filename);
	obj.sprite.setTexture(obj.texture);
	obj.sprite.setPosition(pos);
	obj.speedY = 3.f;
	obj.speedX = 0.f;
}
void roadObjUpdate(RoadObj& obj, sf::Vector2f pos) {
	obj.sprite.move(obj.speedX, obj.speedY);
	if (obj.sprite.getPosition().y >= WINDOW_HEIGHT) {
		obj.sprite.setPosition(pos);
	}
}

void roadObjDraw(sf::RenderWindow& window, const RoadObj& obj) {
	window.draw(obj.sprite);
}

