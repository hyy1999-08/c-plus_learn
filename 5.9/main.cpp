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
		we->print();//����ָ��ָ��������������޷����������ຯ��

	}
	return 0;
}