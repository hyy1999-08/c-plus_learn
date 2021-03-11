#include "mytext.h"


int main() {


	static vector<int> my_seq;//static 的作用是静态不会释放，const是保证不会改变值
	int size;
	bool ifc = true;
	while(ifc){
		cout << "Please input your size:";
		cin >> size;
		if (!check_size(size)) {
			cout << "Your size has some mistakes,maybe it is too large or <0.";
			return 0;
		}
		add(my_seq, size);
		display(my_seq,"int");
		check_c(ifc);

	}
	return 0;
}


int pent(int x) {
	int result;//利用传值既不用怕对象传不了
	result = x*(3*x - 1) / 2;
	return result;
}
void add(vector<int> &seq, int size) {
	for (int x = seq.size()+1; x <=size; x++) {
		if (x <0) {
			cout << "there is some mistake.";
		}
		int num = pent(x);
		seq.push_back(num);
	}

}
bool check_size(int size) {
	if (size > 1024 || size <= 0) {
		return false;
	}

	return true;
}
void check_c(bool &x) {
	string answer;
	cout << "if you want to continue?Y/N";
	cin >> answer;
	if (answer == "Y" || answer == "y") {
		x = true;
	}
	else {
		x = false;
	}

}
template <typename elemtype>
void display(vector<elemtype> &myseq,string t) {
	for (int x = 0; x < myseq.size(); x++) {
		cout << myseq[x] << " ";
	}
	cout << "\n";
	cout << "This is " <<t << " array.";

}
