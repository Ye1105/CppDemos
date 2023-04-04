#include <iostream>
#include <fstream>
#include "worker_manager.h"
#include "worker.h"
#include "manager.h"
#include "employee.h"
#include "boss.h"

using namespace std;

WorkerManager::WorkerManager() {

	cout << "WorkerManager ���캯��" << endl;


	ifstream ifs;
	ifs.open(FILE_NAME, ios::in);

	//�ļ�������
	if (!ifs.is_open()) {

		cout << "�ļ�������" << endl;

		this->empNum = 0; 		//��ʼ������
		this->fileIsEmpty = true; 	//��ʼ���ļ�Ϊ�ձ�־
		this->empArray = NULL; 		//��ʼ������ָ��
		ifs.close(); 	//�ر��ļ�

		return;
	}

	//�ļ����ڣ�����û�м�¼
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "�ļ�Ϊ��!" << endl;
		this->empNum = 0;
		this->fileIsEmpty = true;
		this->empArray = NULL;
		ifs.close();
		return;
	}
	ifs.close();

	//�ļ����ڣ���������
	int num = this->getEmpNum();
	cout << "ְ������Ϊ��" << num << endl;

	this->empNum = num;
	this->fileIsEmpty = false;
	this->empArray = new Worker * [this->empNum];

	initEmp();
}

WorkerManager::~WorkerManager() {
	cout << "WorkerManager ��������" << endl;

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
	cout << "******** 0.�˳�ְ��ϵͳ **********" << endl;
	cout << "******** 1.���ְ����Ϣ **********" << endl;
	cout << "******** 2.��ʾְ����Ϣ **********" << endl;
	cout << "******** 3.ɾ��ְ����Ϣ **********" << endl;
	cout << "******** 4.����ְ����Ϣ **********" << endl;
	cout << "******** 5.�޸�ְ����Ϣ **********" << endl;
	cout << "******** 6.���ձ������ **********" << endl;
	cout << "******** 7.��������ĵ� **********" << endl;
	cout << "********************************" << endl;
	cout << endl;
}

void WorkerManager::exsitSystem() {
	cout << "��ӭ�´�ʹ��" << endl;
	exit(0);
}

void WorkerManager::addEmp()
{

	cout << "����������ְ������" << endl;

	int addNum = 0;
	cin >> addNum;

	if (addNum > 0) {
		//�����¿ռ��С
		int newSize = this->empNum + addNum;

		//�����¿ռ�
		Worker** newSpace = new Worker * [newSize];

		//��ԭ�ռ������ݴ�ŵ��¿ռ���
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

			cout << "�������" << i + 1 << "����ְ����ţ�" << endl;
			cin >> id;

			cout << "�������" << i + 1 << "����ְ��������" << endl;
			cin >> name;

			cout << "�������" << i + 1 << "����ְ����λ��" << endl;
			cout << "1. ��ְͨ��" << endl;
			cout << "2. ����" << endl;
			cout << "3. �ϰ�" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
			{
				//��ͨԱ��
				worker = new Emoployee(id, name, dSelect);
				break;
			}
			break;
			case 2:
			{
				//����
				worker = new Manager(id, name, dSelect);
				break;
			}
			break;
			case 3:
			{
				//�ϰ�
				worker = new Boss(id, name, dSelect);
				break;
			}
			break;
			default:
				break;
			}
			newSpace[this->empNum + i] = worker;
		}

		//�ͷ�ԭ�еĿռ�
		//delete empArray;  //�����ͷ�����Ҫ�� delete[]
		delete[] this->empArray;

		//���¿ռ��ָ��
		this->empArray = newSpace;

		//����ְ��������
		this->empNum = newSize;

		//����ְ����Ϊ�ձ�־
		this->fileIsEmpty = false;

		//���浽�ļ���
		save();

		cout << "��ӳɹ�" << endl;
	}
	else {
		cout << "������������" << endl;
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
			//����
			worker = new Manager(id, name, dId);
			break;
		}
		break;
		case 3:
		{
			//�ϰ�
			worker = new Boss(id, name, dId);
			break;
		}
		break;
		default:
			break;
		}

		//�����������
		this->empArray[index] = worker;

		index++;
	}
}


void WorkerManager::showEmp()
{
	if (this->fileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < this->empNum; i++)
		{
			//cout << "id��" << empArray[i]->id << "\tname��" << empArray[i]->name << "\tְλ��" << (empArray[i]->deptId == 1 ? "ְ��" : (empArray[i]->deptId == 2 ? "����" : "�ϰ�")) << endl;

			empArray[i]->showInfo();
		}
	}
}

void WorkerManager::delEmp()
{
	int number;
	cout << "������Ҫɾ����Ա�����" << endl;
	cin >> number;

	int index = isExsit(number);

	if (index == -1)
	{
		cout << "Ա��������" << endl;
		return;
	}
	else {
		for (int i = index; i < empNum - 1; i++)
		{
			//����Ǩ��
			empArray[i] = empArray[i + 1];
		}

		this->empNum--;

		//����ͬ�����µ��ļ���
		save();

		cout << "����ɾ���ɹ�" << endl;
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
	//0.�ļ������ڻ�������Ϊ��
	if (this->fileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
		return;
	}
	//1.�����û�id
	int number;
	cout << "������Ҫ�޸ĵ�Ա�����" << endl;
	cin >> number;
	//2.�ж��û��Ƿ����
	int index = isExsit(number);
	if (index == -1)
	{
		cout << "Ա��������" << endl;
		return;
	}
	else {
		//3.ɾ���û���Ϣ
		delete this->empArray[index];

		//4.���´����µĶ���
		int id = 0;
		cout << "������ְ��id" << endl;
		cin >> id;

		string name = "";
		cout << "������ְ��������" << endl;
		cin >> name;

		int dId = 0;
		while (true)
		{
			cout << "������ְ�����[1:ְ�� 2:���� 3���ϰ�]" << endl;
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
			//����
			worker = new Manager(id, name, dId);
			break;
		}
		break;
		case 3:
		{
			//�ϰ�
			worker = new Boss(id, name, dId);
			break;
		}
		break;
		default:
			break;
		}

		empArray[index] = worker;

		//4.���µ��ĵ�
		save();

		cout << "�޸���Ϣ�ɹ�" << endl;
	}
}

void WorkerManager::finEmp()
{
	//0.�ļ������ڻ�������Ϊ��
	if (this->fileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
		return;
	}
	//1.�����û�id
	int number;
	cout << "������Ҫ���ҵ�Ա�����" << endl;
	cin >> number;
	//2.�ж��û��Ƿ����
	int index = isExsit(number);
	if (index == -1)
	{
		cout << "Ա��������" << endl;
		return;
	}
	else {
		empArray[index]->showInfo();
	}
}

void WorkerManager::sortEmp()
{

	//0.�ļ������ڻ�������Ϊ��
	if (this->fileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
		return;
	}

	int order = 0;
	while (order != 1 && order != 2)
	{
		cout << "��ѡ������ʽ 1����ְ���������� 2����ְ�����Ž���" << endl;
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

	cout << "�������" << endl;
}

void WorkerManager::clearFile()
{
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;

	int select = 0;
	cin >> select;

	if (select == 1) {
		//1.��ģʽ ios:trunc �������ɾ���ļ������´���
		ofstream ofs(FILE_NAME, ios::trunc);
		ofs.close();

		//���� Ӧ���ͷŵ������е�ÿ���Ѷ���
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

		cout << "��ճɹ�" << endl;

	}
}
