#include "worker.h"

class Manager :public Worker {
public:
	Manager(int id, string name, int deptId);
	// ͨ�� Worker �̳�
	virtual void showInfo();
	virtual string getDeptName();
};