#pragma once
#include "Graphics.h"

class Ball
{
public:
	Ball(int x, int y, int r) : posX(x), posY(y), radius(r), directionX(1), directionY(1) {};

	void draw(Graphics& gfx)
	{
		gfx.drawCircle(posX, posY, radius, Colors::White);
	}

	void move(int speed)
	{
		if (posX - radius - speed < 0) directionX *= -1;
		if (posX + radius + speed >= Graphics::ScreenWidth) directionX *= -1;
		if (posY - radius - speed < 0) directionY *= -1;
		if (posY + radius + speed >= Graphics::ScreenHeight) directionY *= -1;

		posX += directionX * speed;
		posY += directionY * speed;
	}

	void reset()
	{
		posX = Graphics::ScreenWidth / 2;
		posY = Graphics::ScreenHeight / 2;
	}

	void setDirectionX(int x) { directionX = x; }

	int getX() { return posX; }
	int getY() { return posY; }
	int getRadius() { return radius; }
	int getDirectionX() { return directionX; }

private:
	int posX;
	int posY;
	int radius;
	int directionX;
	int directionY;
};