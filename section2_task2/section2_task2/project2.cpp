#include "mytext.h"


int main() {


	//
	int size;
	bool ifc = true;
	while (ifc) {
		cout << "Please input your size:";
		cin >> size;
		if (!check_size(size)) {
			cout << "Your size has some mistakes,maybe it is too large or <0.";
			return 0;
		}
		vector<int> *my_seq = add(size);
		display(my_seq, "int");
		check_c(ifc);

	}
	return 0;
}


int pent(int x) {
	int result;//���ô�ֵ�Ȳ����¶��󴫲���
	result = x * (3 * x - 1) / 2;
	return result;
}
/*����ͨ��ֱ�Ӳ�������
void add(vector<int>& seq, int size) {
	for (int x = seq.size() + 1; x <= size; x++) {
		if (x < 0) {
			cout << "there is some mistake.";
		}
		int num = pent(x);
		seq.push_back(num);
	}

}
*/

//ͨ������ָ��static vector<int> my_seq;static �������Ǿ�̬�����ͷţ�const�Ǳ�֤����ı�ֵ
vector<int>* add(int size) {
	static vector<int> myseq;
	for (int ix = myseq.size() + 1; ix <= size; ix++) {
		myseq.push_back(pent(ix));
	}

	return &myseq;

}


bool check_size(int size) {
	if (size > 1024 || size <= 0) {
		return false;
	}

	return true;
}
void check_c(bool& x) {
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

void display(vector<elemtype> *myseq, string t) {
	for (int x = 0; x < myseq->size(); x++) {
		cout << (*myseq)[x] << " ";
	}
	cout << "\n";
	cout << "This is " << t << " array.";

}
