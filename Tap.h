#pragma once
#include <SFML/Graphics.hpp> 

using namespace sf;

class Tap
{
public:
	Sprite sprite;
	bool vid;
	
	void update()
	{
		vid = false;

	}
};