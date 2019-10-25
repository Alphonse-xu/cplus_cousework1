#include <iostream>

#include <vector>
#include<string>
#include<fstream>
#include<iomanip>
#include<cmath>

#include "Puzzle.h"

using namespace std;


//用户输入配置
void puzzle::userenter() {
	bool temp = true;
	do
	{
		for (int i = 0; i < puzzlestr.size(); i++)
		{
			int a;
			do {
				cout << "enter your puzzle NO." << i + 1 << " number from 1 to 20" << endl;
				cin >> a;
			} while ((a <= 0) || (a > 20));
			puzzlestr[i] = a;
		}
		//判断用户输入是否重复
		vector<int> count(21, 0);
		for (int i = 0; i < puzzlestr.size(); i++)
		{
			if (count[puzzlestr[i]] == 1) {
				temp = false;
				break;
			}
			count[puzzlestr[i]]++;
		}
		if (!temp)
			cout << "there is a repeated number, please continue" << endl;
	} while (!temp);
	
}

//创建输出文件
void puzzle::creatfile() {
	string filename;
	auto id = filename.find("*");
	if (id == string::npos) cout << "safe filename" << endl;
	else
		cout << "unsafe filename" << endl;
	ofstream ofile("15puzzle.txt", ios::out);//ios::out | std::ios_base::app;覆盖文件写入或接着文件写入
	if (!ofile) {
		cout << "error opening destination file." << endl;
		return;
	}
	ofile << "1" << endl;
	//写入用户输入的一个配置
		for (int i = 0; i < sidenum; i++)
		{
			for (int j = 0; j < sidenum; j++)
			{
				if ((j + sidenum * i) == puzzlenum-1) break;
				else
				ofile << setw(3) << setiosflags(ios::left) << puzzlestr[j + sidenum * i];
			}
			ofile << endl;
		}
	ofile.close();
}

void puzzle::creatfile(int num) {
	int par = ios::out;
	ofstream ofile("15puzzle.txt", par);
	if (!ofile) {
		cout << "error opening destination file." << endl;
		return;
	}

	ofile << num << endl;//配置数量
	for (int k = 0; k < num; k++)
	{	//循环输出用户选择数量的配置
		for (int i = 0; i < sidenum; i++)
		{
			for (int j = 0; j < sidenum; j++)
			{
				if ((j + sidenum * i) == puzzlenum-1) break;
				else
					ofile << setw(3) << setiosflags(ios::left) << ppuzzlestr[k][j + sidenum * i];
			}
			ofile << endl;
		}
		ofile << endl;
	}
	ofile.close();
}