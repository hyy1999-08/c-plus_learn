#include "my_user.h"
int my_user::_id_number = 0;
//这里由于ulevel为枚举类型，并没有在这里有定义，所以得指定域符
map<string, my_user::ulevel> my_user::my_levelmap;




bool my_user::check() {
	return _login_key < _id_number;
	//这里就简单的判断下
}

void my_user::guess_progress(bool &guess_c)
{	
	if(this->_user_answer==this->_rand_generate){
		cout << "Your answer are right! ";
		this->add_guess_num();
		this->add_guess_right();
		guess_c = false;
	}else if (this->_user_answer > this->_rand_generate) {
		cout << "Your answer may be a little bit bigger. "<<"Try agiain!"<<endl;
		this->add_guess_num();
	}
	else {
		cout << "Your answer may be a little bit smaller! " << "Try agiain!" << endl;
		this->add_guess_num();

	}
}

void my_user::calculate_rp()
{
	//强制类型转换，以免出现小数被省略
	_guess_rp =double (_guess_right) /double( _guess_num);
}

string my_user::get_level() const
{
	static string level_table[] = { "Beginner","Intermediate","Advanced","Guru" };

	return level_table[_rank];
}

void my_user::reset_levelmap(const string& level)
{
	map<string, ulevel>::iterator it;
	_rank = (it = my_levelmap.find(level)) != my_levelmap.end() ? it->second : Beginner;
}

void my_user::get_key()
{//用固定变量
	_login_key = _id_number;
	_id_number++;

//用随机生成，但可能会重复
}
