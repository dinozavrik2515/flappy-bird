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
	
	

	void Coordinates()
	{
		srand(time(0));

		y = rand() % 6;

		rect.left = 700;

		rect.top = 50 + 120 * y;

	}

	Pipe(Texture& image)
	{
		for (int i = 0; i < 2; i++)
		{
			sprite[i].setTexture(image);
		}

		sprite[1].setTextureRect(IntRect(28, 715, 85, -115));

		dx = 0;
		Coordinates();
	}

	void update()
	{
		if (over)
		{
			if (play)
			{
				rect.left += dx;
			}
			if (rect.left < -5)
			{
				Coordinates();
			}

			for (int i = 0; i < 2; i++)
			{
				sprite[i].setPosition(rect.left, rect.top - 1 * i);
			}
			
		}

		
	}
};