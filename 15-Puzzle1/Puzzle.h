#ifndef PUZZLE_H
#define PUZZLE_H	


#include "father.h"
#include <algorithm>
#include <vector>
using namespace std;

constexpr int zero = 100;

class puzzle:public father{
public:
	puzzle() = default;
	void userenter();
	template<typename T> void userchoose(T& num){
		//用户选择数字随机生成配置
		string a;
		ppuzzlestr.resize(num);
		vector<int> temp;//生成20序列
		for (int i = 0; i < 20; ++i)
		{
			temp.push_back(i + 1);
		}
		for (int i = 0; i < num; i++)
		{
			random_shuffle(temp.begin(), temp.end());//打乱向量元素，选择需要数量的序列
			for (int j = 0; j < puzzlenum - 1; j++)
			{
				cout << temp[j] << " ";
				ppuzzlestr[i].push_back(temp[j]);
			}
			cout << endl;
		}
	}
	void creatfile();
	void creatfile(int num);
private:
	vector<int> puzzlestr{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,zero };
	vector<vector<int>> ppuzzlestr;

};
#endif PUZZLE_H