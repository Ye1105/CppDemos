#include "sing_manager.h"
#include<algorithm>
#include<deque>
#include<numeric>
#include<fstream>

SingManager::SingManager()
{
	this->initSpeech();

	this->createSpeaker();

	this->loadRecord();


}

SingManager::~SingManager()
{
}

void SingManager::showMenu()
{
	cout << "********************************" << endl;
	cout << "******** 0.�˳��ݽ�ϵͳ **********" << endl;
	cout << "******** 1.��ʼ�ݽ����� **********" << endl;
	cout << "******** 2.�鿴�����¼ **********" << endl;
	cout << "******** 3.��ձ�����¼ **********" << endl;
	cout << "********************************" << endl;
	cout << endl;
}

void SingManager::exsitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	exit(0);
}

void SingManager::initSpeech()
{

	//�������ÿ�
	this->v1.clear();
	this->v2.clear();
	this->v3.clear();

	this->speakers.clear();
	this->record.clear();
	this->index = 1;
}

void SingManager::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];

		Speaker sp;
		sp.name = name;

		for (int i = 0; i < 2; i++)
		{
			sp.scores[i] = 0;
		}
		this->v1.push_back(i + 10001);

		this->speakers.insert(make_pair(i + 10001, sp));
	}
}

void SingManager::startSpeech()
{
	//��һ�ֱ���
	//1.��ǩ
	this->index = 1;
	this->speechDraw();
	//2.����
	this->speechContest();
	//3.��ʾ���
	this->showScore();
	//4.�ڶ��ֱ���
	this->index++;
	this->speechDraw();
	this->speechContest();
	showScore();
	//4.����
	this->saveRecord();

	this->initSpeech();

	this->createSpeaker();

	this->loadRecord();
}

void SingManager::speechDraw()
{
	cout << "�� <<" << this->index << " >> �ֱ���ѡ�����ڳ�ǩ" << endl;
	cout << "-----------------------" << endl;
	cout << "��ǩ���ݽ�˳������" << endl;
	if (this->index == 1) {
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it < v1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	else {
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it < v2.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "----------------------------" << endl;
	system("pause");
}

void SingManager::speechContest()
{
	cout << "--------------��" << this->index << "����ʽ������ʼ��-----------------" << endl;
	multimap<double, int, greater<double>>groupScore; //��ʱ����������key���� value��ѡ�ֱ��

	int num = 0;
	vector <int> src; //��������Ա����
	if (this->index == 1)
	{
		src = v1;
	}
	else {
		src = v2;
	}

	for (vector<int>::iterator i = src.begin(); i != src.end(); i++)
	{
		num++;

		//��ί���
		deque<double>d;

		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f; //600-1000
			d.push_back(score);
		}

		sort(d.begin(), d.end(), greater<double>());
		d.pop_front();
		d.pop_back();

		double sum = accumulate(d.begin(), d.end(), 0.0f);
		double avg = sum / (double)d.size();


		this->speakers[*i].scores[this->index - 1] = avg;

		groupScore.insert(make_pair(avg, *i));

		if (num % 6 == 0) {
			cout << "��" << num / 6 << "С��������Σ�" << endl;
			for (multimap<double, int, greater<double>>::iterator i = groupScore.begin(); i != groupScore.end(); i++)
			{
				cout << "��ţ�" << i->second << "������" << this->speakers[i->second].name << "�ɼ���" << this->speakers[i->second].scores[this->index - 1] << endl;
			};
			int count = 0;
			//ȡǰ����
			for (multimap<double, int, greater<double>>::iterator i = groupScore.begin(); i != groupScore.end() && count < 3; i++, count++)
			{
				if (this->index == 1) {
					v2.push_back((*i).second);
				}
				else
				{
					v3.push_back((*i).second);
				}
			}

			groupScore.clear();

			cout << "------------------�� " << this->index << " �ֱ��������------------------" << endl;
			system("pause");

		}

	}

}

void SingManager::showScore()
{
	cout << "---------------��" << this->index << "�ֽ���--------------" << endl;
	vector<int> v;
	if (this->index == 1) {
		v = v2;
	}
	else
	{
		v = v3;
	}

	for (vector<int>::iterator i = v.begin(); i != v.end(); i++)
	{
		cout << "ѡ�ֱ�ţ�" << *i << "����" << speakers[*i].name << "�÷�" << speakers[*i].scores[this->index - 1] << endl;

	}
	cout << endl;
	system("pause");

}

void SingManager::saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);//������ķ�ʽ���ļ�

	for (vector<int>::iterator i = v3.begin(); i < v3.end(); i++)
	{
		ofs << *i << "," << speakers[*i].scores[1] << ",";
	}
	ofs << endl;
	ofs.close();
	this->fileIsEmpty = false;
	cout << "��¼�Ѿ�����" << endl;
}

void SingManager::showRecord()
{
	if (this->fileIsEmpty) {
		cout << "�ļ�Ϊ�ջ򲻴���" << endl;
		return;
	}

	for (size_t i = 0; i < this->record.size(); i++)
	{
		cout << "��" << i + 1 << "��" <<
			"�ھ����" << this->record[i][0] << " �÷�" << this->record[i][1] <<
			"�ھ����" << this->record[i][2] << " �÷�" << this->record[i][3] <<
			"�ھ����" << this->record[i][4] << " �÷�" << this->record[i][5] << endl;
	}
}

void SingManager::clearRecord()
{
	cout << "ȷ����գ�" << endl;
	cout << "1 ȷ��" << endl;
	cout << "2 ����" << endl;
	int select = 0;
	cin >> select;
	if (select == 1) {
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		this->initSpeech();

		this->createSpeaker();

		this->loadRecord();

		cout << "��ճɹ�" << endl;
	}

}

void SingManager::loadRecord()
{
	ifstream ifs("speech.csv", ios::in);
	if (!ifs.is_open()) {
		this->fileIsEmpty = true;
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "�ļ�Ϊ��" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
	this->fileIsEmpty = false;

	ifs.putback(ch); //��ȡ�ĵ����ַ��Ż�ȥ
	string data;
	int  index = 0;
	while (ifs >> data)
	{
		//cout << data << endl;
		vector<string>v;
		int pos = -1;
		int start = 0;
		while (true)
		{
			pos = data.find(",", start); //��0��ʼ���� ��,��
			if (pos == -1)
			{
				break;
			}
			string tmp = data.substr(start, pos - start); //�ҵ��˽��зָ ����1 ��ʼλ�ã�����2 ��ȡ����

			v.push_back(tmp);
			start = pos + 1;
		}
		this->record.insert(make_pair(index, v));
		index++;
	}
	ifs.close();
}

