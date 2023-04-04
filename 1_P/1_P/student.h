#pragma once
#include <string>
#include <deque>
using namespace std;
#include "extend.h"

class Student {
private:
	//编号
	int order;
	//姓名
	string name;
	//参赛顺序
	int randomOrder;
	//是否通过
	bool isPass;
	//评分列表
	deque<int> scores;
	//平均分
	int avarage; //accumulate

public:

	/// <summary>
	/// 全局函数：平均分排序规则
	/// </summary>
	/// <param name="ref1"></param>
	/// <param name="ref2"></param>
	/// <returns></returns>
	friend class avarageCompare;

	friend class GameManager;

	friend class Judgment;

	friend  ostream& operator<<(ostream& out, const Student& st);

	/// <summary>
	/// 平均分降序
	/// </summary>
	/// <param name="fir"></param>
	/// <param name="sec"></param>
	/// <returns></returns>
	bool operator()(const Student& fir, const  Student& sec) const;

	Student();

	~Student();
};

