#pragma once
#include <string>
using namespace std;

/// <summary>
/// Worker ������
/// </summary>
class Worker {
public:

	//��ʾ������Ϣ
	virtual void showInfo() = 0;

	//��ȡ��λ����
	virtual string getDeptName() = 0;

	//ְ�����
	int id;
	//ְ������
	string name;
	//ְ�����ڲ������Ʊ��
	int deptId;
};