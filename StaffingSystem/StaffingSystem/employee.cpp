#include "employee.h"
#include<iostream>
using namespace std;

Emoployee::Emoployee(int id, string name, int deptId)
{
	this->id = id;
	this->name = name;
	this->deptId = deptId;
}

void Emoployee::showInfo()
{
	cout << "ְ����ţ�" << this->id
		<< "\tְ��������" << this->name
		<< "\tְ����λ��" << this->getDeptName()
		<< "\t��λְ����ɾ�����������"
		<< endl;
}

string Emoployee::getDeptName()
{
	return string("Ա��");
}
