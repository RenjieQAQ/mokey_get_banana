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
	cout << "״̬��MonkeyAt(" << *this <<","<< *position << "),";
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
	cout <<" *"<< *this << "��λ��"<<where() <<"�ƶ���"<< to << endl;
	position = &to;
	return 0;
}


int Monkey::CARRY(Box& box, const Position& to)
{
	if (*position == box.where()) {
		cout << " *" << *this << "��"<<box <<"��λ��" << where() << "���˵�" << to << endl;
		box.position = &to;
		this->position = &to;
	}
	else {
		cout << " *" << *this << "�޷��ƶ�" << box << "��Ϊ���߲���ͬһλ��" << endl;
	}
	return 0;
}


int Monkey::CLIMB(Box& box)
{
	if (*position == box.where()) {
		box_to_stand = &box;
		cout << " *" << *this << "������" << box << endl;
	}
	else {
		cout << " *" << *this << "�޷�����" << box << "��Ϊ���߲���ͬһλ��" << endl;
	}
	return 0;
}


int Monkey::HOLD(Object& thing)
{
	if (*position == thing.where()) {
		obj_holded = &thing;

		cout << " *" << *this << "������" << thing << endl;
	}
	else {
		cout << " *" << *this << "�޷�����" << thing << "��Ϊ���߲���ͬһλ��" << endl;
	}
	return 0;
}


