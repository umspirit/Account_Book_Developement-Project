#ifndef USING_SHOW
#define USING_SHOW

class Using_Show { // ��볻���� �����ִ� �Լ��� ���� class 

	int mon	 = 0; // ���� �Է¹޴� ����
	int date = 0;// ���� �Է¹޴� ����
	int uselect;
public:

	//�ڡڡڡڡڡڡڡڡڡڡڡڡ� �̼� 4 : ������ �ڡڡڡڡڡڡڡڡڡڡڡڡ�
	Using_Show();
	void First_show(); // ���� ���� �Է¹޴� �Լ�
	int Month_Input();
	int Day_Input();
	void SetMon(int dmon);
	void SetDay(int dday);
	void Second_show(Using_Show &us, DayUsing &dayuse, int &uindex, int &account); //         �̼� 3 : ��ü �Ű����� ����
	void String_sort(DayUsing &dayuse, int uindex, string &tapstr);
	//�ڡڡڡڡڡڡڡڡڡڡڡڡ� �̼� 4 : �Ҹ��� �ڡڡڡڡڡڡڡڡڡڡڡڡ�
	~Using_Show();
};

#endif // !USING_SHOW