#pragma once
#include <SFML/Graphics.hpp>
#include "settings.h"
struct Brick {
	sf::RectangleShape shape;
	sf::Color color;
	sf::Vector2f position;
};
void brickInit(Brick& brick, sf::Vector2f position) {
	brick.position = position;
	brick.shape.setSize(BRICK_SIZE);
	brick.shape.setFillColor(sf::Color::Black);
	brick.shape.setPosition(brick.position);
	brick.shape.setOutlineThickness(1.f);
	brick.shape.setOutlineColor(sf::Color::White);
}
void brickUpdate(Brick& brick) {

}
void brickDraw(sf::RenderWindow& window, const Brick& brick) {
	window.draw(brick.shape);
}
