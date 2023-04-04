#include "boss.h"
#include <iostream>
using namespace std;

Boss::Boss(int id, string name, int deptId) {
	this->id = id;
	this->name = name;
	this->deptId = deptId;
}

void Boss::showInfo()
{
	cout << "职工标号：" << this->id
		<< "\t职工姓名：" << this->name
		<< "\t职工岗位：" << this->getDeptName()
		<< "\t岗位职责：管理公司所有事务"
		<< endl;
}

string Boss::getDeptName()
{
	return string("老板");
}
