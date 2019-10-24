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

	thread t1([this]() 
	{
		this->printcon();
	});
	thread t2([this]() 
	{
		this->creatfile();
	});

	t1.join(); // This waits for the function to compelete
	t2.join();
}

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
//打印到屏幕上（可以写一个重载）
void solution::printcon() {
	cout << config_num<<endl;
	for (size_t k = 0; k < config_num; k++)
	{	//循环输出用户选择数量的配置
		for (size_t i = 0; i < sqrt(puzzlenum + 1); i++)
		{
			for (size_t j = 0; j < sqrt(puzzlenum + 1); j++)
			{
				if ((j + 3 * i) == puzzlenum) break;
				else
					cout << setw(3) << setiosflags(ios::left) << spuzzle[k][j + 3 * i];
			}
			cout << endl;
		}
		//多线程输出

		cout << "row = " << row<<endl;
		cout << "column = " << row<<endl;
		cout << "reverse row = " << row<<endl;
		cout << "reserve column = " << row<<endl;
		cout << endl;
	}
}

void solution::creatfile() {
	int par = ios::out;
	//if (cond) 
	//par = ios::out | std::ios_base::app;
	ofstream ofile("solution.txt", par);
	if (!ofile) {
		cout << "error opening destination file." << endl;
		return;
	}
	//if (!cond)选写 需要读文件判定里面有没有写入过
	ofile << config_num << endl;//配置数量
	for (size_t k = 0; k < config_num; k++)
	{	//循环输出用户选择数量的配置
		for (size_t i = 0; i < sqrt(puzzlenum + 1); i++)
		{
			for (size_t j = 0; j < sqrt(puzzlenum + 1); j++)
			{
				if ((j + 3 * i) == puzzlenum) break;
				else
					ofile << setw(3) << setiosflags(ios::left) << spuzzle[k][j + 3 * i];
			}
			ofile << endl;
		}
		ofile << "row = " << row << endl;
		ofile << "column = " << row << endl;
		ofile << "reverse row = " << row << endl;
		ofile << "reserve column = " << row << endl;
		ofile << endl;
	}
	ofile.close();
}
