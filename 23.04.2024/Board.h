#pragma once
#include <vector>
#include "Cell.h"

class Board
{
public:
	Board(int width = DEFAULT_WIDTH, int height = DEFAULT_HEIGHT) 
		: 
		_width(width),
		_height(height)
	{
		for (int i = 0; i < width; ++i)
		{
			_cells.emplace_back();
			for (int j = 0; j < height; ++j)
			{
				_cells[_cells.size() - 1].emplace_back(static_cast<Cell::State>(rand()%2));
			}
		}
	};

	void nextGeneration()
	{
		std::vector<std::vector<Cell>> tmp = _cells;

		for (int i = 0; i < _width; i++)
		{
			for (int j = 0; j < _height; ++j)
			{
				int alive_neighbours = calculate_neighbours(i,j);

				Cell& lookupCell = _cells[i][j];
				Cell& nexGenCell = tmp[i][j];

				if (lookupCell.getState() == Cell::State::ALIVE)
				{
					if (alive_neighbours < 2) nexGenCell.setState(Cell::State::DEAD);
					else if(alive_neighbours > 3) nexGenCell.setState(Cell::State::DEAD);
				}
				else
				{
					if (alive_neighbours == 3) nexGenCell.setState(Cell::State::ALIVE);
				}
			}
		}
		_cells = tmp;
	}

	const std::vector<std::vector<Cell>>& getCells() { return _cells; };
	int getWidht() { return _width; }
	int getHeight() { return _height; }

public:
	static constexpr int DEFAULT_WIDTH = 50;
	static constexpr int DEFAULT_HEIGHT = 30;

private:
	int calculate_neighbours(int x, int y)
	{
		int rv = 0;
		int leftX = (x - 1 >= 0) ? x - 1 : 0;
		int rightX = x + 1 < _width ? x + 1 : _width-1;
		int topY = y - 1 >= 0 ? y - 1 : 0;
		int bottomY = y + 1 < _height ? y + 1 : _height - 1;

		for (int i = leftX; i <= rightX; i++)
		{
			for (int j = topY; j <= bottomY; ++j)
			{
				if (i != x || j != y)
				{
					if (_cells[i][j].getState() == Cell::State::ALIVE)
					{
						rv++;
					}
				}
			}
		}

		return rv;
	}


private:
	int _width;
	int _height;
	std::vector<std::vector<Cell>> _cells;
};