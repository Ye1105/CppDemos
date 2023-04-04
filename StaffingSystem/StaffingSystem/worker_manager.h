#include <iostream>
using namespace std;
#include "worker.h"

constexpr auto FILE_NAME = "empFile.txt";

class WorkerManager {
public:

	//��¼�ļ��е���������
	int empNum;

	//Ա�������ָ��
	Worker** empArray;

	//��־�ļ��Ƿ�Ϊ��
	bool fileIsEmpty;

	//���캯��
	WorkerManager();

	//��������
	~WorkerManager();

	//չʾ�˵��б�
	void showMenu();

	//�˳�����
	void exsitSystem();

	//����Ա��
	void addEmp();

	//�����ļ�
	void save();

	//ͳ������
	int getEmpNum();

	//��ʼ��Ա��
	void initEmp();

	//��ʾְ��
	void showEmp();

	//ɾ��ְ��
	void delEmp();

	//����ְ������ж�ְ���Ƿ���ڣ������ڷ���ְ����������λ�ã������ڷ���-1
	int isExsit(int id);

	//�޸�ְ����Ϣ
	void modEmp();

	//����ְ����Ϣ eg��ֻ�� id ��ѯ demo
	void finEmp();

	//����
	void sortEmp();

	//����ļ�
	void clearFile();
};

