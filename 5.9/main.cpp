#include"Fibonacci.h"
#include"num_sequence.h"
#include<iostream>
#include <type_traits>
#include<typeinfo>
using namespace std;

int main() {

	Fibonacci fib;
	num_sequence *we = &fib;

	//typeid(*we) == typeid(Fibonacci);
	if (1) {
		//we->print();
		//Fibonacci *pf = static_cast<Fibonacci*>(we);
		we->print();//基类指针指向派生类对象但仍无法调用派生类函数

	}
	return 0;
}