#include "game_manager.h"
#include<vector>
#include <algorithm>
#include<iostream>
using namespace std;
#include<deque>
#include<numeric>
#include<functional>

GameManager::GameManager(vector<Student>& stu, vector<Judgment>& jdt)
{
	//��ʼ�������б�
	this->jdt = jdt;
	//��ӡ��ǩ�õ�ѧ���б�
	cout << "--------------- �������� -------------------" << endl;
	this->printMapJudgement(this->jdt);
	//��ʼ��ѧ���б�
	this->stu = stu;
}

GameManager::~GameManager()
{
}

void GameManager::draw()
{
	//����ѧ���б�
	if (!stu.empty()) {
		for (size_t i = 0; i < stu.size(); i++)
		{
			//��ȡ�����
			int rd = this->randNumFun();

			stu[i].randomOrder = rd;

			mapStu.insert(make_pair(rd, stu[i]));

			cout << stu[i].name << '\t' << stu[i].order << '\t' << stu[i].randomOrder << '\t' << stu[i].isPass << '\t' << stu[i].avarage << endl;
		}

		cout << "--------------- �ܲ�����Ա -------------------" << endl;
		//��ӡ��ǩ�õ�ѧ���б�
		this->printMap(mapStu);
	}
}

int GameManager::randNumFun() {
	random_device rd;
	default_random_engine eng(rd());
	uniform_int_distribution<int> distr(MIN, MAX);
	while (true)
	{
		pair<set<int>::iterator, bool> it = nums.insert(distr(eng));
		if (it.second)
			return *it.first;
	}
}

void GameManager::group() {
	//ͨ����ǩ���ɴ�С���з���

	//	vector <pair<int, Student>>

	for (map<int, Student>::iterator i = mapStu.begin(); i != mapStu.end(); i++)
	{
		pair<int, Student> p(i->first, i->second);
		if (i->first < 10007) {

			mapStuFirst.push_back(p);
		}
		else
		{
			mapStuSecond.push_back(p);
		}
	}

	cout << "--------------- ��һ�������Ա -------------------" << endl;
	this->printVectorPairs(mapStuFirst);

	cout << "--------------- �ڶ��������Ա -------------------" << endl;
	this->printVectorPairs(mapStuSecond);
}

ostream& operator<<(ostream& out, const Student& st)
{
	// TODO: �ڴ˴����� return ���
	return out << st.name << '\t' << st.order << '\t' << st.randomOrder << '\t' << st.isPass << '\t' << st.avarage;
}

ostream& operator<<(ostream& out, const Judgment& st) {
	return out << st.name << '\t' << st.order;
};


void GameManager::groupOnRace()
{
	//��ȡ��һ��Ĳ�����Ա
	//����
	for (vector<pair<int, Student>> ::iterator i = this->mapStuFirst.begin(); i != this->mapStuFirst.end(); i++)
	{
		for (vector<Judgment>::iterator j = this->jdt.begin(); j != this->jdt.end(); j++)
		{
			i->second.scores.push_back(j->postScore());
		}

		//�Է�����������
		sort(i->second.scores.begin(), i->second.scores.end(), less<int>());

		////�ų���С ��� ����
		i->second.scores.pop_front();
		i->second.scores.pop_back();

		////ƽ����
		i->second.avarage = accumulate(i->second.scores.begin(), i->second.scores.end(), 0) / (JUDGMENT_NUM - 2);
	}

	sort(mapStuFirst.begin(), mapStuFirst.end(), avarageCompare());

	mapStuFirst.resize(3);


	cout << "--------------- ��һ�������Ա -------------------" << endl;
	this->printVectorPairs(mapStuFirst);


}

void GameManager::groupOnRace2()
{
	//��ȡ��һ��Ĳ�����Ա
	//����
	for (vector<pair<int, Student>> ::iterator i = this->mapStuSecond.begin(); i != this->mapStuSecond.end(); i++)
	{
		for (vector<Judgment>::iterator j = this->jdt.begin(); j != this->jdt.end(); j++)
		{
			i->second.scores.push_back(j->postScore());
		}

		//�Է�����������
		sort(i->second.scores.begin(), i->second.scores.end(), less<int>());

		////�ų���С ��� ����
		i->second.scores.pop_front();
		i->second.scores.pop_back();

		////ƽ����
		i->second.avarage = accumulate(i->second.scores.begin(), i->second.scores.end(), 0) / (JUDGMENT_NUM - 2);
	}

	sort(mapStuSecond.begin(), mapStuSecond.end(), avarageCompare());

	mapStuSecond.resize(3);

	cout << "--------------- �ڶ��������Ա -------------------" << endl;
	this->printVectorPairs(mapStuSecond);
}

void GameManager::finalRace()
{
	mapStuFinal.resize(mapStuFirst.size() + mapStuSecond.size());
	//���һ�ֺ͵ڶ��ֱ���������Ա�ĺϼ�
	//set_union(mapStuFirst.begin(), mapStuFirst.end(), mapStuSecond.begin(), mapStuSecond.end(), mapStuFinal.begin());

	for (vector<pair<int, Student>> ::iterator i = this->mapStuFirst.begin(); i != this->mapStuFirst.end(); i++)
	{
		mapStuFinal.push_back(*i);
	}
	for (vector<pair<int, Student>> ::iterator i = this->mapStuSecond.begin(); i != this->mapStuSecond.end(); i++)
	{
		mapStuFinal.push_back(*i);
	}

	for (vector<pair<int, Student>> ::iterator i = this->mapStuFinal.begin(); i != this->mapStuFinal.end(); i++)
	{
		for (vector<Judgment>::iterator j = this->jdt.begin(); j != this->jdt.end(); j++)
		{
			i->second.scores.push_back(j->postScore());
		}

		//�Է�����������
		sort(i->second.scores.begin(), i->second.scores.end(), less<int>());

		////�ų���С ��� ����
		i->second.scores.pop_front();
		i->second.scores.pop_back();

		////ƽ����
		i->second.avarage = accumulate(i->second.scores.begin(), i->second.scores.end(), 0) / (JUDGMENT_NUM - 2);
	}

	sort(mapStuFinal.begin(), mapStuFinal.end(), avarageCompare());

	mapStuFinal.resize(3);

	cout << "--------------- ����ʤ��Ա -------------------" << endl;
	this->printVectorPairs(mapStuFinal);
}


void  GameManager::printMap(const map< int, Student>& maps) {
	for (map<int, Student>::const_iterator i = maps.begin(); i != maps.end(); i++)
	{
		cout << i->second << endl;
	}
}

void  GameManager::printVectorPairs(const vector<pair<int, Student>>& maps) {
	for (vector<pair<int, Student>> ::const_iterator i = maps.begin(); i != maps.end(); i++)
	{
		cout << i->second << endl;
	}
}


void  GameManager::printMapJudgement(vector<Judgment>& maps) {
	for (vector<Judgment>::const_iterator i = maps.begin(); i != maps.end(); i++)
	{
		cout << *i << endl;
	}
}