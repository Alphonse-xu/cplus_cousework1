#include <iostream>
#include <algorithm>
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
		//int maxNo = -1;
		for (size_t i = 0; i < puzzlestr.size(); i++)
		{
			int a;
			do {
				cout << "enter your puzzle NO." << i + 1 << " number from 1 to 20" << endl;
				cin >> a;
			} while ((a <= 0) || (a > 20));
			puzzlestr[i] = a;
			//maxNo = max(maxNo, v[i]);
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
//用户选择数字随机生成配置
void puzzle::userchoose(int num) {
	string a;
	ppuzzlestr.resize(num);
	vector<int> temp;//生成20序列
		for (int i = 0; i < 20; ++i)
		{
			temp.push_back(i + 1);
		}
		for (size_t i = 0; i < num; i++)
		{
			random_shuffle(temp.begin(), temp.end());//打乱向量元素，选择需要数量的序列
			for (int j = 0; j < puzzlenum; j++)
			{

				cout << temp[j] << " ";
				ppuzzlestr[i].push_back(temp[j]);
			}
			cout << endl;
		}
}
//创建输出文件
void puzzle::creatfile() {
	int par = ios::out;
	//if (cond) 
	//par = ios::out | std::ios_base::app;覆盖文件写入或接着文件写入
	ofstream ofile("15puzzle.txt", par);
	if (!ofile) {
		cout << "error opening destination file." << endl;
		return;
	}
	ofile << "1" << endl;
	//写入用户输入的一个配置
		for (size_t i = 0; i < sqrt(puzzlenum+1); i++)
		{
			for (size_t j = 0; j < sqrt(puzzlenum + 1); j++)
			{
				if ((j + 3 * i) == puzzlenum) break;
				else
				ofile << setw(3) << setiosflags(ios::left) << puzzlestr[j + 3 * i];
			}
			ofile << endl;
		}
	ofile.close();
}
//
void puzzle::creatfile(int num) {
	int par = ios::out;
	//if (cond) 
	//par = ios::out | std::ios_base::app;
	ofstream ofile("15puzzle.txt", par);
	if (!ofile) {
		cout << "error opening destination file." << endl;
		return;
	}
	//if (!cond)选写 需要读文件判定里面有没有写入过
	ofile << num << endl;//配置数量
	for (size_t k = 0; k < num; k++)
	{	//循环输出用户选择数量的配置
		for (size_t i = 0; i < sqrt(puzzlenum + 1); i++)
		{
			for (size_t j = 0; j < sqrt(puzzlenum + 1); j++)
			{
				if ((j + 3 * i) == puzzlenum) break;
				else
					ofile << setw(3) << setiosflags(ios::left) << ppuzzlestr[k][j + 3 * i];
			}
			ofile << endl;
		}
	}
	ofile.close();
}