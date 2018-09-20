#ifndef WEEK_AVERAGE
#define WEEK_AVERAGE


class Week_Average { // 주의 평균을 구하는 class
	int wmonth;
	int wweek;
	int wselect;
	float total_in;
	float total_out;
	int year_total;
	int sum;
	int mon;

public:

	//★★★★★★★★★★★★★ 미션 4 : 생성자 ★★★★★★★★★★★★★
	Week_Average();
	void Manual_Show();
	int Mneu_Select(int &start, int &end, int &tmp_month);
	void Calculate(int week_start, int week_end, int dindex, DayUsing dayuse, int month);
	void Month_Input(int &tmp_month);
	void Total_Print(int week_start, int week_end, int dindex, DayUsing dayuse, int month);
	void Week_Input(int &start, int &end);
	void Go(int week_start, int week_end, int dindex, DayUsing dayuse, int month);
	//★★★★★★★★★★★★★ 미션 4 : 소멸자 ★★★★★★★★★★★★★
	~Week_Average();
};

#endif // !WEEK_AVERAGE