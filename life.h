#pragma once
#include <SFML/Graphics.hpp>
#include "settings.h"
struct Life {
	sf::Texture texture;
	sf::Sprite sprite;
};
void LifeInit(Life& life, sf::Vector2f pos) {
	life.texture.loadFromFile("life.png");
	life.sprite.setTexture(life.texture);
	life.sprite.setPosition(pos);
}
void LifeUpdate(Life& life) {

}
void LifeDraw(sf::RenderWindow& window, const Life& life) {
	window.draw(life.sprite);
}

