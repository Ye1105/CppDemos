#include<iostream>
using namespace std;
#include "worker_manager.h"

int main() {



	//实例化管理员对象
	WorkerManager wm;

	int num = -1;

	while (true)
	{
		switch (num)
		{
		case -1:
			system("cls");
			wm.showMenu();
			cout << "请输入操作指令,按 enter 确定输入" << endl;
			cin >> num;

			continue;
		case 0:
			wm.exsitSystem();

		case 1:
			wm.addEmp();
			break;
		case 2:
			wm.showEmp();
			break;

		case 3:
		{
			wm.delEmp();
			break;
		}
		case 4:
		{
			wm.finEmp();
			break;
		}

		case 5:
		{
			wm.modEmp();
			break;
		}

		case 6:
		{
			wm.sortEmp();
			break;
		}
		case 7:
		{
			wm.clearFile();
			break;
		}

		default:

			cout << "指令不存在" << endl;
			break;
		}

		system("pause");
		num = -1;
	}

	system("pause");
	return 0;
}