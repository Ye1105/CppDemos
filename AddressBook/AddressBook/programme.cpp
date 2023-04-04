#include <iostream>
#include <string>
#include "common.h"

using namespace std;

#define MAX 1000

/// <summary>
/// ��ϵ�˽ṹ��
/// </summary>
struct Person {
	//����
	string name;
	//1 �� 2 Ů
	int sex;
	//����
	int age;
	//�绰
	string phone;
	//��ַ
	string address;
};

/// <summary>
/// ͨѶ¼�ṹ��
/// </summary>
struct  AddressBook {
	//ͨѶ¼�б�����ϵ������
	struct Person personArray[MAX];

	//ͨѶ¼�е�ǰ��¼����ϵ�˸���
	int size = 0;
};

/// <summary>
/// �����ϵ��
/// </summary>
/// <param name="abs"></param>
void addPerson(AddressBook* abs) {
	//�ж�ͨѶ¼�Ƿ��Ѿ�����
	if (abs->size == MAX) {
		cout << "ͨѶ¼�������޷����" << endl;
		return;
	}
	else
	{
		//��Ӿ������ϵ��
		string name;
		cout << "������������";
		cin >> name;
		abs->personArray[abs->size].name = name;

		int sex;
		while (true)
		{
			cout << "�������Ա� 1 ���� 2 (1�����У�2����Ů)��";
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->size].sex = sex;
				break;
			}
			else {
				cout << "�����ʽ����ȷ���Ա�������1��2,1�������ԣ�2����Ů��" << endl;
				continue;
			}
		};


		int age;
		cout << "���������䣺";
		cin >> age;
		abs->personArray[abs->size].age = age;

		string phone;
		cout << "�������ֻ��ţ�";
		cin >> phone;
		abs->personArray[abs->size].phone = phone;


		string address;
		cout << "�������ַ��";
		cin >> address;
		abs->personArray[abs->size].address = address;


		//���ݳ���+1
		abs->size++;


		cout << "��ϵ��������" << endl;
	}
}

//չʾ�б�
void showPerson(AddressBook* abs) {
	if (abs->size == 0) {
		cout << "������ϵ��" << endl;
		return;
	}

	for (int i = 0; i < abs->size; i++)
	{
		cout << abs->personArray[i].name << '\t'
			<< (abs->personArray[i].sex == 1 ? "��" : "Ů") << '\t'
			<< abs->personArray[i].age << '\t'
			<< abs->personArray[i].phone << '\t'
			<< abs->personArray[i].address << '\t'
			<< endl;
	}
}

/// <summary>
/// ��ǰ�û��Ƿ����
/// </summary>
/// <param name="abs"></param>
/// <param name="name"></param>
/// <returns></returns>
int isExsit(AddressBook* abs, string name) {
	int i = 0;
	while (i < abs->size)
	{
		if (abs->personArray[i].name == name) {
			return i;
		}
		i++;
	}
	return -1;
}


/// <summary>
/// ɾ����ϵ��
/// </summary>
/// <param name="abs"></param>
void deletePerson(AddressBook* abs) {

	//�����������Ƿ���ڵ�ǰ����
	if (abs->size == 0) {
		cout << "������ϵ��" << endl;
		return;
	}

	//��ȡҪ�����û�������
	string name;
	cout << "������Ҫɾ�����û����ƣ�";
	cin >> name;

	//�ж������Ƿ����
	int flag = isExsit(abs, name);

	if (flag == -1) {
		cout << "���������ƣ�" << name << endl;
		return;
	}
	else
	{
		int i = 0;
		while (i < abs->size)
		{
			if (abs->personArray[i].name == name) {
				//�ӵ�ǰλ�ÿ�ʼ���е�������ǰ�ƶ�һλ	
				int j = i;
				while (j < abs->size - 1)
				{
					abs->personArray[j] = abs->personArray[j + 1];
					j++;
				}
				abs->size--;
				continue;  //���ڶ����ͬ���Ƶĳ�Աʱ�����ɾ��
			};
			i++;
		}
	}
}


void selectPerson(AddressBook* abs) {
	//�����������Ƿ���ڵ�ǰ����
	if (abs->size == 0) {
		cout << "������ϵ��" << endl;
		return;
	}

	//��ȡҪ�����û�������
	string name;
	cout << "������Ҫ���ҵ��û����ƣ�";
	cin >> name;

	//�ж������Ƿ����
	int flag = isExsit(abs, name);

	if (flag == -1) {
		cout << "���������ƣ�" << name << endl;
		return;
	}
	else {
		int i = 0;
		while (i < abs->size)
		{
			if (abs->personArray[i].name == name) {
				cout << abs->personArray[i].name << '\t'
					<< (abs->personArray[i].sex == 1 ? "��" : "Ů") << '\t'
					<< abs->personArray[i].age << '\t'
					<< abs->personArray[i].phone << '\t'
					<< abs->personArray[i].address << '\t'
					<< endl;
			};
			i++;
		}
	}
}


/// <summary>
/// �޸��û�
/// </summary>
/// <param name="abs"></param>
void modifyPeron(AddressBook* abs) {
	//�����������Ƿ���ڵ�ǰ����
	if (abs->size == 0) {
		cout << "������ϵ��" << endl;
		return;
	}

	//��ȡҪ�����û�������
	string name;
	cout << "������Ҫ�޸ĵ��û����ƣ�";
	cin >> name;

	//�ж������Ƿ����
	int flag = isExsit(abs, name);

	if (flag == -1) {
		cout << "���������ƣ�" << name << endl;
		return;
	}
	else
	{
		//eg: �����ṹ���Ա���޸Ĳ�������
		string phone;
		cout << "�������µ��ֻ��ţ�";
		cin >> phone;
		abs->personArray[flag].phone = phone;
	}
}

void clearPerson(AddressBook* abs) {
	abs->size = 0;
}

int  main() {
	try
	{
		//������ʼ�û���Ϣ�б�
		AddressBook abs;
		//��ʼ��ͨѶ¼�е�ǰ��Ա����


		int num = -1;

		while (true)
		{
			switch (num)
			{
			case -1:
				system("cls"); //��������
				showMenu();
				cout << "���������ָ��,�� enter ȷ������" << endl;
				cin >> num;
				continue;

			case 0:
				cout << "��ӭ�´�ʹ��" << endl;
				return 0;

			case 1:
				//��Ӳ���
				addPerson(&abs); //���õ�ַ���ݣ���������ʵ��
				break;
			case 2:
				//չʾ����
				showPerson(&abs);
				break;
			case 3:
				//ɾ������
				deletePerson(&abs);
				break;
			case 4:
				//���Ҳ���
				selectPerson(&abs);
				break;
			case 5:
				//�޸Ĳ���
				modifyPeron(&abs);
				break;
			case 6:
				//�����ϵ��
				clearPerson(&abs);
				break;

			default:
				cout << "ָ�����" << endl;
				break;
			}

			system("pause");
			num = -1;
		};
	}
	catch (const std::exception&)
	{

	}
	return 0;
}