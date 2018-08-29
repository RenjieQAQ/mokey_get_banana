#pragma once
#include <iostream>
#include "Position.h"
class Object
{
public:
	Object(const char * name=NULL);
	~Object();
protected:
	const char *obj_name;
	const Position * position;
public:
	const char * name() const;
	const Position & where() const;
	friend ostream& operator << (ostream&, Object&);
	friend bool SamePlace(const Object& obj_a, const Object& obj_b);
};

