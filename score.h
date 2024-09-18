#pragma once
#include <SFML/Graphics.hpp> 
#include "player.h"
#include "Pipe.h"

using namespace  sf;

float score(Pipe pipe, Player Bird, int &scoreplay)
{

	if (pipe.rect.left == Bird.rect.left && pipe.rect.top == Bird.rect.top)
	{
		scoreplay++;

		return scoreplay++;

	}
}