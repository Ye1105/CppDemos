#pragma once
#include <string>
#include <deque>
using namespace std;
#include "extend.h"

class Student {
private:
	//���
	int order;
	//����
	string name;
	//����˳��
	int randomOrder;
	//�Ƿ�ͨ��
	bool isPass;
	//�����б�
	deque<int> scores;
	//ƽ����
	int avarage; //accumulate

public:

	/// <summary>
	/// ȫ�ֺ�����ƽ�����������
	/// </summary>
	/// <param name="ref1"></param>
	/// <param name="ref2"></param>
	/// <returns></returns>
	friend class avarageCompare;

	friend class GameManager;

	friend class Judgment;

	friend  ostream& operator<<(ostream& out, const Student& st);

	/// <summary>
	/// ƽ���ֽ���
	/// </summary>
	/// <param name="fir"></param>
	/// <param name="sec"></param>
	/// <returns></returns>
	bool operator()(const Student& fir, const  Student& sec) const;

	Student();

	~Student();
};

