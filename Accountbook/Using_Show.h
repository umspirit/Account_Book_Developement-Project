#ifndef USING_SHOW
#define USING_SHOW

class Using_Show { // 사용내역을 보여주는 함수를 가진 class 

	int mon	 = 0; // 월을 입력받는 변수
	int date = 0;// 일을 입력받는 변수
	int uselect;
public:

	//★★★★★★★★★★★★★ 미션 4 : 생성자 ★★★★★★★★★★★★★
	Using_Show();
	void First_show(); // 월과 일을 입력받는 함수
	int Month_Input();
	int Day_Input();
	void SetMon(int dmon);
	void SetDay(int dday);
	void Second_show(Using_Show &us, DayUsing &dayuse, int &uindex, int &account); //         미션 3 : 객체 매개변수 전달
	void String_sort(DayUsing &dayuse, int uindex, string &tapstr);
	//★★★★★★★★★★★★★ 미션 4 : 소멸자 ★★★★★★★★★★★★★
	~Using_Show();
};

#endif // !USING_SHOW