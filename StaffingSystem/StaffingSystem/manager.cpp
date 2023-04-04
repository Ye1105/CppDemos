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
	cout << "职工标号：" << this->id
		<< "\t职工姓名：" << this->name
		<< "\t职工岗位：" << this->getDeptName()
		<< "\t岗位职责：完成老板交给的任务，并下发任务给员工"
		<< endl;
}

string Manager::getDeptName()
{
	return string("经理");
}
