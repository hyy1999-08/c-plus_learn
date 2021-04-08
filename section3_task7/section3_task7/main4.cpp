#include<iterator>
#include<fstream>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
class even_elem {
public:
	bool operator()(int elem) {
		return elem % 2 ? false: true;

	}
};


*/



int main() {
	//ifstream infile1("my_number.txt");
	void get_odd(vector<int> &my_num,vector<int> &my_odd);
	void get_even(vector<int>&my_num, vector<int>&my_even);
	ofstream out_file_odd("odd_number.txt");
	ofstream out_file_even("even_number.txt");
	if (!out_file_odd||!out_file_even) {
		cout << "There are some mistake to create a file!";
		return -1;
	}
	cout << "Please input your number:";
	cout << endl;
	istream_iterator<int> in(cin),eof;
	ostream_iterator<int> osf_odd(out_file_odd," ");
	//注意如何输出换行
	ostream_iterator<int> osf_even(out_file_even," \n");
	vector<int> my_num;
	vector<int> odd_num;
	vector<int> even_num;
	copy(in, eof, back_inserter(my_num));
	/*
	
	//可使用泛型算法partition,stable_partition可以保持相对顺序,并利用定义区分的偶数
	vector<int>::iterator division=partition(my_num.begin(),my_num.end(),even_elem() );//division指向分割位置
	copy(my_num.begin(),division,osf_even);
	copy(division,my_num.end(),osf_odd);

	
	*/
	get_odd(my_num, odd_num);
	get_even(my_num,even_num);
	copy(odd_num.begin(), odd_num.end(), osf_odd);
	copy(even_num.begin(), even_num.end(), osf_even);







	return 0;
}

void get_odd(vector<int> &my_num,vector<int> &my_odd) {

	for (int ix = 0; ix < my_num.size(); ix++) {
		if (my_num[ix] % 2 != 0) {
			my_odd.push_back(my_num[ix]);
		}


	}
		
}
void get_even(vector<int>& my_num, vector<int>& my_even) {
	for (int ix = 0; ix < my_num.size(); ix++) {
		if (my_num[ix] % 2 == 0) {
			my_even.push_back(my_num[ix]);
		}


	}

}