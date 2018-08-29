#pragma once
#include "Object.h"
class Banana :
	public Object
{
public:
	Banana(const Position &pos);
	~Banana();
	void status();
};

