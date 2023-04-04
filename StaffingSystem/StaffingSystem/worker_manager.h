#include <iostream>
using namespace std;
#include "worker.h"

constexpr auto FILE_NAME = "empFile.txt";

class WorkerManager {
public:

	//记录文件中的人数个数
	int empNum;

	//员工数组的指针
	Worker** empArray;

	//标志文件是否为空
	bool fileIsEmpty;

	//构造函数
	WorkerManager();

	//析构函数
	~WorkerManager();

	//展示菜单列表
	void showMenu();

	//退出程序
	void exsitSystem();

	//新增员工
	void addEmp();

	//保存文件
	void save();

	//统计人数
	int getEmpNum();

	//初始化员工
	void initEmp();

	//显示职工
	void showEmp();

	//删除职工
	void delEmp();

	//按照职工编号判断职工是否存在，若存在返回职工在数组中位置，不存在返回-1
	int isExsit(int id);

	//修改职工信息
	void modEmp();

	//查找职工信息 eg：只做 id 查询 demo
	void finEmp();

	//排序
	void sortEmp();

	//清空文件
	void clearFile();
};

