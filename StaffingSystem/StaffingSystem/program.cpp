#include<iostream>
using namespace std;
#include "worker_manager.h"

int main() {



	//ʵ��������Ա����
	WorkerManager wm;

	int num = -1;

	while (true)
	{
		switch (num)
		{
		case -1:
			system("cls");
			wm.showMenu();
			cout << "���������ָ��,�� enter ȷ������" << endl;
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

			cout << "ָ�����" << endl;
			break;
		}

		system("pause");
		num = -1;
	}

	system("pause");
	return 0;
}