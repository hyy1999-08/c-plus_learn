#include<fstream>
#include<iterator>
#include<map>
#include<iostream>
#include<string>
#include<set>
using namespace std;
int main() {
	void display_all(map<string, int>&my_m);
	void display1(map<string, int> &my_m);
	ifstream inputfile("inputfile.txt");

	if (!inputfile) {
		cout << "There are some mistakes during inputing a file.";
		return -1;
	}
	map<string, int> my_map;

	const int size = 6;
	string get;
	string exclusion[size] = { "a","an","or","the","and","but" };
	set<string> my_set(exclusion,exclusion+size);
	while (inputfile>>get) {
		if (my_set.count(get)) {
			continue;

		}
		my_map[get]++;
	}
	display1(my_map);
	display_all(my_map);
	return 0;
}


void display1(map<string,int> &my_m) {
	bool try1 = true;
	string find_w;
	string ans;
	map<string, int>::iterator it;
	while (try1) {
		cout << "Would you want to find a word?y/n"<<endl;
		cin >> ans;
		if (ans == "y" || ans == "Y") {
			cout << "Please input your word: "<<endl;
			cin >> find_w;
			if ((it=my_m.find(find_w) )!= my_m.end()) {
				//注意通过迭代器调用map，只需通过指针调用形式
				cout << "We find it!" << endl;
				cout << "The string " << find_w << " occurs " << it->second << " time(s)." << endl;
				try1 = false;
			}
			else {

				cout << "Sorry,we can't find this word,please check your word." << endl
					 << "Let's try again!";

			}


		}
		else {
			try1 == false;

		}
	}







}
void display_all(map<string, int>& my_m) {
	//注意不要刚开始进行赋值，因为此时里面并没有任何值，地址随机，指针会指向end，而不是开始
	map<string, int>::iterator iter = my_m.begin();
	cout << "The whole:" << endl;
	for (; iter != my_m.end(); iter++) {
		cout << iter->first << " ";
	}




}