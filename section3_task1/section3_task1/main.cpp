#include<algorithm>
#include<iostream>
#include<vector>
#include<functional>
using namespace std;

template<typename input,typename comp, typename Elemtype,typename arrtype>
void sub_vec1(input p,vector<arrtype> &my_seq,  const Elemtype& val, comp pred) {
	vector <arrtype> local_vector(my_seq);
	sort(local_vector.begin(),local_vector.end());//从小到大排序
	p= find_if(local_vector.begin(), local_vector.end(), bind2nd(pred, val));
	local_vector.erase(p, local_vector.end());
	for (int ix = 0; ix < local_vector.size(); ix++) {
		cout << local_vector[ix] << " ";

	}
	
	cout << endl;

}
template<typename input, typename comp, typename Elemtype, typename arrtype>
void sub_vec2(input p, vector<arrtype>& my_seq, const Elemtype& val, comp pred) {
	vector <arrtype> local_vector(my_seq);
	sort(local_vector.begin(), local_vector.end());
	p = find_if(local_vector.begin(), local_vector.end(), bind2nd(pred, val));
	local_vector.erase(local_vector.begin(),p);
	for (int ix = 0; ix < local_vector.size(); ix++) {
		cout << local_vector[ix] << " ";

	}

	cout << endl;

}

int main() {
	const int size = 6;
	int arr[size] = { 2,23,5,9,1,10 };
	vector<int> my_a(arr, arr + size);
	vector<int>::iterator iter;
	cout << "array for values less than 6";
	cout << endl;
	sub_vec1(iter, my_a, size, greater<int>());
	cout << "array for values greater than 6";
	cout << endl;
	sub_vec2( iter,my_a, size, greater<int>());

	return 0;
}