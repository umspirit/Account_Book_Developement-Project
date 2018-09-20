#include "myclass.h"
#include "Time_Compute.h"


//★★★★★★★★★★★★★ 미션 4 : 생성자 ★★★★★★★★★★★★★
Time_Compute::Time_Compute() { 
	cout << "Time_Compute 객체가 생성되었습니다.\n";
	SetPtime();
}

void Time_Compute::SetTime() { // 시간을 업데이트하는 함수(초기화)
	time(&the_time);
	SetPtime();
}

void Time_Compute::SetPtime() { // 시간을 tm구조체에 다시 주는 함수
	p_time = localtime(&the_time);
}

int Time_Compute::getMonth() { // 월을 반환하는 함수
	return p_time->tm_mon + 1;
}

int Time_Compute::getDay() { // 일을 반환하는 함수
	return p_time->tm_mday;
}

string Time_Compute::ReturnString(string &daystr) { // 일정혁식의 시간을 저장한 문자열을 반환하는 함수
	char timestr[20];								   // 값 저장에 쓰이는 문자열을 반환

	SetTime(); // 시간 업데이트
	strftime(timestr, sizeof(timestr), "%Y/%m/%d-%H:%M", p_time);
	daystr = timestr;

	return daystr;
}

//★★★★★★★★★★★★★ 미션 4 : 소멸자 ★★★★★★★★★★★★★
Time_Compute::~Time_Compute() {
	cout << "Time_Compute 객체가 소멸되었습니다.\n";
}