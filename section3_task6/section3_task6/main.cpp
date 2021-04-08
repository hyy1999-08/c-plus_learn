#include"Result.h"

int main() {
	map<string, vector<string>> my_map;
	//map<string, string[]> my_map;
	void display(map<string, vector<string> >&my_map,ostream & os=cout);
	const int size1 = 8;
	const int size2 = 5;
	const string my_string1 = "1429";
	const string my_string2 = "309";
	void input_m( vector<string>&my_vector,const string &my_string, map<string, vector<string>> &my_mapi);
	string my_arr1[] = { "»ÆÒ«ìÇ","ÕÅÎÄ½¡","ÀîÆæ·å","¹ËÆéÑÒ","Ìï±ó»Ô","Íõ´º»Ô","Ô¬»ª¾ı","ÍõÒİÛÂ" };
	string my_arr2[] = { "³ÂÊ÷Ìî","³Â¾ÙË¸","·¢¸ç","»ÆÒ«ìÇ","Ğ¡ÖÇ"};

	vector<string> my_vector1(my_arr1, my_arr1 + size1);
	vector<string> my_vector2(my_arr2, my_arr2 + size2);
	input_m(my_vector1, my_string1,my_map);
	input_m(my_vector2, my_string2, my_map);
	display(my_map);
	return 0;
}


void input_m(vector<string>& my_vector,const string &my_string, map<string, vector<string>> &my_mapi) {
	my_mapi[my_string] = my_vector;
}

void display(map<string, vector<string> >& my_map, ostream& os) {
	Result find_fn(map<string, vector<string>> &m_m);
	bool try_m = true;
	string get;
	string ans;
	while (try_m)
	{
		map<string, vector<string>>::iterator iter;
		iter = my_map.begin();
		vector<string> m_f;
		Result display_r = find_fn(my_map);
		if (display_r.R_iterm != my_map.end()) {
			cout << "We find him/she!";
			os << "He/she is in " << display_r.my_family << endl;
			os << "The " << display_r.my_family << " family has following members:" << endl;
			for (int ix = 0; ix < display_r.R_vec.size(); ix++) {
				os << display_r.R_vec[ix] << " ";
			}
		}
		os << endl;
		cin.ignore();
		cout << "Do you want to find another one?y/n:"<< endl;

		cin >> ans;
		if (ans == "y" || ans == "Y") {
				try_m = true;
			}
		else {
				try_m = false;
			}
	

	}

}



Result find_fn(map<string, vector<string>> &m_m) {
	char get_fn;
	bool get_a= false;
	vector<string> r_n ;
	vector<string>::iterator r_np;
	Result net;
	cout << "Please input the first name of which man you want to find:"<<endl;
	cin >> get_fn;
	map<string, vector<string>>::iterator iter = m_m.begin();
	for (; iter != m_m.end();iter++) {
		r_n = iter->second;
		r_np = r_n.begin();
		for (; r_np != r_n.end();r_np++) {
			if ( (*r_np).at(0)== get_fn) {
				net.my_family = iter->first;
				net.R_vec = r_n;
				net.R_iterm = m_m.begin();
				get_a = true;
				break;
			}
		}
		if (!get_a) {
			net.R_iterm = m_m.end();
		}

	}
	return net;
}









