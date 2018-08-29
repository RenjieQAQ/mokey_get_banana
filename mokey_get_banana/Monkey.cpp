#include "Monkey.h"



Monkey::Monkey(const Position & pos)
{
	obj_name = "Monkey";
	position = &pos;
	box_to_stand = NULL;
	obj_holded = NULL;
}


Monkey::~Monkey()
{
}


bool Monkey::Ground()
{
	if (box_to_stand == NULL)
		return true;
	else
		return false;
}


bool Monkey::MonkeyAt(Position& pos)
{
	if (&pos == position)
		return true;
	else
		return false;
}


bool Monkey::Hold(Object& thing)
{
	if(&thing == obj_holded)
		return true;
	else
		return false;
}


bool Monkey::Empty()
{
	if (obj_holded == NULL)
		return true;
	else
		return false;
}


bool Monkey::OnBox(Box &box)
{
	if (&box == box_to_stand)
		return true;
	else
		return false;
}

void Monkey::status() {
	cout << "状态：MonkeyAt(" << *this <<","<< *position << "),";
	if(Ground())
		cout << "Ground(" << *this << "),";
	else
		cout << "OnBox(" << *this << "," << *box_to_stand << "),";
	if(Empty())
		cout << "Empty(" << *this << "),";
	else
		cout << "Hold(" << *this << "," << *obj_holded << "),";

}


int Monkey::MOVE(const Position& to)
{
	cout <<" *"<< *this << "从位置"<<where() <<"移动到"<< to << endl;
	position = &to;
	return 0;
}


int Monkey::CARRY(Box& box, const Position& to)
{
	if (*position == box.where()) {
		cout << " *" << *this << "把"<<box <<"从位置" << where() << "搬运到" << to << endl;
		box.position = &to;
		this->position = &to;
	}
	else {
		cout << " *" << *this << "无法移动" << box << "因为两者不在同一位置" << endl;
	}
	return 0;
}


int Monkey::CLIMB(Box& box)
{
	if (*position == box.where()) {
		box_to_stand = &box;
		cout << " *" << *this << "爬上了" << box << endl;
	}
	else {
		cout << " *" << *this << "无法爬上" << box << "因为两者不在同一位置" << endl;
	}
	return 0;
}


int Monkey::HOLD(Object& thing)
{
	if (*position == thing.where()) {
		obj_holded = &thing;

		cout << " *" << *this << "拿起了" << thing << endl;
	}
	else {
		cout << " *" << *this << "无法拿起" << thing << "因为两者不在同一位置" << endl;
	}
	return 0;
}


