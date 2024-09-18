#pragma once
#include <SFML/Graphics.hpp> 
#include "player.h"
#include "Pipe.h"

using namespace  sf;
class Score
{
public:
	int playerscore = 0;
	int score(Pipe pipe, Player Bird)
	{
		if (pipe.rect.top == Bird.rect.left && pipe.rect.top == Bird.rect.top)
		{
			playerscore++;
			return playerscore;
		}

	}
};