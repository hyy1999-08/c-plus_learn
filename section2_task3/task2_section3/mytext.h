#include<iostream>
#include<vector>
#include<string>
using namespace std;


int pent(int x);
inline bool check_size(int size);//调整为inline 函数
void display_elem(const vector<int>* myseq, int pos,int& elem);
const vector<int>*add(int size);
void check_c(bool& x);
template <typename elemtype> void display(const vector<elemtype>* myseq, string t);

