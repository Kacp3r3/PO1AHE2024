#pragma once

class Cell
{
public:
	enum class State
	{
		DEAD,
		ALIVE,
	};

public:
	Cell() : _state(State::DEAD) {};
	Cell(State s) : _state(s) {};

	State getState() const { return _state;  }
	void setState(const State& newState) { _state = newState;  }

private:
	State _state;
};