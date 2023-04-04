#include<iostream>
#include<vector>
#include "game_manager.h"
using namespace std;

int main() {
	//裁判列表
	vector<Judgment> jgs;
	for (size_t i = 0; i < JUDGMENT_NUM; i++)
	{
		jgs.push_back(Judgment());
	}

	//学生列表
	vector<Student> sts;
	for (size_t i = 0; i < STUDENT_NUM; i++)
	{
		sts.push_back(Student());
	}

	//初始化
	GameManager gm(sts, jgs);

	int num = 0;

	while (true)
	{
		cout << "输入步骤" << endl;
		cin >> num;
		switch (num)
		{
		case 1:
			cout << "开始抽签" << endl;
			gm.draw();
			break;
		case 2:
			cout << "开始分组" << endl;
			gm.group();
			break;

		case 3:
			cout << "第一组比赛" << endl;
			gm.groupOnRace();
			break;

		case 4:
			cout << "第二组比赛" << endl;
			gm.groupOnRace2();
			break;

		case 5:
			cout << "决赛" << endl;
			gm.finalRace();
			break;

		default:
			break;
		}
	}

	std::system("pause");
	return 0;
}