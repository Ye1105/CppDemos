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
	cout << "职工标号：" << this->id
		<< "\t职工姓名：" << this->name
		<< "\t职工岗位：" << this->getDeptName()
		<< "\t岗位职责：完成经理交给的任务"
		<< endl;
}

string Emoployee::getDeptName()
{
	return string("员工");
}
