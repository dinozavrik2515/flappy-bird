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
	bool isover = &over;
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
			rect.left += dx * time;

			if (play)
			{
				dy = dy + 0.0005 * time;
			}

			rect.top += dy * time;

			if (rect.top <= 0)
			{
				rect.top = 0;
			}

			if (rect.top > 860)
			{
				rect.top = 860;
				dy = 0;

				sprite.setTexture(GameOver);
				sprite.setTextureRect(IntRect(0, 0, 180, 166));

				
				over = false;
				
					
				
			}

		}

	

		/*curFrame += 0.005 * time;
		if (curFrame > 3)
		{
			curFrame -= 3;
		}*/

		sprite.setTextureRect(IntRect(38 * int(curFrame), 0, 80, 66));

		sprite.setPosition(rect.left, rect.top);
	}
};
