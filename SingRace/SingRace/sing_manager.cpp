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
	cout << "******** 0.退出演讲系统 **********" << endl;
	cout << "******** 1.开始演讲比赛 **********" << endl;
	cout << "******** 2.查看往届记录 **********" << endl;
	cout << "******** 3.清空比赛记录 **********" << endl;
	cout << "********************************" << endl;
	cout << endl;
}

void SingManager::exsitSystem()
{
	cout << "欢迎下次使用" << endl;
	exit(0);
}

void SingManager::initSpeech()
{

	//容器都置空
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
		string name = "选手";
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
	//第一轮比赛
	//1.抽签
	this->index = 1;
	this->speechDraw();
	//2.比赛
	this->speechContest();
	//3.显示结果
	this->showScore();
	//4.第二轮比赛
	this->index++;
	this->speechDraw();
	this->speechContest();
	showScore();
	//4.保存
	this->saveRecord();

	this->initSpeech();

	this->createSpeaker();

	this->loadRecord();
}

void SingManager::speechDraw()
{
	cout << "第 <<" << this->index << " >> 轮比赛选手正在抽签" << endl;
	cout << "-----------------------" << endl;
	cout << "抽签后演讲顺序如下" << endl;
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
	cout << "--------------第" << this->index << "轮正式比赛开始：-----------------" << endl;
	multimap<double, int, greater<double>>groupScore; //临时容器，保存key分数 value的选手编号

	int num = 0;
	vector <int> src; //比赛的人员容器
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

		//评委打分
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
			cout << "第" << num / 6 << "小组比赛名次：" << endl;
			for (multimap<double, int, greater<double>>::iterator i = groupScore.begin(); i != groupScore.end(); i++)
			{
				cout << "编号：" << i->second << "姓名：" << this->speakers[i->second].name << "成绩：" << this->speakers[i->second].scores[this->index - 1] << endl;
			};
			int count = 0;
			//取前三名
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

			cout << "------------------第 " << this->index << " 轮比赛比完毕------------------" << endl;
			system("pause");

		}

	}

}

void SingManager::showScore()
{
	cout << "---------------第" << this->index << "轮晋级--------------" << endl;
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
		cout << "选手编号：" << *i << "姓名" << speakers[*i].name << "得分" << speakers[*i].scores[this->index - 1] << endl;

	}
	cout << endl;
	system("pause");

}

void SingManager::saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);//用输出的方式打开文件

	for (vector<int>::iterator i = v3.begin(); i < v3.end(); i++)
	{
		ofs << *i << "," << speakers[*i].scores[1] << ",";
	}
	ofs << endl;
	ofs.close();
	this->fileIsEmpty = false;
	cout << "记录已经保存" << endl;
}

void SingManager::showRecord()
{
	if (this->fileIsEmpty) {
		cout << "文件为空或不存在" << endl;
		return;
	}

	for (size_t i = 0; i < this->record.size(); i++)
	{
		cout << "第" << i + 1 << "届" <<
			"冠军编号" << this->record[i][0] << " 得分" << this->record[i][1] <<
			"冠军编号" << this->record[i][2] << " 得分" << this->record[i][3] <<
			"冠军编号" << this->record[i][4] << " 得分" << this->record[i][5] << endl;
	}
}

void SingManager::clearRecord()
{
	cout << "确认清空？" << endl;
	cout << "1 确认" << endl;
	cout << "2 返回" << endl;
	int select = 0;
	cin >> select;
	if (select == 1) {
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		this->initSpeech();

		this->createSpeaker();

		this->loadRecord();

		cout << "清空成功" << endl;
	}

}

void SingManager::loadRecord()
{
	ifstream ifs("speech.csv", ios::in);
	if (!ifs.is_open()) {
		this->fileIsEmpty = true;
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "文件为空" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
	this->fileIsEmpty = false;

	ifs.putback(ch); //读取的单个字符放回去
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
			pos = data.find(",", start); //从0开始查找 ‘,’
			if (pos == -1)
			{
				break;
			}
			string tmp = data.substr(start, pos - start); //找到了进行分割， 参数1 起始位置，参数2 截取长度

			v.push_back(tmp);
			start = pos + 1;
		}
		this->record.insert(make_pair(index, v));
		index++;
	}
	ifs.close();
}

