#pragma once
#include <string>
using namespace std;

class Judgment {
private:
	//���
	int order;
	//����
	string name;
public:

	friend class Student;

	friend class GameManager;

	friend ostream& operator<<(ostream& out, const Judgment& st);

	//��������
	int postScore();

	Judgment();

	~Judgment();
};