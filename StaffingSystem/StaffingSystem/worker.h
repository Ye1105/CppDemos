#pragma once
#include <string>
using namespace std;

/// <summary>
/// Worker 抽象类
/// </summary>
class Worker {
public:

	//显示个人信息
	virtual void showInfo() = 0;

	//获取岗位名称
	virtual string getDeptName() = 0;

	//职工标号
	int id;
	//职工姓名
	string name;
	//职工所在部门名称编号
	int deptId;
};