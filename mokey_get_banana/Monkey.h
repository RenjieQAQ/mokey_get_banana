#pragma once
#include "Object.h"
#include "Box.h"
#include "Position.h"
#include "Banana.h"
class Monkey :
	public Object
{
public:
	Monkey(const Position &pos);
	~Monkey();
	bool Ground();
	bool MonkeyAt(Position& pos);
	bool Hold(Object& thing);
	bool Empty();
	bool OnBox(Box &box);
	void status();
private:
	Box *box_to_stand;
	Object *obj_holded;
	//Position* positon;
public:
	int MOVE(const Position& to);
	int CARRY(Box& box, const Position& to);
	int CLIMB(Box& box);
	int HOLD(Object& thing);
};

