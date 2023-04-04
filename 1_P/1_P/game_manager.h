#pragma once
#include "student.h"
#include "extend.h"
#include "judgment.h"
#include <map>
#include <vector>
#include <set>
#include <random>

/// <summary>
/// 平均分排序规则
/// </summary>
class avarageCompare {
public:
	bool operator()(const pair<int, Student>& ref1, const pair<int, Student>& ref2) const {
		return ref1.second.avarage > ref2.second.avarage;
	}
};

class GameManager {
public:

	//比赛阶段
	enum stage {
		first = 1,
		end = 2
	};

	/// <summary>
	/// 裁判列表
	/// </summary>
	vector<Judgment> jdt;

	/// <summary>
	/// 参赛学生列表
	/// </summary>
	vector<Student> stu;

	map< int, Student> mapStu;
	/// <summary>
	/// 第一轮比赛成员列表
	/// </summary>
	vector <pair<int, Student>> mapStuFirst;

	/// <summary>
	/// 第二轮比赛成员列表
	/// </summary>
	vector <pair<int, Student>> mapStuSecond;

	/// <summary>
	/// 决胜局成员列表
	/// </summary>
	vector <pair<int, Student>> mapStuFinal;

	//构造函数
	GameManager(vector<Student>&, vector<Judgment>&);

	//析构
	~GameManager();

	/// <summary>
	/// 记录 10001-10012 标牌列表的已经被选中的列表
	/// </summary>
	set<int> nums;

	/// <summary>
	/// 抽签 10001-10012 标牌列表随机产生一项
	/// </summary>
	/// <returns></returns>
	int randNumFun();

	/// <summary>
	/// 抽签
	/// </summary>
	void draw();

	/// <summary>
	/// 分组
	/// </summary>
	void group();

	/// <summary>
	/// 第一组比赛
	/// </summary>
	void groupOnRace();

	/// <summary>
	/// 第二组比赛
	/// </summary>
	void groupOnRace2();


	/// <summary>
	/// 决胜局比赛
	/// </summary>
	void finalRace();

	/// <summary>
	/// 打印学生键值对列表
	/// </summary>
	/// <param name="maps"></param>
	void printMap(const map<int, Student>& maps);

	/// <summary>
	/// 打印学生键值对列表
	/// </summary>
	/// <param name="maps"></param>
	void printVectorPairs(const vector<pair<int, Student>>& maps);

	/// <summary>
	/// 打印裁判列表
	/// </summary>
	/// <param name="maps"></param>
	void  printMapJudgement(vector<Judgment>& maps);

};

