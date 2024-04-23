#pragma once
#include <thread>
#include <chrono>

#include "Board.h"

//Nie u¿ywamy klauzuli using w plikach nag³ówkowych!
using namespace std::chrono_literals;

class GameEngine
{
public:
	GameEngine() : _board(), _run(true) {};

	virtual void processInput() = 0;
	virtual void show() = 0;

	void update()
	{
		std::this_thread::sleep_for(0.25s);
		_board.nextGeneration();
	}

	void go()
	{
		while (_run)
		{
			processInput();
			update();
			show();
		}
	}

protected:
	bool _run;
	Board _board;
};