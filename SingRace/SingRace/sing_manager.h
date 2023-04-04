#pragma once
#include<iostream>
#include<vector>
#include "speaker.h"
#include <map>
using namespace std;

class SingManager {
public:
	vector<int> v1;

	vector<int> v2;

	vector<int> v3;

	map<int, Speaker> speakers;

	int index;


	SingManager();

	~SingManager();

	/// <summary>
	/// �˵�չʾ
	/// </summary>
	void showMenu();

	/// <summary>
	/// �˳�
	/// </summary>
	void exsitSystem();

	void initSpeech();

	void createSpeaker();

	void startSpeech();

	void speechDraw();

	void speechContest();

	void showScore();

	void saveRecord();

	void showRecord();

	void clearRecord();

	bool fileIsEmpty;

	map<int, vector<string>> record;

	void loadRecord();
};