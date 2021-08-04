#pragma once
#include<iostream>
using namespace std;
//解决几个问题1.返回指针类型
class num_sequence
{
public:
	//virtual num_sequence* clone();//定义了纯虚函数
	void print() { cout << "num_sequence!" << endl; }
};

