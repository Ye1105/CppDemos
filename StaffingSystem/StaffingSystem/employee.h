#pragma once
#include "worker.h"

class Emoployee :public Worker {
public:
	Emoployee(int id, string name, int deptId);

	//显示个人信息
	virtual void showInfo();

	//获取岗位名称
	virtual string getDeptName();
};