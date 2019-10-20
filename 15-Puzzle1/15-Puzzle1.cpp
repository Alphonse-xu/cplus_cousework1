// ConsoleApplication12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;
#define Tnodenum 8
#define sidenum 13
#define zero 100
#define Lheadnum 7

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

//定义循环链表
struct Lnode {
	int Lint;
	struct Lint *next;
};
int *Lhead_pointer[Lheadnum];//定义保存循环链表头指针的数组

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


int main()
{
	int puzzlestr[8] = { 1,2,3,4,5,6,7,zero };
	Tnode** treelocation = &root;
	CreateTree(treelocation, puzzlestr);
	cout << root << endl;


	/*for (size_t i = 0; i < Tnodenum-1; i++)
	{
		int a;
		cout << "enter your puzzle NO"<<i<<"number"<<endl;
		cin >> a;
		T->puzzleint[i] = a;
	}


	CreateTree(T);
	*/

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
