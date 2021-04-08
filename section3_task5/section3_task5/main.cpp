#include<map>
#include<fstream>
#include<iostream>
#include<functional>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<iterator>
#include"less_than.h"
using namespace std;
int main() {
	ifstream inf("inputfile.txt");
	ofstream ouf("outputfile.txt");
	void display(vector<string> & my_vector, ofstream & os);
	if (!inf||!ouf) {
		cout << "There are some mistakes when inputing a file.";
		return -1;


	}
	const int size = 6;
	string get1;
	string exclusion[size] = { "a","an","or","the","and","but" };
	set<string> my_s(exclusion, exclusion + size);
	map<string, int> my_map;
	vector<string> my_vector;

	while (inf >> get1) {
		if (my_s.count(get1)) {
			continue;
		}
		my_vector.push_back(get1);

	}
	sort(my_vector.begin(), my_vector.end(), less_than());
	display(my_vector, ouf);





	return 0;
}
void display(vector<string> &my_vector,ofstream &os) {
	vector<string>::iterator m_b = my_vector.begin();
	os<< "The whole values are:" << endl;
	for (; m_b != my_vector.end(); m_b++) {
		os << (*m_b) << " ";
	

	}


}
