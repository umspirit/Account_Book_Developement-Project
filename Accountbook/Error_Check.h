#ifndef ERROR_CHECK 
#define ERROR_CHECK

class Error_Check {

public:

	//≮≮≮≮≮≮≮≮≮≮≮≮≮ 固记 4 : 积己磊 ≮≮≮≮≮≮≮≮≮≮≮≮≮
	Error_Check();
	int Number_Check(int n, string endnum);
	string Modify_Check(string endnum);
	bool Money_isDigit(string str, string endnum);
	bool Date_Digit(string str);
	bool Select_Digit(string str, string endnum);
	bool Modify_Digit(string str, string endnum);
	bool Function_Select(int select, string endnum, string str);
	//≮≮≮≮≮≮≮≮≮≮≮≮≮ 固记 4 : 家戈磊 ≮≮≮≮≮≮≮≮≮≮≮≮≮
	~Error_Check();
};

#endif // !