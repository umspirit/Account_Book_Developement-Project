#ifndef ERROR_CHECK 
#define ERROR_CHECK

class Error_Check {

public:

	//�ڡڡڡڡڡڡڡڡڡڡڡڡ� �̼� 4 : ������ �ڡڡڡڡڡڡڡڡڡڡڡڡ�
	Error_Check();
	int Number_Check(int n, string endnum);
	string Modify_Check(string endnum);
	bool Money_isDigit(string str, string endnum);
	bool Date_Digit(string str);
	bool Select_Digit(string str, string endnum);
	bool Modify_Digit(string str, string endnum);
	bool Function_Select(int select, string endnum, string str);
	//�ڡڡڡڡڡڡڡڡڡڡڡڡ� �̼� 4 : �Ҹ��� �ڡڡڡڡڡڡڡڡڡڡڡڡ�
	~Error_Check();
};

#endif // !