#include <SFML/Graphics.hpp> 
#include <stdlib.h> 
#include <time.h> 
#include "player.h"
#include "Tap.h"
#include "Pipe.h"
#include <sstream>
#include "Mvar.h"
#include "score.h"
#include <iostream>

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(700, 1000), "test");

	Image FonImage;
	FonImage.loadFromFile("images\\fon1.jpg");

	Texture FonTexture;
	FonTexture.loadFromImage(FonImage);

	Sprite FonSprite;
	FonSprite.setTexture(FonTexture);

	Image PlayerImage;
	PlayerImage.loadFromFile("images\\1bird.png");

	Texture PlayerTexture;
	PlayerTexture.loadFromImage(PlayerImage);

	Sprite PlayerSprite;
	PlayerSprite.setTexture(PlayerTexture);
	Player Bird(PlayerTexture);

	Image TapImage;
	TapImage.loadFromFile("images\\Без названия335_20240918093852.png");

	Texture TapTexture;
	TapTexture.loadFromImage(TapImage);

	Sprite TapSprite;
	TapSprite.setTexture(TapTexture);
	TapSprite.setPosition(95, 120);
	Tap tap;

	Image PipeImage;
	PipeImage.loadFromFile("images\\gljancevoe-serdechko-128x123.png");


	Texture PipeTexture;
	PipeTexture.loadFromImage(PipeImage);

	Sprite PipeSprite;
	PipeSprite.setTexture(PipeTexture);
	Pipe pipe(PipeTexture);

	

	Image GameOverImage;
	GameOverImage.loadFromFile("images\\Без названия332_20240917204720.png");

	Texture GameOverTexture;
	GameOverTexture.loadFromImage(GameOverImage);

	Sprite GameOverSprite;
	GameOverSprite.setTexture(GameOverTexture);

	Score score;
	score.score(pipe, Bird);

	Image ScoreImage;
	ScoreImage.loadFromFile("images\\Без названия336_20240918114836.png");

	Texture ScoreTexture;
	ScoreTexture.loadFromImage(ScoreImage);

	Sprite ScoreSprite;
	ScoreSprite.setTexture(ScoreTexture);
	ScoreSprite.setPosition(0, -10);

	
	
	Clock clock;




	while (window.isOpen())
	{
		
			float time = clock.getElapsedTime().asMicroseconds();
			clock.restart();
			time = time / 800;

			Event event;
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
				{
					window.close();
				}
			}

			if (event.type == Event::MouseButtonPressed)
			{
				if (event.key.code == Mouse::Left)
				{
					if (start)
					{
						start = false;
						play = true;
					}


					if (play)
					{
						Bird.dy = -0.2;
					}
				}


			}
			if (play)
			{
				if (Bird.rect.left > 10)
				{
					Bird.dx = -0.02;
				}
				else
				{
					Bird.dx = 0;
				}

				pipe.dx = -0.6;
			}



			Bird.update(time, GameOverTexture, PlayerTexture);
			if (start)
			{
				tap.update();
			}
			pipe.update();
			window.clear(Color::White);
			window.draw(FonSprite);
			window.draw(Bird.sprite);

			if (start)
			{
				window.draw(TapSprite);
			}

			for (int i = 0; i < 2; i++)
			{
				window.draw(pipe.sprite[i]);
			}
			
			if (!over)
			{
				window.draw(ScoreSprite);
			}
			
			window.display();

		
		
	}

	

	return 0;
}