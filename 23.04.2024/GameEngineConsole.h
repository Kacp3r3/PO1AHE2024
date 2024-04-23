#pragma once
#include <Windows.h>
#include <iostream>

#include "GameEngine.h"
class GameEngineConsole : public GameEngine
{
public:
	GameEngineConsole() : GameEngine() 
	{
		_console = GetStdHandle(STD_OUTPUT_HANDLE);
	};

	void processInput() 
	{
		/*
			if kbhit()
			user_input = getch()
			if(user_input == 27) _run = False;
		
		*/
	};
	void show()
	{
		_cursorPos.X = 0;
		_cursorPos.Y = 0;
		SetConsoleCursorPosition(_console, _cursorPos);

		const auto& cells = _board.getCells();

		for (int i = 0; i < _board.getWidht(); ++i)
		{
			for (int j = 0; j < _board.getHeight(); ++j)
			{
				if (cells[i][j].getState() == Cell::State::ALIVE) std::cout << "#";
				else std::cout << " ";

				_cursorPos.Y++;
				SetConsoleCursorPosition(_console, _cursorPos);
			}
			_cursorPos.Y = 0;
			_cursorPos.X++;
		}
	}

private:
	COORD _cursorPos;
	HANDLE _console;
};