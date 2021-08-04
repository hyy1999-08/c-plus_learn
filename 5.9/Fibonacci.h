#pragma once
#include"num_sequence.h"
#include<iostream>
using namespace std;
class Fibonacci:public num_sequence
{
public:
	//Fibonacci* clone() { return new Fibonacci(*this); }
	void print(){ cout << "Fibonacci!" << endl; }
};

