#pragma once
#include "worker.h"

class Boss :public Worker {
public:
	Boss(int id, string name, int deptId);

	// ͨ�� Worker �̳�
	virtual void showInfo() override;
	virtual string getDeptName() override;
};