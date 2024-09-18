#pragma once
#include <SFML/Graphics.hpp> 
#include "Mvar.h"
#include <sstream>

using namespace sf;

class Player
{
public:
	float dy, dx;
	FloatRect rect;
	Sprite sprite;
	float curFrame;
	Event event1;


	

	Player(Texture& bird)
	{
		sprite.setTexture(bird);
		sprite.setTextureRect(IntRect(0, 0, 80, 66));

		

		rect.left = 100;
		rect.top = 125;

		dy = dx = 0;
		curFrame = 0;
	}

	void update(float time, Texture& GameOver, Texture& bird)
	{
		if(over)
		{
			rect.left += dx * time; // Обновление горизонтальной позиции игрока

			if (play)
			{
				dy = dy + 0.0005 * time; // Увеличение вертикальной скорости под действием гравитации
			}

			rect.top += dy * time;

			if (rect.top <= 0)
			{
				rect.top = 0; // Установка игрока на верхнюю границу
			}

			if (rect.top > 860) //Проверка, если птичка выходит за нижнюю границу
			{
				rect.top = 860; // Установка игрока на нижнюю границу
				dy = 0; // Обнуление вертикальной скорости

				sprite.setTexture(GameOver);
				sprite.setTextureRect(IntRect(0, 0, 180, 166));

				
				over = false;
				
					
				
			}

		}

		
		
		sprite.setTextureRect(IntRect(0, 0, 80, 66));
		sprite.setPosition(rect.left, rect.top);
	}
};
