#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include "Box.h"
#include "Position.h"
#include "Banana.h"
#include "Monkey.h"

class monkeyProblem {
	Monkey monkey;
	Box	box;
	Banana banana;
public:
	monkeyProblem(const Position& monkey_pos, const Position& box_pos, const Position& banana_pos)
		:monkey(monkey_pos),box(box_pos), banana(banana_pos){

	}
	~monkeyProblem() {

	}
	void ShowStatus() {
		monkey.status();
		box.status();
		banana.status();
	}
	void WorkOut() {
		ShowStatus();
		if (!SamePlace(monkey, box)) {
			monkey.MOVE(box.where());
			ShowStatus();
		}
		if (SamePlace(monkey, box)&&(!SamePlace(monkey, banana))) {
			monkey.CARRY(box, banana.where());
			ShowStatus();
		}
		if (monkey.Ground()&& SamePlace(monkey, box)&& SamePlace(box, banana)) {
			monkey.CLIMB(box);
			ShowStatus();
		}
		if (monkey.Empty() && monkey.OnBox(box) && SamePlace(monkey, box) && SamePlace(box, banana)) {
			monkey.HOLD(banana);
			ShowStatus();
		}
		if (monkey.Hold(banana) && monkey.OnBox(box) && SamePlace(monkey, box) && SamePlace(box, banana)) {
			cout<<"猴子成功摘到香蕉"<<endl;
		}
		else {
			cout << "猴子摘到香蕉失败" << endl;
		}
	}
};

int main() {
	Position pos_monkey("a"), pos_banana("b"), pos_box("c");
	monkeyProblem problem(pos_monkey, pos_banana, pos_box);
	problem.WorkOut();
	string str;
	while (1) {
		cout << "输入q退出，输入r退出重新开始" << endl;
		char ch=getchar();
		if (ch == 'q')
			return 0;
		if (ch == 'r') {
			cout << "请输入猴子的位置名称：" << endl;
			cin >> str;
			pos_monkey.setPlace(str);
			cout << "请输入箱子的位置名称：" << endl;
			cin >> str;
			pos_box.setPlace(str);
			cout << "请输入香蕉的位置名称：" << endl;
			cin >> str;
			pos_banana.setPlace(str);
			monkeyProblem new_problem(pos_monkey, pos_banana, pos_box);
			new_problem.WorkOut();
		}
	}
	system("Pause");
	return 0;
}
