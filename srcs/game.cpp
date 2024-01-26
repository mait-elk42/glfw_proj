#include <stdio.h>
// #include <GFX/game.hpp>


class Vector2 {
private:
	int	x;
	int	y;

public:
	Vector2(int x, int y) : x(x), y(y)
	{
		printf("!%d\n", this->x);
	}
	// {
	// 	this->x = x;
	// 	this->y = y;
	// }
	~Vector2()
	{

	}
	void ReInitialize(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};