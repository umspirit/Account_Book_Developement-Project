#ifndef DATA_MODIFY
#define DATA_MODIFY

class Data_Modify { // �Էµ� ������ �����ϴ� class

	int dmonth;
	int dday;
	int dselect;
	int dataindex;
public:

	//�ڡڡڡڡڡڡڡڡڡڡڡڡ� �̼� 4 : ������ �ڡڡڡڡڡڡڡڡڡڡڡڡ�
	Data_Modify();
	int Menu_Show();
	bool Select_Show(int &dindex, DayUsing &dayuse);
	void Delete_Menu(STAT &status, int &dindex, int &account, DayUsing &dayuse);
	void Revise_Menu();
	int Month_Input();
	int Day_Input();
	void Menu_Select(STAT &status, int &dindex, int &account, DayUsing &dayuse);
	//�ڡڡڡڡڡڡڡڡڡڡڡڡ� �̼� 4 : �Ҹ��� �ڡڡڡڡڡڡڡڡڡڡڡڡ�
	~Data_Modify();
};

#endif // !