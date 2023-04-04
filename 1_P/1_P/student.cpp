#include "student.h"
#include <ctime>

bool Student::operator()(const Student& fir, const Student& sec) const
{
	return fir.avarage > sec.avarage;
}



Student::Student()
{
	this->order = rand();
	this->name = "student_" + to_string(this->order);
	this->isPass = 0;
	this->avarage = 0;
	this->randomOrder = 0;
}

Student::~Student()
{
}





