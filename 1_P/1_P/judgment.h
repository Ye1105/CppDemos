#pragma once
#include <string>
using namespace std;

class Judgment {
private:
	//编号
	int order;
	//姓名
	string name;
public:

	friend class Student;

	friend class GameManager;

	friend ostream& operator<<(ostream& out, const Judgment& st);

	//发布分数
	int postScore();

	Judgment();

	~Judgment();
};