#pragma once
#include<string>
#include<functional>
using namespace std;
class less_than
{
public:
	//注意operator后面得跟个（）
	bool operator()(const string& s1, const string& s2) {
		return (s1.size() < s2.size());



	}
};

