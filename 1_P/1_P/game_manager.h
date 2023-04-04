#pragma once
#include "student.h"
#include "extend.h"
#include "judgment.h"
#include <map>
#include <vector>
#include <set>
#include <random>

/// <summary>
/// ƽ�����������
/// </summary>
class avarageCompare {
public:
	bool operator()(const pair<int, Student>& ref1, const pair<int, Student>& ref2) const {
		return ref1.second.avarage > ref2.second.avarage;
	}
};

class GameManager {
public:

	//�����׶�
	enum stage {
		first = 1,
		end = 2
	};

	/// <summary>
	/// �����б�
	/// </summary>
	vector<Judgment> jdt;

	/// <summary>
	/// ����ѧ���б�
	/// </summary>
	vector<Student> stu;

	map< int, Student> mapStu;
	/// <summary>
	/// ��һ�ֱ�����Ա�б�
	/// </summary>
	vector <pair<int, Student>> mapStuFirst;

	/// <summary>
	/// �ڶ��ֱ�����Ա�б�
	/// </summary>
	vector <pair<int, Student>> mapStuSecond;

	/// <summary>
	/// ��ʤ�ֳ�Ա�б�
	/// </summary>
	vector <pair<int, Student>> mapStuFinal;

	//���캯��
	GameManager(vector<Student>&, vector<Judgment>&);

	//����
	~GameManager();

	/// <summary>
	/// ��¼ 10001-10012 �����б���Ѿ���ѡ�е��б�
	/// </summary>
	set<int> nums;

	/// <summary>
	/// ��ǩ 10001-10012 �����б��������һ��
	/// </summary>
	/// <returns></returns>
	int randNumFun();

	/// <summary>
	/// ��ǩ
	/// </summary>
	void draw();

	/// <summary>
	/// ����
	/// </summary>
	void group();

	/// <summary>
	/// ��һ�����
	/// </summary>
	void groupOnRace();

	/// <summary>
	/// �ڶ������
	/// </summary>
	void groupOnRace2();


	/// <summary>
	/// ��ʤ�ֱ���
	/// </summary>
	void finalRace();

	/// <summary>
	/// ��ӡѧ����ֵ���б�
	/// </summary>
	/// <param name="maps"></param>
	void printMap(const map<int, Student>& maps);

	/// <summary>
	/// ��ӡѧ����ֵ���б�
	/// </summary>
	/// <param name="maps"></param>
	void printVectorPairs(const vector<pair<int, Student>>& maps);

	/// <summary>
	/// ��ӡ�����б�
	/// </summary>
	/// <param name="maps"></param>
	void  printMapJudgement(vector<Judgment>& maps);

};

