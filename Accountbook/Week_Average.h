#ifndef WEEK_AVERAGE
#define WEEK_AVERAGE


class Week_Average { // ���� ����� ���ϴ� class
	int wmonth;
	int wweek;
	int wselect;
	float total_in;
	float total_out;
	int year_total;
	int sum;
	int mon;

public:

	//�ڡڡڡڡڡڡڡڡڡڡڡڡ� �̼� 4 : ������ �ڡڡڡڡڡڡڡڡڡڡڡڡ�
	Week_Average();
	void Manual_Show();
	int Mneu_Select(int &start, int &end, int &tmp_month);
	void Calculate(int week_start, int week_end, int dindex, DayUsing dayuse, int month);
	void Month_Input(int &tmp_month);
	void Total_Print(int week_start, int week_end, int dindex, DayUsing dayuse, int month);
	void Week_Input(int &start, int &end);
	void Go(int week_start, int week_end, int dindex, DayUsing dayuse, int month);
	//�ڡڡڡڡڡڡڡڡڡڡڡڡ� �̼� 4 : �Ҹ��� �ڡڡڡڡڡڡڡڡڡڡڡڡ�
	~Week_Average();
};

#endif // !WEEK_AVERAGE