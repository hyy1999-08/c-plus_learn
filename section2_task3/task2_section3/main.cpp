#include "mytext.h"


int main() {


	//
	int size;
	bool ifc = true;
	bool pos_get= true;
	string bool_get;
	int pos;
	int my_elem;
	while (ifc) {
		cout << "Please input your size:";
		cin >> size;
		if (!check_size(size)) {
			cout << "Your size has some mistakes,maybe it is too large or <0.";
			return 0;
		}
		const vector<int>* my_seq = add(size);
		display(my_seq, "int");


	
		while (pos_get) {
			cout << "Do you want to get a elem?Y/N";
			cin >> bool_get;
			if (bool_get == "Y" || bool_get == "y") {
				cout << "Please input your position:";
				cin >> pos;
				if (pos <= my_seq->size() && pos > 0) {
					display_elem(my_seq, pos, my_elem);
					pos_get = false;
				}
				else {

					cout << "Your position may be bigger than the max size or <0."<<endl;
					
				}

			}
			else if (bool_get != "N" || bool_get != "n") {
				cout << "Please input Y or N."<<endl;
				cout << "Let's restart.";

			}
		}
		pos_get = true;

		check_c(ifc);
	}
	return 0;
}


int pent(int x) {
	int result;//利用传值既不用怕对象传不了
	result = x * (3 * x - 1) / 2;
	return result;
}
/*这是通过直接操纵数组
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

//通过返回指针static vector<int> my_seq;static 的作用是静态不会释放，const是保证不会改变值
const vector<int>* add(int size) {
	static vector<int> myseq;
	for (int ix = myseq.size() + 1; ix <= size; ix++) {
		myseq.push_back(pent(ix));
	}

	return &myseq;

}
void display_elem(const vector<int>* myseq,int pos,int &elem) {
	elem = (*myseq)[pos - 1];
	cout << "this elem " << elem << " is in position " << pos<<endl;
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

void display(const vector<elemtype>* myseq, string t) {
	for (int x = 0; x < myseq->size(); x++) {
		cout << (*myseq)[x] << " ";
	}
	cout << "\n";
	cout << "This is " << t << " array.";

}
