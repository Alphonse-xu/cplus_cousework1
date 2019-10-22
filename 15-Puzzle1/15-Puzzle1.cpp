// ConsoleApplication12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;
#define Tnodenum 8
#define sidenum 13
#define zero 100
#define Lheadnum 7
#define puzzlenum 8
//定义树节点
struct Tnode {
	int puzzleint[8];
	struct Tnode *N1;
	struct Tnode *N2;
	struct Tnode *N3;
	struct Tnode *N4;
	struct Tnode *N5;
	struct Tnode *N6;
	struct Tnode *N7;

};
struct Tnode* root = nullptr;



int f1[8], f2[8], f3[8], f4[8], f5[8];
//移动函数1 2*2移动
void turnswap(const int *a) {
	for (int i = 0; i < Tnodenum - 1; i++)
	{
		f1[i] = a[i];
	}
	swap(f1[5], f1[8]);
	swap(f1[4], f1[5]);
	swap(f1[7], f1[4]);
	swap(f1[8], f1[7]);
}

//定义搜索重复
bool comparetree(Tnode *tree, int *PINT) {
	if (tree)
	{
		if (PINT == tree->puzzleint) {
			return true;

		}
		else
		{
			comparetree(tree->N1, PINT);
			//comparetree(tree->N2, PINT);
			//comparetree(tree->N3, PINT);
			//comparetree(tree->N4, PINT);
			//comparetree(tree->N5, PINT);

		}
		return false;
	}
	return false;
}
//创建树
void CreateTree(Tnode** T, int *PINT) {
	if (!T)
	{
		*T = new Tnode();
		for (int i = 0; i < Tnodenum - 1; i++)
		{
			(*T)->puzzleint[i] = PINT[i];
		}
	}
	bool key;//判断是否重复
	//int puzzlestr[8] = { 1,2,3,4,5,6,7,zero };
	key = comparetree(root, PINT);
	if (key)  T = nullptr;
	else
	{

		for (int i = 0; i < Tnodenum - 1; i++)
		{
			(*T)->puzzleint[i] = PINT[i];
		}

		turnswap(PINT);
		CreateTree(&(*T)->N1, f1);
	
	}

}
//用户输入配置
void userenter(vector<int> &v) {
	bool temp=true;
	do
	{
		//int maxNo = -1;
		for (size_t i = 0; i < v.size(); i++)
		{
			int a;
			do {
				cout << "enter your puzzle NO." << i+1 << " number from 1 to 20" << endl;
				cin >> a;
			} while ((a <= 0) || (a > 20));
			v[i] = a;
			//maxNo = max(maxNo, v[i]);
		}
		//判断用户输入是否重复
		vector<int> count(21, 0);
		for (int i = 0; i < v.size(); i++) 
		{
			if (count[v[i]] == 1) {
				temp = false;
				break;
			}
			count[v[i]]++;
		}
		if (!temp) 
			cout << "there is a repeated number, please continue" << endl;
	} while (!temp);
}
//用户选择数字随机生成配置
void userchoose(vector<int> &v) {
	string a;
	unsigned int b;
	cout << "do you want to choose a 15puzzle? Y or N" << endl;
	cin >> a;
	if (a == "Y")
	{
		cout << "how many configurations you want?" << endl;
		cin >> b;
		vector<int> temp;
		for (int i = 0; i < 20; ++i)
		{
			temp.push_back(i + 1);
		}
		for (size_t i = 0; i < b; i++)
		{
			random_shuffle(temp.begin(), temp.end());
			for (int i = 0; i < puzzlenum; i++)
			{
				cout << temp[i] << " ";
				v[i] = temp[i];
			}
			cout << endl;
		}
	}
}
//创建输出文件
void creatfile(vector<int> &v) {
	int par = ios::out;
	//if (cond) 
		//par = par | std::ios_base::app;
	ofstream ofile("15puzzle.txt", par);
	if (!ofile) {
		cout << "error opening destination file." << endl;
		return;
	}
	//if (!cond)//选写 需要读文件判定里面有没有写入过
		ofile << "1" << endl;//需要判定有多少配置需要写入(从USERCHOOSE函数传入)
		/*for (size_t i = 0; i < length; i++)
		{
		缺一个循环输出用户选择数量的配置
		}*/
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			if ((j + 3 * i) == 8) ofile << setw(3) << setiosflags(ios::left);
			else
			ofile << setw(3) << setiosflags(ios::left) << v[j+3*i];
		}
		ofile << endl;
	}
	ofile.close();
}
//读文件（读写可以合并）
void readfile(vector<int> &v) {
	int total;//读文件第一行判断有几个配置
	ifstream ifile("15puzzle.txt", ios::in);
	if (!ifile) {
		cout << "error opening destination file." << endl;
		return;
	}
	int a;
	ifile >> total;
	cout << total<<endl;
	int x = 0;
	while (true) 
	{
		ifile >> v[x];
		x++;
		if (ifile.eof() != 0) break;
	}
	ifile.close();
	for (int i = 0; i < puzzlenum; i++)
	{
		cout << v[i] << " ";
	}
}
int main()
{
	vector<int> puzzlestr{ 1,2,3,4,5,6,7,8,zero };
	//userenter(puzzlestr);
	userchoose(puzzlestr);
	creatfile(puzzlestr);
	readfile(puzzlestr);
	//Tnode** treelocation = &root;
	//CreateTree(treelocation, puzzlestr);
	//cout << root << endl;
	return 0;


}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
