#include<iostream>
#include<iterator>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int main() {


	/*
	//if you want to use file 

	ifstream in_file("inputfile.txt");
	ofstream out_file("outputfile.txt");
	if (!in_file || !out_file) {
		cout << "Sorry,can't create a file or output file.";
		return -1;
	}
	istream_iterator<string> is(in_file);
	istream_iterator<string> eof;
	vector<string> tx;
	copy(is, eof, back_inserter(tx) );
	ostream_iterator<string> os(out_file, " ");
	copy(tx.begin(), tx.end(), os);

	*/

	//use cin/cout 
	istream_iterator<string> is(cin);
	istream_iterator<string> eof;
	vector<string> text;
	//该输入方式为一直调用，直到你ctrl+z退出输入为止
	copy(is, eof, back_inserter(text));
	sort(text.begin(), text.end());
	ostream_iterator<string> os(cout, " ");
	copy(text.begin(), text.end(), os);

	
	return 0;
}