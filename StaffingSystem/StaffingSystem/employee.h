#pragma once
#include "worker.h"

class Emoployee :public Worker {
public:
	Emoployee(int id, string name, int deptId);

	//��ʾ������Ϣ
	virtual void showInfo();

	//��ȡ��λ����
	virtual string getDeptName();
};