#pragma once
#include<string>
#include<functional>
using namespace std;
class less_than
{
public:
	//ע��operator����ø�������
	bool operator()(const string& s1, const string& s2) {
		return (s1.size() < s2.size());



	}
};

