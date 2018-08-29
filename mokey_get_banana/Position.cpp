#include "Position.h"



Position::Position(const char * name )
{
	pos_name = name;
}

Position::Position(const Position& pos) {
	pos_name = pos.pos_name;
}

Position::~Position()
{
}

string Position::name() {
	return  pos_name;
}


void Position::setPlace(string name) {
	pos_name = name;
}


bool Position::operator == (Position& pos) {
	if (pos_name == pos.name())
		return true;
	else
		return false;
}

bool operator == (const Position& pos1, const Position& pos2) {
	if (pos1.pos_name == pos2.pos_name)
		return true;
	else
		return false;
}
ostream& operator << (ostream& out, Position& pos) {
	out << pos.pos_name;
	return out;
}

ostream& operator << (ostream& out, const Position& pos) {
	out << pos.pos_name;
	return out;
}
