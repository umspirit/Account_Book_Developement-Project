#ifndef DATA_MODIFY
#define DATA_MODIFY

class Data_Modify { // 입력된 정보를 수정하는 class

	int dmonth;
	int dday;
	int dselect;
	int dataindex;
public:

	//★★★★★★★★★★★★★ 미션 4 : 생성자 ★★★★★★★★★★★★★
	Data_Modify();
	int Menu_Show();
	bool Select_Show(int &dindex, DayUsing &dayuse);
	void Delete_Menu(STAT &status, int &dindex, int &account, DayUsing &dayuse);
	void Revise_Menu();
	int Month_Input();
	int Day_Input();
	void Menu_Select(STAT &status, int &dindex, int &account, DayUsing &dayuse);
	//★★★★★★★★★★★★★ 미션 4 : 소멸자 ★★★★★★★★★★★★★
	~Data_Modify();
};

#endif // !