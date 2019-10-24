#ifndef SOLUTION_H
#define SOLUTION_H	

#include <vector>
using namespace std;

#define sidenum 13
#define zero 100
#define Lheadnum 7
#define puzzlenum 8



class solution{
public:
	solution()=default;
	void readfile();
	void mapsequence();
	void printcon();
	void creatfile();
private:
	vector<vector<int>> spuzzle;
	size_t row;
	size_t column;
	size_t reverse_row;
	size_t reserve_column;
	int config_num = 0;
};

#endif SOLUTION_H
