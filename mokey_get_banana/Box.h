#pragma once
#include "Object.h"
#include "Position.h"
class Box :
	public Object
{
public:
	Box(const Position &pos);
	~Box();
	bool BoxAt(Position& pos);
	void status();
	friend class Monkey;
private:
	//Position * position;
};

