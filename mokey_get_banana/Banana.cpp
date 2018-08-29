#include "Banana.h"



Banana::Banana(const Position &pos)
{
	obj_name = "Banana";
	position = &pos;
}


Banana::~Banana()
{
}

void Banana::status() {
	cout << "BananaAt(" << *this << "," << *position << ")," << endl;
}
