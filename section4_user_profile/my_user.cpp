#include "my_user.h"
int my_user::_id_number = 0;
//��������ulevelΪö�����ͣ���û���������ж��壬���Ե�ָ�����
map<string, my_user::ulevel> my_user::my_levelmap;




bool my_user::check() {
	return _login_key < _id_number;
	//����ͼ򵥵��ж���
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
	//ǿ������ת�����������С����ʡ��
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
{//�ù̶�����
	_login_key = _id_number;
	_id_number++;

//��������ɣ������ܻ��ظ�
}
