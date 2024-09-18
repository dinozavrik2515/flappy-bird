#pragma once
#include <SFML/Graphics.hpp> 
#include "player.h"
#include "Pipe.h"

using namespace  sf;

void score(Pipe pipe, Player Bird, int &Scoreplay) 
{
	if (pipe.rect.intersects(Bird.rect)) // Проверка на пересечение спрайтов
	{
		Scoreplay++;
	}
}