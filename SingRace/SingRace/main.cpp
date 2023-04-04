#include<iostream>
using namespace std;
#include "sing_manager.h"


int main() {

	srand((unsigned int)time(NULL));

	SingManager sm;


	int num = -1;

	while (true)
	{
		switch (num)
		{
		case -1:
			system("cls");
			sm.showMenu();
			cout << "请输入操作指令,按 enter 确定输入" << endl;
			cin >> num;

			continue;
		case 0:
			sm.exsitSystem();
			break;
		case 1:
			sm.startSpeech();
			break;
		case 2:
			sm.showRecord();
			break;
		case 3:
			sm.clearRecord();
			break;
		}
		system("pause");
		num = -1;
	}
}