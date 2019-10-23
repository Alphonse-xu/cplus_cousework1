#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<fstream>
#include<iomanip>

using namespace std;
/*
void solution::mapsequence() {
	int maxCount = 0;
	int recordCount = 1;

	for (int i = 0; i < dp.size() - 1; i++) {

		if (dp[i] == dp[i + 1] - 1)
			recordCount++;
		else {
			recordCount = 1;
			continue;
		}
		if (recordCount > maxCount)
			maxCount = recordCount;
	}

	if (maxCount < N)
		return false;
	else
		return true;
	printcon();
}*/
void solution::readfile() {
	//int total;//读文件第一行判断有几个配置
	ifstream ifile("15puzzle.txt", ios::in);
	if (!ifile) {
		cout << "error opening destination file." << endl;
		return;
	}
	int a;
	ifile >> config_num;
	cout << "total configuration number is " << config_num << endl;
	int y = 0;
	for (size_t i = 0; i < config_num; i++)
	{
		spuzzle.resize(config_num);
		for (size_t j = 0; j < puzzlenum; j++)
		{
			ifile >> y;
			spuzzle[i].push_back(y); //spuzzle[i][x] = y;
			if (ifile.eof() != 0) break;
		}
		if (ifile.eof() != 0) break;//这里好像跳出判定不对
	}
	ifile.close();
	for (int i = 0; i < config_num; i++)
	{
		for (size_t j = 0; j < puzzlenum; j++)
		{
			cout << spuzzle[i][j] << " ";
		} 
		cout << endl;
	}
}
/*打印到屏幕上（写一个重载）
void solution::printcon() {
				for (size_t i = 0; i < 3; i++)
			{
				for (size_t j = 0; j < 3; j++)
				{
					if ((j + 3 * i) == 8) ofile << setw(3) << setiosflags(ios::left);
					else
						ofile << setw(3) << setiosflags(ios::left) << puzzlestr[j + 3 * i];
				}
				ofile << endl;
			}
}*/
/*
void solution::creatfile() {
	int par = ios_base::app;
	//if (cond) 
		//par = ios::out | std::ios_base::app;
	ofstream ofile("solution_file.txt", par);
	if (!ofile) {
		cout << "error opening destination file." << endl;
		return;
	}
	//if (!cond)//选写 需要读文件判定里面有没有写入过
	ofile << config_num << endl;//需要判定有多少配置需要写入
	for (size_t k = 0; k < config_num; k++)
	{	//循环输出用户选择数量的配置
		for (size_t i = 0; i < 3; i++)
		{
			for (size_t j = 0; j < 3; j++)
			{
				if ((j + 3 * i) == 8) ofile << setw(3) << setiosflags(ios::left);
				else
					ofile << setw(3) << setiosflags(ios::left) << puzzlestr[j + 3 * i];
			}
			cout << "row =" << row;

			ofile << endl;
		}
	}
	ofile.close();
}*/
