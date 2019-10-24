// ConsoleApplication12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//#include <thread>

#include "Puzzle.h"
#include "solution.h"

using namespace std;

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
		cout << "choose which function do you want" << endl<<"";

		do {
			cout << "if you want to enter your puzzle.please press 1" << endl << "if you want to creat puzzle in rando way.please press 2 " << endl;
			cin >> mod;
			switch (mod) {
			case 1:
				cout << "enter the size of puzzle you want" << endl;
				cin >> p15.sidenum;
				s15.sidenum = p15.sidenum;
				p15.puzzlenum = p15.sidenum * p15.sidenum;
				s15.puzzlenum = s15.sidenum * s15.sidenum;
				p15.userenter();
				p15.creatfile();
				flag = false;
				break;
			case 2:
				cout << "how many configurations you want?" << endl;
				cin >> config_num;
				cout << "enter the size of puzzle you want" << endl;
				cin >> p15.sidenum;
				s15.sidenum = p15.sidenum;
				p15.puzzlenum = p15.sidenum * p15.sidenum;
				s15.puzzlenum = s15.sidenum * s15.sidenum;
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
