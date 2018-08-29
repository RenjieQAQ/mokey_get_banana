#include "Box.h"



Box::Box(const Position &pos)
{
	obj_name = "Box";
	position = &pos;
}


Box::~Box()
{
}

bool Box::BoxAt(Position& pos) {
	if (&pos == position)
		return true;
	else
		return false;
}


void Box::status() {
	cout << "BoxAt(" << *this << "," << *position << ")," ;
}
