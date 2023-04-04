#include "worker.h"

class Manager :public Worker {
public:
	Manager(int id, string name, int deptId);
	// Í¨¹ý Worker ¼Ì³Ð
	virtual void showInfo();
	virtual string getDeptName();
};