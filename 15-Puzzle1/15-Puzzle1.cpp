// ConsoleApplication12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//#include <thread>

#include "Puzzle.h"
#include "solution.h"

using namespace std;
//
/*class puzzle {
	//friend
public:
	puzzle() = default;
	void userenter();
	void userchoose();
	void creatfile();
	void readfile();
private:
	vector<int> puzzlestr{ 1,2,3,4,5,6,7,8,zero };
	int config_num=0;
};*/

/*
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
*/

int main()
{
	int mod;
	bool flag=true;
	bool tryflag = false;
	bool doflag = true;
	unsigned int config_num;

	puzzle p15;
	solution s15;
	do {
		
		do {
			cout << "if you want to enter your puzzle.please press 1" << endl << "if you want to creat puzzle in rando way.please press 2 " << endl;
			cin >> mod;
			switch (mod) {
			case 1:
				p15.userenter();
				p15.creatfile();
				flag = false;
				break;
			case 2:
				cout << "how many configurations you want?" << endl;
				cin >> config_num;
				p15.userchoose(config_num);
				p15.creatfile(config_num);
				flag = false;
				break;
			default:
				cout << "please choose you what want again" << endl;
				flag = true;
			}
		}while (flag);
		
		
		try {
			s15.readfile();
		}
		catch (const char* msg) {
			cout << msg << endl;
		}
		s15.mapsequence();
		//再来一次
		
		do {
			cout << "do you want to try again?press 1 to continue. press 2 to exit." << endl;
			cin >> mod;
			switch (mod) {
			case 1:
				tryflag = false;
				doflag = true;
				break;
			case 2:
				doflag = false;
				tryflag = false;
				break;
			default:
				cout << "please choose you what want again" << endl;
				tryflag = true;
			}
		} while (tryflag);
		
	} while (doflag);
	return 0;
	//Tnode** treelocation = &root;
	//CreateTree(treelocation, puzzlestr);
	//cout << root << endl;

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
