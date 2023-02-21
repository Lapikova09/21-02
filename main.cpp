#include <SFML/Graphics.hpp>
#include "settings.h"
#include "roadObj.h"
#include "car.h"
#include "obstacle.h"
#include "TextObj.h"
#include "Life.h"
#include "can.h"
#include "bricks.h"

using namespace sf;
enum GameState { PLAY, GAME_OVER, YOU_WIN };
int main()
{
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
		WINDOW_TITLE,
		Style::Titlebar | Style::Close);
	window.setFramerateLimit(FPS);
	window.setPosition(Vector2i{ (1920 - (int)WINDOW_WIDTH) / 2,0 });
	GameState gameState = PLAY;

	RoadObj road;
	roadObjInit(road, ROAD_POS, "froad.jpg");
	RoadObj grass;
	roadObjInit(grass, GRASS_POS, "frass.jpg");
	RoadObj road1;
	roadObjInit(road1, ROAD_POS1, "froad.jpg");
	RoadObj grass1;
	roadObjInit(grass1, GRASS_POS1, "frass.jpg");
	Car car;
	carInit(car, CAR_START_POS, "car.png");
	Obstacle obs;
	obstacleInit(obs);
	Textobj scoreText;
	TextobjInit(scoreText, std::to_string(car.score), TEXT_POS);
	Textobj scorecanText;
	TextobjInit(scorecanText, std::to_string(car.canscore), TEXT_POS1);
	Textobj gameOverText;
	TextobjInit(gameOverText, "GAME OVER", Vector2f{ (WINDOW_WIDTH - 275.f) / 2,(WINDOW_HEIGHT - 50.f) / 2 });
	Textobj youWinText;
	TextobjInit(youWinText, "YOU WIN", Vector2f{ (WINDOW_WIDTH - 250.f) / 2,(WINDOW_HEIGHT - 50.f) / 2 });
	Life life1;
	LifeInit(life1, LIFE1_POS);
	Life life2;
	LifeInit(life2, LIFE2_POS);
	Life life3;
	LifeInit(life3, LIFE3_POS);
	Brick brick1;
	brickInit(brick1, BRICK1_POS);
	Brick brick2;
	brickInit(brick2, BRICK2_POS);
	Brick brick3;
	brickInit(brick3, BRICK3_POS);
	Brick brick4;
	brickInit(brick4, BRICK4_POS);
	Brick brick5;
	brickInit(brick5, BRICK5_POS);
	Brick arr[5] = { brick1,brick2,brick3,brick4,brick5 };
	Life mas[3] = { life1,life2,life3 };
	Can can;
	canInit(can);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		switch (gameState) {
		case PLAY:
			roadObjUpdate(grass, GRASS_POS1);
			roadObjUpdate(road, ROAD_POS1);
			roadObjUpdate(grass1, GRASS_POS1);
			roadObjUpdate(road1, ROAD_POS1);
			carUpdate(car);
			obstacleUpdate(obs);
			TextobjUpdate(scoreText, car.score);
			TextobjUpdate(scorecanText, car.canscore);
			canUpdate(can);
			if (car.sprite.getGlobalBounds().intersects(obs.sprite.getGlobalBounds())) {
				respawn(obs);
				car.score = car.score - 1;
				mas[car.score].sprite.setPosition(END_POS);
			}
			LifeUpdate(mas[0]);
			LifeUpdate(mas[1]);
			LifeUpdate(mas[2]);

			if (car.sprite.getGlobalBounds().intersects(can.sprite.getGlobalBounds())) {
				respawncan(can);
				car.canscore = car.canscore + 1;
				arr[car.canscore-1].shape.setFillColor(Color::Green);
			}
			brickUpdate(arr[1]);
			brickUpdate(arr[2]);
			brickUpdate(arr[3]);
			brickUpdate(arr[4]);
			brickUpdate(arr[0]);

			if (car.canscore == 5) {
				gameState = YOU_WIN;
			}

			if (car.score == 0) {
				gameState = GAME_OVER;
			}

			window.clear();
			roadObjDraw(window, grass);
			roadObjDraw(window, road);
			roadObjDraw(window, grass1);
			roadObjDraw(window, road1);
			carDraw(window, car);
			obstacleDraw(window, obs);
			textDraw(window, scoreText);
			LifeDraw(window, mas[0]);
			LifeDraw(window, mas[1]);
			LifeDraw(window, mas[2]);
			brickDraw(window, arr[1]);
			brickDraw(window, arr[2]);
			brickDraw(window, arr[3]);
			brickDraw(window, arr[4]);
			brickDraw(window, arr[0]);
			canDraw(window, can);
			textDraw(window, scorecanText);
			window.display();
			break;

		case GAME_OVER:
			window.clear();
			textDraw(window, gameOverText);
			window.display();
			break;
		case YOU_WIN:
			window.clear();
			textDraw(window, youWinText);
			window.display();
			break;
		}
	}

	return 0;
}
