#ifndef USER_INFO
#define USER_INFO

class User_Information { // ������� ������ ����ϴ� Ŭ����

public:

	//�ڡڡڡڡڡڡڡڡڡڡڡڡ� �̼� 4 : ������ �ڡڡڡڡڡڡڡڡڡڡڡڡ�
	User_Information();
	//�ڡڡڡڡڡڡڡڡڡڡڡڡ� �̼� 6 : friend �Լ� �ڡڡڡڡڡڡڡڡڡڡڡڡ�
	friend void AccountBook_Start::setID(); // ID�� �����ϴ� �Լ�
	//�ڡڡڡڡڡڡڡڡڡڡڡڡ� �̼� 6 : friend �Լ� �ڡڡڡڡڡڡڡڡڡڡڡڡ�
	friend void AccountBook_Start::setPasswd(); // ��й�ȣ�� �����ϴ� �Լ�
	//�ڡڡڡڡڡڡڡڡڡڡڡڡ� �̼� 4 : �Ҹ��� �ڡڡڡڡڡڡڡڡڡڡڡڡ�
	~User_Information();
};

#endif // !USER_INFO