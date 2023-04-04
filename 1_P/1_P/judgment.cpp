#include "judgment.h"
#include <ctime>

int Judgment::postScore()
{
	//rand() % (b-a+1)+ a   a~b 的随机整数
	//1-100
	int num = rand() % 100 + 1;
	return num;
}

Judgment::Judgment()
{
	this->order = rand();
	this->name = "judge_" + to_string(this->order);
}

Judgment::~Judgment()
{
}