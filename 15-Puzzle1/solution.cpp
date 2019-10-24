#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <thread>

#include "Puzzle.h"
#include "solution.h"


using namespace std;

void solution::mapsequence() {
	for (int k = 0; k < config_num; k++)
	{
		unsigned long long temp = 1;
		row.resize(config_num);
		int continue_num = 0;
		vector<vector<unsigned long long>> fakepuzzle(config_num);
		for (int i = 0; i < config_num; i++)
		{
			for (int j = 0; j < puzzlenum - 1; j++)
			{
				fakepuzzle[i].push_back(spuzzle[i][j]);
			}
		}

		sort(&fakepuzzle[k][0], &fakepuzzle[k][14]);
		//判断有几个连续组
		for (int i = 0; i < puzzlenum-sidenum; i++) {
			if ((spuzzle[k][i] + 3) == spuzzle[k][i+3]) {
				continue_num++;
			}
		}
		//公式(n2-1-n)!*n连续数*((n-1)/2 + n2-1-(n-1))!*(n-1)连续数/2
		for (int i = 1; i <= puzzlenum - sidenum-1; i++) {
			temp = temp * i;
		}
		row[k] = temp  * continue_num * 3 / 2;

		continue_num = 0;
		temp = 1;
		for (int i = 0; i < puzzlenum - sidenum + 1; i++) {
			if ((spuzzle[k][i] + 2) == spuzzle[k][i + 2]) {
				continue_num++;
			}
		}
		for (int i = 1; i <= puzzlenum - sidenum; i++) {
			temp = temp * i;
		}
		row[k] = row[k] + (temp  * continue_num / 2);
	}

	mapsequence_all();
	//多线程
	thread t1([this]()
	{
		this->printcon();
	});
	thread t2([this]()
	{
		this->creatfile();
	});

	t1.join();
	t2.join();
}

//23排序计数
void solution::mapsequence_all() {
	for (int k = 0; k < config_num; k++) 
	{
		int total = sidenum * sidenum - 1;
		//
		for (int i = 0; i < (total - 1); i++)
		{
			if ((sidenum - i % sidenum) >= 2)
			{
				if ((spuzzle[k][i] + 1) == spuzzle[k][i + 1])
					row2++;
				if ((spuzzle[k][i] - 1) == spuzzle[k][i + 1])
					rev_row2++;
			}
		}
		//
		for (int i = 0; i < (total - 2); i++)
		{
			if ((sidenum - i % sidenum) >= 3)
			{
				if ((spuzzle[k][i] + 1) == spuzzle[k][i + 1] && (spuzzle[k][i + 1] + 1) == (spuzzle[k][i + 2]))
					row3++;
				if ((spuzzle[k][i] - 1) == spuzzle[k][i + 1] && (spuzzle[k][i + 1] - 1) == (spuzzle[k][i + 2]))
					rev_row3++;
			}
		}
		//
		for (int i = 0; i < (total - sidenum); i++)
		{
			if ((spuzzle[k][i] + 1) == spuzzle[k][i + sidenum])
				column2++;
			if ((spuzzle[k][i] - 1) == spuzzle[k][i + sidenum])
				rev_column2++;
		}
		//
		for (int i = 0; i < (total - 2 * sidenum); i++)
		{
			if ((spuzzle[k][i] + 1) == spuzzle[k][i + sidenum] && (spuzzle[k][i + sidenum] + 1) == spuzzle[k][i + 2 * sidenum])
				column3++;
			if ((spuzzle[k][i] - 1) == spuzzle[k][i + sidenum] && (spuzzle[k][i + sidenum] - 1) == spuzzle[k][i + 2 * sidenum])
				rev_column3++;
		}
	}
}

//读文件
void solution::readfile() {
	ifstream ifile("15puzzle.txt", ios::in);
	if (!ifile) {
		throw "error opening destination file.";
		return;
	}
	ifile >> config_num;//读第一行判断有几个配置
	cout << "total configuration number is " << config_num << endl;
	//读入配置
	int y = 0;
	for (int i = 0; i < config_num; i++)
	{
		spuzzle.resize(config_num);
		for (int j = 0; j < puzzlenum-1; j++)
		{
			ifile >> y;
			spuzzle[i].push_back(y); 
			if (ifile.eof() != 0) break;
		}
		if (ifile.eof() != 0) break;
	}
	ifile.close();
	for (int i = 0; i < config_num; i++)
	{
		for (int j = 0; j < puzzlenum-1; j++)
		{
			cout << spuzzle[i][j] << " ";
		} 
		cout << endl;
	}
}

//打印到屏幕上
void solution::printcon() {
	cout << config_num<<endl;
	for (int k = 0; k < config_num; k++)
	{	//循环输出用户选择数量的配置
		for (int i = 0; i < sidenum; i++)
		{
			for (int j = 0; j < sidenum; j++)
			{
				if ((j + sidenum * i) == puzzlenum-1) break;
				else
					cout << setw(3) << setiosflags(ios::left) << spuzzle[k][j + sidenum * i];
			}
			cout << endl;
		}
		cout << "total for row & column, including reverse, in this configuration" << endl;
		cout << "2 =" << row2 + column2 + rev_row2 + rev_column2 << endl;
		cout <<"3 ="<<row3+column3+rev_row3+rev_column3<<endl;
		cout << "row = " << row[k]<<endl;
		cout << "column = " << row[k]<<endl;
		cout << "reverse row = " << row[k]<<endl;
		cout << "reserve column = " << row[k]<<endl;
		cout << endl;
	}
}

//创建文件
void solution::creatfile() {
	string filename;
	auto id = filename.find("*");
	if (id == string::npos) cout << "safe filename" << endl;
	else
		cout << "unsafe filename" << endl;
	ofstream ofile("solution.txt", ios::out);
	if (!ofile) {
		cout << "error opening destination file." << endl;
		return;
	}
	//if (!cond)选写 需要读文件判定里面有没有写入过
	ofile << config_num << endl;//配置数量
	for (int k = 0; k < config_num; k++)
	{	//循环输出用户选择数量的配置
		for (int i = 0; i < sidenum; i++)
		{
			for (int j = 0; j < sidenum; j++)
			{
				if ((j + sidenum * i) == puzzlenum-1) break;
				else
					ofile << setw(3) << setiosflags(ios::left) << spuzzle[k][j + sidenum * i];
			}
			ofile << endl;
		}
		ofile << "total for row & column, including reverse, in this configuration" << endl;
		ofile << "2 =" << row2 + column2 + rev_row2 + rev_column2 << endl;;
		ofile << "3 =" << row3 + column3 + rev_row3 + rev_column3<<endl;
		ofile << "row = " << row[k] << endl;
		ofile << "column = " << row[k] << endl;
		ofile << "reverse row = " << row[k] << endl;
		ofile << "reserve column = " << row[k] << endl;
		ofile << endl;
	}
	ofile.close();
}
