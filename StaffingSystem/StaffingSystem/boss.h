#pragma once
#include "worker.h"

class Boss :public Worker {
public:
	Boss(int id, string name, int deptId);

	// Í¨¹ý Worker ¼Ì³Ð
	virtual void showInfo() override;
	virtual string getDeptName() override;
};