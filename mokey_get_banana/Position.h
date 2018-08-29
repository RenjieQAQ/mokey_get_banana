#pragma once
#include <iostream>
#include <string>
using namespace std;
class Position 
{
	string pos_name;
public:
	Position(const char * name = "somewhere");
	Position(const Position& pos);
	~Position();
	void setPlace(string name);
	bool operator == (Position&);
	friend bool operator == (const Position&, const Position&);
	friend ostream& operator << (ostream&, Position&);
	friend ostream& operator << (ostream&, const Position&);
	string name();
};

