#include<iostream>
#include"my_user.h"
#include<cstdlib>
#include<time.h>

using namespace std;

//������ר�����������û����룬�Լ�����
istream& operator>>(istream& is, my_user& m_user) {
	//����Ƿ��غ�
	if (m_user.check()) {
		srand((int)time(NULL));
		int find_n1;//������չΪtriple X
		find_n1 = rand() % (m_user.get_gr());//����һ�������
		m_user.set_gr1(find_n1);//�����û���µ���
		return is;
	}
	else {
		cout << "There are some mistakes occurs when you want to login!";
		return is;
	}
	
}
//�����ר�����������ʾ
ostream& operator<<(ostream& os, my_user& m_user) {
	bool guess_want=true;
	double g_n;//int��1/3���˹�ȥ��Ϊ0
	while(guess_want){
		cout << "We have generated your number! Please guess :" << endl;
		cin >> g_n;
		cin.clear();
		m_user.add_login_r();
		m_user.add_login_n();
		m_user.set_ur(g_n);//����
		m_user.guess_progress(guess_want);

	
	}

	m_user.calculate_rp();
	os << "You have guess " << m_user.get_gn() << "time(s) totally." << endl;
	os << "Your right percent is " << m_user.get_rp() << endl;
	//�����ʽΪname , rank ,��¼����, �µĴ���
	os << "Your total information is:" << "\n";
	os << "name";
	for (int i = 0; i < m_user.get_name().size(); i++) { os << " "; }
	os << "rank";
	for (int i = 0; i < m_user.get_level().size(); i++) { os << " "; }
	os << "login_num"<< " ";
	os << "guess_num"<< " ";
	os << "guess_right" << " ";
	os << "guess_right_percent" << " " << endl;

	//�û�������
	os << m_user.get_name() << " "
		<< m_user.get_level() << " ";
	for (int i = 0; i < m_user.get_level().size(); i++) { os << " "; }
	os << m_user.get_login_num();
	for (int i = 0; i < m_user.get_level().size(); i++) { os << " "; }
	os << m_user.get_gn();
	for (int i = 0; i < m_user.get_level().size(); i++) { os << " "; }
	os << m_user.get_right();
	for (int i = 0; i < m_user.get_level().size(); i++) { os << " "; }
	os << m_user.get_rp()
		<< endl;
	return os;
}

int main() {

	//int id = 0;
	//char buffer[16];
	//_itoa_s(id++, buffer, 10);
	//cout << id << endl;
	//cout << buffer<< endl;


	my_user my_f1(10, "ҫ��");
	my_user my_f2(10, "����");
	cin >>my_f1;
	if (my_f1.check()) {
		cout << my_f1;
	}

	return 0;

}
