#include <iostream>
#include <string>
#include "common.h"

using namespace std;

#define MAX 1000

/// <summary>
/// 联系人结构体
/// </summary>
struct Person {
	//姓名
	string name;
	//1 男 2 女
	int sex;
	//年龄
	int age;
	//电话
	string phone;
	//地址
	string address;
};

/// <summary>
/// 通讯录结构体
/// </summary>
struct  AddressBook {
	//通讯录中保存联系人数组
	struct Person personArray[MAX];

	//通讯录中当前记录的联系人个数
	int size = 0;
};

/// <summary>
/// 添加联系人
/// </summary>
/// <param name="abs"></param>
void addPerson(AddressBook* abs) {
	//判断通讯录是否已经满了
	if (abs->size == MAX) {
		cout << "通讯录已满，无法添加" << endl;
		return;
	}
	else
	{
		//添加具体的联系人
		string name;
		cout << "请输入姓名：";
		cin >> name;
		abs->personArray[abs->size].name = name;

		int sex;
		while (true)
		{
			cout << "请输入性别 1 或者 2 (1代表男，2代表女)：";
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->size].sex = sex;
				break;
			}
			else {
				cout << "输入格式不正确：性别请输入1或2,1代表男性，2代表女性" << endl;
				continue;
			}
		};


		int age;
		cout << "请输入年龄：";
		cin >> age;
		abs->personArray[abs->size].age = age;

		string phone;
		cout << "请输入手机号：";
		cin >> phone;
		abs->personArray[abs->size].phone = phone;


		string address;
		cout << "请输入地址：";
		cin >> address;
		abs->personArray[abs->size].address = address;


		//数据长度+1
		abs->size++;


		cout << "联系人添加完成" << endl;
	}
}

//展示列表
void showPerson(AddressBook* abs) {
	if (abs->size == 0) {
		cout << "暂无联系人" << endl;
		return;
	}

	for (int i = 0; i < abs->size; i++)
	{
		cout << abs->personArray[i].name << '\t'
			<< (abs->personArray[i].sex == 1 ? "男" : "女") << '\t'
			<< abs->personArray[i].age << '\t'
			<< abs->personArray[i].phone << '\t'
			<< abs->personArray[i].address << '\t'
			<< endl;
	}
}

/// <summary>
/// 当前用户是否存在
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
/// 删除联系人
/// </summary>
/// <param name="abs"></param>
void deletePerson(AddressBook* abs) {

	//遍历数组中是否存在当前名称
	if (abs->size == 0) {
		cout << "暂无联系人" << endl;
		return;
	}

	//获取要输入用户的名称
	string name;
	cout << "请输入要删除的用户名称：";
	cin >> name;

	//判断名称是否存在
	int flag = isExsit(abs, name);

	if (flag == -1) {
		cout << "不存在名称：" << name << endl;
		return;
	}
	else
	{
		int i = 0;
		while (i < abs->size)
		{
			if (abs->personArray[i].name == name) {
				//从当前位置开始所有的索引往前移动一位	
				int j = i;
				while (j < abs->size - 1)
				{
					abs->personArray[j] = abs->personArray[j + 1];
					j++;
				}
				abs->size--;
				continue;  //存在多个相同名称的成员时，多次删除
			};
			i++;
		}
	}
}


void selectPerson(AddressBook* abs) {
	//遍历数组中是否存在当前名称
	if (abs->size == 0) {
		cout << "暂无联系人" << endl;
		return;
	}

	//获取要输入用户的名称
	string name;
	cout << "请输入要查找的用户名称：";
	cin >> name;

	//判断名称是否存在
	int flag = isExsit(abs, name);

	if (flag == -1) {
		cout << "不存在名称：" << name << endl;
		return;
	}
	else {
		int i = 0;
		while (i < abs->size)
		{
			if (abs->personArray[i].name == name) {
				cout << abs->personArray[i].name << '\t'
					<< (abs->personArray[i].sex == 1 ? "男" : "女") << '\t'
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
/// 修改用户
/// </summary>
/// <param name="abs"></param>
void modifyPeron(AddressBook* abs) {
	//遍历数组中是否存在当前名称
	if (abs->size == 0) {
		cout << "暂无联系人" << endl;
		return;
	}

	//获取要输入用户的名称
	string name;
	cout << "请输入要修改的用户名称：";
	cin >> name;

	//判断名称是否存在
	int flag = isExsit(abs, name);

	if (flag == -1) {
		cout << "不存在名称：" << name << endl;
		return;
	}
	else
	{
		//eg: 其他结构体成员的修改不做举例
		string phone;
		cout << "请输入新的手机号：";
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
		//声明初始用户信息列表
		AddressBook abs;
		//初始化通讯录中当前人员个数


		int num = -1;

		while (true)
		{
			switch (num)
			{
			case -1:
				system("cls"); //清屏操作
				showMenu();
				cout << "请输入操作指令,按 enter 确定输入" << endl;
				cin >> num;
				continue;

			case 0:
				cout << "欢迎下次使用" << endl;
				return 0;

			case 1:
				//添加操作
				addPerson(&abs); //利用地址传递，可以修饰实参
				break;
			case 2:
				//展示操作
				showPerson(&abs);
				break;
			case 3:
				//删除操作
				deletePerson(&abs);
				break;
			case 4:
				//查找操作
				selectPerson(&abs);
				break;
			case 5:
				//修改操作
				modifyPeron(&abs);
				break;
			case 6:
				//清空联系人
				clearPerson(&abs);
				break;

			default:
				cout << "指令不存在" << endl;
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