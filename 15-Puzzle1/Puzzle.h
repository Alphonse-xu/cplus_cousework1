#ifndef PUZZLE_H
#define PUZZLE_H	

#include <vector>
using namespace std;
#define sidenum 13
#define zero 100
#define Lheadnum 7
#define puzzlenum 8

class puzzle {
	//friend
public:
	puzzle() = default;
	void userenter();
	void userchoose(int num);
	void creatfile();
	void creatfile(int num);
private:
	vector<int> puzzlestr{ 1,2,3,4,5,6,7,8,zero };
	vector<vector<int>> ppuzzlestr;
	int config_num=0;

};
#endif PUZZLE_H