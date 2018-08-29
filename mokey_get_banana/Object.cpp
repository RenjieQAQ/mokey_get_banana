#include "Object.h"



Object::Object(const char * name )
{
	obj_name = name;
	position = NULL;
}


Object::~Object()
{
}


const char * Object::name() const
{
	return obj_name;
}


const Position & Object::where() const{
	return *position;
}

ostream& operator << (ostream& out , Object& obj) {
	out << obj.obj_name;
	return out;
}


bool SamePlace(const Object& obj_a, const Object& obj_b) {
	if(obj_a.where()== obj_b.where())
		return true;
	else
		return false;
}
