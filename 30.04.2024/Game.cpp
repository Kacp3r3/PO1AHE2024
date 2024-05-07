/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	p1(50, Graphics::ScreenHeight / 2, 20, 80),
	p2(Graphics::ScreenWidth - 50, Graphics::ScreenHeight / 2, 20, 80),
	ball(Graphics::ScreenWidth / 2, Graphics::ScreenHeight / 2, 10),
	scoreP1(0),
	scoreP2(0)
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (ball.getX() < 25)
	{
		scoreP2++;
		ball.reset();
		std::string info = "P2 score: " + std::to_string(scoreP2) + "\n";
		OutputDebugStringA(info.c_str());
	}
	else if (ball.getX() > Graphics::ScreenWidth - 25)
	{
		scoreP1++;
		ball.reset();
		std::string info = "P1 score: " + std::to_string(scoreP1) + "\n";
		OutputDebugStringA(info.c_str());
	}
	
	auto event = wnd.kbd.ReadKey();
	if (event.GetCode() == VK_ESCAPE)
	{
		wnd.Kill();
	}


	const int speed = 5;

	//sprawdzenie kolizji
	if (p1.checkColission(ball))
	{
		ball.setDirectionX(1);
	}
	else if(p2.checkColission(ball))
	{
		ball.setDirectionX(-1);
	}

	ball.move(speed);
	
	if (wnd.kbd.KeyIsPressed('W'))
	{
		p1.moveUp(speed);
	}
	else if (wnd.kbd.KeyIsPressed('S'))
	{
		p1.moveDown(speed);
	}

	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		p2.moveUp(speed);
	}
	else if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		p2.moveDown(speed);
	}

}

void Game::ComposeFrame()
{
	p1.draw(gfx);
	p2.draw(gfx);
	ball.draw(gfx);
}
