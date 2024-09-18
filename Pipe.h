#pragma once
#include <time.h>
#include <SFML/Graphics.hpp> 
#include "Mvar.h"

using namespace sf;

class Pipe
{
public:
	float PipePosition;
	Sprite sprite[2];
	int y;
	float dx;
	FloatRect rect;
	
	

	// Метод для установки координат
	void Coordinates()
	{
		srand(time(0));

		y = rand() % 6; // Генерация случайного положения

		rect.left = 700;

		rect.top = 50 + 120 * y;

	}

	Pipe(Texture& image)
	{
		for (int i = 0; i < 2; i++)
		{
			sprite[i].setTexture(image); // Установка текстуры для каждого спрайта

		}
			sprite[1].setTextureRect(IntRect(28, 715, 85, -115)); // Установка области текстуры для второго спрайта
		
		dx = 0;
		Coordinates();
	}

	void update() // Метод обновления состояния 
	{
		if (over)
		{
			if (play)
			{
				rect.left += dx;
			}
			if (rect.left < -10) // Если сердечко выходит за пределы экрана, создаем новое
			{
				Coordinates();
			}

			for (int i = 0; i < 2; i++)  // Установка позиции спрайтов
			{
				sprite[i].setPosition(rect.left, rect.top - 1 * i);
				
			}
			
		}

		
	}
};