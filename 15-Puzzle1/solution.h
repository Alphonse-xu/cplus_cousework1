#ifndef SOLUTION_H
#define SOLUTION_H	

#include "father.h"
#include <vector>
using namespace std;


class solution:public father{
public:
	solution()=default;
	void readfile();
	void mapsequence();
	void printcon();
	void creatfile();
	void mapsequence_all();
private:
	vector<vector<int>> spuzzle;
	vector<unsigned long long> row;
	unsigned long long column;
	unsigned long long reverse_row;
	unsigned long long reserve_column;
	unsigned long long row2;
	unsigned long long row3;
	unsigned long long rev_row2;
	unsigned long long rev_row3;
	unsigned long long column2;
	unsigned long long column3;
	unsigned long long rev_column2;
	unsigned long long rev_column3;
	int config_num = 0;
};

#endif SOLUTION_H
