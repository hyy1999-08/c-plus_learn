#include<iostream>
#include<vector>
#include<string>
#include "mytext.h"
using namespace std;


int main() {


	//vector两个初始化,用表或者一个个赋值
	int a = 10;
	int b = 20;
	float c = 60.0;
	float d = 60.3;
	const string e = "element";
	const string f = "ecosystem";
	const int my_as = 4;
	const int my_is = 7;
	const int my_fs = 5;
	int my_int[my_is] = { 1,3,5,9,10,12,20 };
	vector<int> my_in(my_int, my_int + my_is);
	//int*p1[n]为指针数组，存放的是指针，int(*p1)[n]指针指向一个数组
	string myarray[my_as] = { "we","are","the","champion" };//string数组
	vector<string> my_ar(myarray, myarray + my_as);

	float my_float[my_fs] = { 12.3,1.7,18.9,20.0,9.5 };
	vector<float> my_fl(my_float, my_float + my_fs);

	cout << "the max of the two int is" << max1(a, b) << endl;
	cout << "the max of the two float is" << max1(c, d) << endl;
	cout << "the max of the two string is" << max1(e, f) << endl;
	cout << "the max of the int vector is" << max(my_in) << endl;
	cout << "the max of the float vector is" << max(my_fl) << endl;
	cout << "the max of the string vector is" << max(my_ar) << endl;
	cout << "the max of the int tuple is" << max(my_int, my_is) << endl;
	cout << "the max of the float tuple is" << max(my_float, my_fs) << endl;
	cout << "the max of the string tuple is" << max(myarray, my_as) << endl;

	return 0;
}
template <typename elemtype> 
elemtype max1(elemtype t1, elemtype t2) {
	return t1 > t2 ? t1 : t2;
}

template<typename vtype>
vtype max(vector<vtype> myseq) {
	vtype max_amount = myseq[0];
	for (int i = 1; i < myseq.size(); i++) {
		if (max_amount < myseq[i]) {
			max_amount = myseq[i];
		}
	}
	return max_amount;

}



template<typename atype>atype max(atype myseq[], const int size) {
	atype max_amount = myseq[0];
	for (int i = 1; i < size; i++) {
		if (max_amount < myseq[i]) {
			max_amount = myseq[i];
		}
	}
	return max_amount;


}


