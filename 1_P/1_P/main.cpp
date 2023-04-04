#include<iostream>
#include<vector>
#include "game_manager.h"
using namespace std;

int main() {
	//�����б�
	vector<Judgment> jgs;
	for (size_t i = 0; i < JUDGMENT_NUM; i++)
	{
		jgs.push_back(Judgment());
	}

	//ѧ���б�
	vector<Student> sts;
	for (size_t i = 0; i < STUDENT_NUM; i++)
	{
		sts.push_back(Student());
	}

	//��ʼ��
	GameManager gm(sts, jgs);

	int num = 0;

	while (true)
	{
		cout << "���벽��" << endl;
		cin >> num;
		switch (num)
		{
		case 1:
			cout << "��ʼ��ǩ" << endl;
			gm.draw();
			break;
		case 2:
			cout << "��ʼ����" << endl;
			gm.group();
			break;

		case 3:
			cout << "��һ�����" << endl;
			gm.groupOnRace();
			break;

		case 4:
			cout << "�ڶ������" << endl;
			gm.groupOnRace2();
			break;

		case 5:
			cout << "����" << endl;
			gm.finalRace();
			break;

		default:
			break;
		}
	}

	std::system("pause");
	return 0;
}