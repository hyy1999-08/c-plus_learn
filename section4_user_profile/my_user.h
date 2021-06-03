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

	string get_level() const;//将enum类型int形式数据还原成对应string类型
	string get_name() const { return _user_name; }
	int get_login_num() const { return _login_num; }
	int get_gn() const { return _guess_num?_guess_num:0; }
	int get_right() const { return _guess_right ? _guess_right : 0; }
	double get_rp() const { return _guess_rp?_guess_rp:0.0; }
	int get_gr() const { return _guess_range?_guess_range:0; }

	//写入数据
	void reset_level(const string&);
	void reset_level(ulevel newlevel) { _rank = newlevel; }
	void set_gr1(int nval) { _rand_generate = nval; }
	void set_ur(int nval) { _user_answer = nval; }
	//只改接受变量看下行不行
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
	static int _id_number;//生成的全局标识
	int _login_key;//被赋值
	int _guess_range;//guess范围
	int _login_rec;//登录记录，暂定为int型
	string _user_name;//登录名字
	int _login_num;//登录次数
	int _guess_num;//猜的次数
	int _guess_right;//猜对次数
	ulevel _rank;//等级分0，1，2，3对应初级，中级，高级，专家；
	double _guess_rp;//猜对百分比
	int _user_answer;//用户答案
	int _rand_generate;//我们自己生成的，后续可拓展



};

