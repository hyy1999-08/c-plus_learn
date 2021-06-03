#pragma once
#include <string>
#include<set>
#include<iostream>
#include<map>
using namespace std;
//using std::string;
class my_user
{
public:
	enum ulevel {Beginner,Intermediate,Advanced,Guru};
	my_user(int guess_range, string uname = "guest",ulevel rank=Beginner, int guess_num=0,int guess_right=0,int login_num=0,int login_record=0) :_guess_range(guess_range),_rank(rank), _user_name(uname),_guess_num(guess_num),_guess_right(guess_right),_login_num(login_num),_login_rec(login_record) { get_key(); }
	bool operator==(my_user &u2)const {
		return this->_login_key== u2._login_key;
	}
	bool operator!=(my_user& u2)const {
		return !(this->_user_name == u2._user_name);
	}

	string get_level() const;//��enum����int��ʽ���ݻ�ԭ�ɶ�Ӧstring����
	string get_name() const { return _user_name; }
	int get_login_num() const { return _login_num; }
	int get_gn() const { return _guess_num?_guess_num:0; }
	int get_right() const { return _guess_right ? _guess_right : 0; }
	double get_rp() const { return _guess_rp?_guess_rp:0.0; }
	int get_gr() const { return _guess_range?_guess_range:0; }

	//д������
	void reset_level(const string&);
	void reset_level(ulevel newlevel) { _rank = newlevel; }
	void set_gr1(int nval) { _rand_generate = nval; }
	void set_ur(int nval) { _user_answer = nval; }
	//ֻ�Ľ��ܱ��������в���
	void add_login_r() { _login_rec++; }
	void add_login_n() { _login_num++; }
	void add_guess_num() { _guess_num++; }
	void add_guess_right() { _guess_right++; }

	void reset_levelmap(const string& level);
	void get_key();
	bool check();
	void guess_progress(bool &guess_c);
	void calculate_rp();
private:
	static map<string, ulevel> my_levelmap;
	static int _id_number;//���ɵ�ȫ�ֱ�ʶ
	int _login_key;//����ֵ
	int _guess_range;//guess��Χ
	int _login_rec;//��¼��¼���ݶ�Ϊint��
	string _user_name;//��¼����
	int _login_num;//��¼����
	int _guess_num;//�µĴ���
	int _guess_right;//�¶Դ���
	ulevel _rank;//�ȼ���0��1��2��3��Ӧ�������м����߼���ר�ң�
	double _guess_rp;//�¶԰ٷֱ�
	int _user_answer;//�û���
	int _rand_generate;//�����Լ����ɵģ���������չ



};

