#include "manager.h"
#include<iostream>
using namespace std;

Manager::Manager(int id, string name, int deptId)
{
	this->id = id;
	this->name = name;
	this->deptId = deptId;
}

void Manager::showInfo()
{
	cout << "ְ����ţ�" << this->id
		<< "\tְ��������" << this->name
		<< "\tְ����λ��" << this->getDeptName()
		<< "\t��λְ������ϰ彻�������񣬲��·������Ա��"
		<< endl;
}

string Manager::getDeptName()
{
	return string("����");
}
