#include <iostream>
#include <fstream>
#include "worker_manager.h"
#include "worker.h"
#include "manager.h"
#include "employee.h"
#include "boss.h"

using namespace std;

WorkerManager::WorkerManager() {

	cout << "WorkerManager 构造函数" << endl;


	ifstream ifs;
	ifs.open(FILE_NAME, ios::in);

	//文件不存在
	if (!ifs.is_open()) {

		cout << "文件不存在" << endl;

		this->empNum = 0; 		//初始化人数
		this->fileIsEmpty = true; 	//初始化文件为空标志
		this->empArray = NULL; 		//初始化数组指针
		ifs.close(); 	//关闭文件

		return;
	}

	//文件存在，并且没有记录
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "文件为空!" << endl;
		this->empNum = 0;
		this->fileIsEmpty = true;
		this->empArray = NULL;
		ifs.close();
		return;
	}
	ifs.close();

	//文件存在，且有数据
	int num = this->getEmpNum();
	cout << "职工个数为：" << num << endl;

	this->empNum = num;
	this->fileIsEmpty = false;
	this->empArray = new Worker * [this->empNum];

	initEmp();
}

WorkerManager::~WorkerManager() {
	cout << "WorkerManager 析构函数" << endl;

	if (this->empArray != NULL) {
		for (int i = 0; i < this->empNum; i++)
		{
			if (this->empArray[i] != NULL) {
				delete this->empArray[i];
			}
		}
		delete[] this->empArray;
		this->empArray = NULL;
		//this->empNum = 0;
		//this->fileIsEmpty = true;
	}
}

void WorkerManager::showMenu() {
	cout << "********************************" << endl;
	cout << "******** 0.退出职工系统 **********" << endl;
	cout << "******** 1.添加职工信息 **********" << endl;
	cout << "******** 2.显示职工信息 **********" << endl;
	cout << "******** 3.删除职工信息 **********" << endl;
	cout << "******** 4.查找职工信息 **********" << endl;
	cout << "******** 5.修改职工信息 **********" << endl;
	cout << "******** 6.按照编号排序 **********" << endl;
	cout << "******** 7.清空所有文档 **********" << endl;
	cout << "********************************" << endl;
	cout << endl;
}

void WorkerManager::exsitSystem() {
	cout << "欢迎下次使用" << endl;
	exit(0);
}

void WorkerManager::addEmp()
{

	cout << "请输入增加职工数量" << endl;

	int addNum = 0;
	cin >> addNum;

	if (addNum > 0) {
		//计算新空间大小
		int newSize = this->empNum + addNum;

		//开辟新空间
		Worker** newSpace = new Worker * [newSize];

		//将原空间下内容存放到新空间下
		if (this->empArray != NULL) {
			for (int i = 0; i < empNum; i++)
			{
				newSpace[i] = this->empArray[i];
			}
		}

		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "请输入第" << i + 1 << "个新职工编号：" << endl;
			cin >> id;

			cout << "请输入第" << i + 1 << "个新职工姓名：" << endl;
			cin >> name;

			cout << "请输入第" << i + 1 << "个新职工岗位：" << endl;
			cout << "1. 普通职工" << endl;
			cout << "2. 经理" << endl;
			cout << "3. 老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
			{
				//普通员工
				worker = new Emoployee(id, name, dSelect);
				break;
			}
			break;
			case 2:
			{
				//经理
				worker = new Manager(id, name, dSelect);
				break;
			}
			break;
			case 3:
			{
				//老板
				worker = new Boss(id, name, dSelect);
				break;
			}
			break;
			default:
				break;
			}
			newSpace[this->empNum + i] = worker;
		}

		//释放原有的空间
		//delete empArray;  //错误，释放数组要用 delete[]
		delete[] this->empArray;

		//更新空间的指向
		this->empArray = newSpace;

		//更新职工的数量
		this->empNum = newSize;

		//更新职工不为空标志
		this->fileIsEmpty = false;

		//保存到文件中
		save();

		cout << "添加成功" << endl;
	}
	else {
		cout << "输入数据有误" << endl;
	}
}

void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILE_NAME, ios::out);
	for (int i = 0; i < this->empNum; i++)
	{
		ofs << this->empArray[i]->id << " "
			<< this->empArray[i]->name << " "
			<< this->empArray[i]->deptId << endl;
	}
	ofs.close();
}

int WorkerManager::getEmpNum()
{
	ifstream ifs;
	ifs.open(FILE_NAME, ios::in);

	int id;
	string name;
	int dId;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;
	}

	ifs.close();

	return num;
}

void WorkerManager::initEmp()
{
	ifstream ifs;
	ifs.open(FILE_NAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		switch (dId)
		{
		case 1:
		{
			worker = new Emoployee(id, name, dId);
			break;
		}
		case 2:
		{
			//经理
			worker = new Manager(id, name, dId);
			break;
		}
		break;
		case 3:
		{
			//老板
			worker = new Boss(id, name, dId);
			break;
		}
		break;
		default:
			break;
		}

		//存放在数组中
		this->empArray[index] = worker;

		index++;
	}
}


void WorkerManager::showEmp()
{
	if (this->fileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < this->empNum; i++)
		{
			//cout << "id：" << empArray[i]->id << "\tname：" << empArray[i]->name << "\t职位：" << (empArray[i]->deptId == 1 ? "职工" : (empArray[i]->deptId == 2 ? "经理" : "老板")) << endl;

			empArray[i]->showInfo();
		}
	}
}

void WorkerManager::delEmp()
{
	int number;
	cout << "请输入要删除的员工编号" << endl;
	cin >> number;

	int index = isExsit(number);

	if (index == -1)
	{
		cout << "员工不存在" << endl;
		return;
	}
	else {
		for (int i = index; i < empNum - 1; i++)
		{
			//数据迁移
			empArray[i] = empArray[i + 1];
		}

		this->empNum--;

		//数据同步更新到文件中
		save();

		cout << "数据删除成功" << endl;
	}
}

int WorkerManager::isExsit(int id)
{
	for (int i = 0; i < empNum; i++)
	{
		if (empArray[i]->id == id)
			return i;
	}
	return -1;
}

void WorkerManager::modEmp()
{
	//0.文件不存在或者数据为空
	if (this->fileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
		return;
	}
	//1.输入用户id
	int number;
	cout << "请输入要修改的员工编号" << endl;
	cin >> number;
	//2.判断用户是否存在
	int index = isExsit(number);
	if (index == -1)
	{
		cout << "员工不存在" << endl;
		return;
	}
	else {
		//3.删除用户信息
		delete this->empArray[index];

		//4.重新创建新的对象
		int id = 0;
		cout << "请输入职工id" << endl;
		cin >> id;

		string name = "";
		cout << "请输入职工姓名：" << endl;
		cin >> name;

		int dId = 0;
		while (true)
		{
			cout << "请输入职工类别[1:职工 2:经理 3：老板]" << endl;
			cin >> dId;
			if (dId == 1 || dId == 2 || dId == 3)
				break;
		}
		Worker* worker = NULL;
		switch (dId)
		{
		case 1:
		{
			worker = new Emoployee(id, name, dId);
			break;
		}
		case 2:
		{
			//经理
			worker = new Manager(id, name, dId);
			break;
		}
		break;
		case 3:
		{
			//老板
			worker = new Boss(id, name, dId);
			break;
		}
		break;
		default:
			break;
		}

		empArray[index] = worker;

		//4.更新到文档
		save();

		cout << "修改信息成功" << endl;
	}
}

void WorkerManager::finEmp()
{
	//0.文件不存在或者数据为空
	if (this->fileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
		return;
	}
	//1.输入用户id
	int number;
	cout << "请输入要查找的员工编号" << endl;
	cin >> number;
	//2.判断用户是否存在
	int index = isExsit(number);
	if (index == -1)
	{
		cout << "员工不存在" << endl;
		return;
	}
	else {
		empArray[index]->showInfo();
	}
}

void WorkerManager::sortEmp()
{

	//0.文件不存在或者数据为空
	if (this->fileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
		return;
	}

	int order = 0;
	while (order != 1 && order != 2)
	{
		cout << "请选择排序方式 1：按职工工号升序 2：按职工工号降序" << endl;
		cin >> order;
	}

	for (int i = 0; i < empNum - 1; i++)
	{
		for (int j = 0; j < empNum - i - 1; j++)
		{
			if (order == 1) {
				if (empArray[j]->id > empArray[j + 1]->id) {
					Worker* temp = empArray[j];
					empArray[j] = empArray[j + 1];
					empArray[j + 1] = temp;
				}
			}
			else if (order == 2) {
				if (empArray[j]->id < empArray[j + 1]->id) {
					Worker* temp = empArray[j];
					empArray[j] = empArray[j + 1];
					empArray[j + 1] = temp;
				}
			}
		}
	}

	save();

	cout << "排序完成" << endl;
}

void WorkerManager::clearFile()
{
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;

	int select = 0;
	cin >> select;

	if (select == 1) {
		//1.打开模式 ios:trunc 如果存在删除文件并重新创建
		ofstream ofs(FILE_NAME, ios::trunc);
		ofs.close();

		//不对 应该释放掉数组中的每个堆对象
		//if (empArray != NULL) {
		//	delete[] empArray;
		//}

		if (this->empArray != NULL) {
			for (int i = 0; i < this->empNum; i++)
			{
				if (this->empArray[i] != NULL) {
					delete this->empArray[i];

				}
			}

			this->empNum = 0;
			delete[] this->empArray;
			this->empArray = NULL;
			this->fileIsEmpty = true;
		}

		cout << "清空成功" << endl;

	}
}
