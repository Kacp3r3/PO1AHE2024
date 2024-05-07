#pragma once
#include "Graphics.h"
#include "Ball.h"

class Paddle
{
public:
	Paddle(int x, int y, int w, int h) : posX(x), posY(y), width(w), height(h) {};

	void draw(Graphics& gfx)
	{
		gfx.drawRect(posX, posY, width, height, Colors::White);
	}

	void moveUp(int x)
	{
		if (posY - height / 2 - x >= 0)
		{
			posY -= x;
		}
	}

	void moveDown(int x)
	{
		if (posY + height / 2 + x < Graphics::ScreenHeight)
		{
			posY += x;
		}
	}

	bool checkColission(Ball& ball)
	{
		if (ball.getX() <= posX + width / 2)
		{
			if (ball.getX() >= posX - width / 2)
			{
				if (ball.getY() <= posY + height / 2)
				{
					if (ball.getY() >= posY - height / 2)
					{
						return true;
					}
				}
			}
		}
		return false;
		//return  &&  &&  && ;
	}

private:
	int posX;
	int posY;
	int width;
	int height;
};