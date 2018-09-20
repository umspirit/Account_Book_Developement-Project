#include "myclass.h"
#include "Using_Show.h"
#include "Error_Check.h"

Error_Check err_Using;


//★★★★★★★★★★★★★ 미션 4 : 생성자 ★★★★★★★★★★★★★
Using_Show::Using_Show() {
	cout << "Using_Show 객체가 생성되었습니다.\n";
} 

void Using_Show::SetMon(int dmon) {
	mon = dmon;
}

void Using_Show::SetDay(int dday) {
	date = dday;
}

//★★★★★★★★★★★★★ 미션 3 : 객체 매개변수 전달 ★★★★★★★★★★★★★
void Using_Show::String_sort(DayUsing &dayuse, int uindex, string &tapstr) {
	int maxleng_use = 3;
	int tmpint;

	for (int i = 0; i < uindex; i++) {
		if (maxleng_use < dayuse.use[i].length()) {
			maxleng_use = dayuse.use[i].length();
		}
	}
	if (maxleng_use < 8) {
		tapstr = "\t";
	}
	else {
 		for (int i = 0; i < uindex; i++) {
			tmpint = maxleng_use - dayuse.use[i].length();
			for (int j = 0; j <= tmpint - 2; j++) {
				dayuse.use[i] += "  ";
				if(dayuse.use[i].length() < 4)
					dayuse.use[i] += "  ";
			}
		}
	}
}

void Using_Show::First_show() { // 콘솔창에 출력을 한다.

	cout << "\t\t\t    =======================================\n";
	cout << "\t\t\t     　　　　사용내역 확인 메뉴입니다　　　　 \n";
	cout << "\t\t\t    =======================================\n\n";
}
/*★★★★★★★★★★★★★★★★★★★★★★★★★
미션 3 객체 매개변수 전달
*///★★★★★★★★★★★★★★★★★★★★★★★★

int Using_Show::Month_Input() { // 월을 입력받는 함수

	do {
		cout << "\t\t\t\t　▶ 월(月) 을 입력해주세요 : ";
		mon = err_Using.Number_Check(EDATE, ""); // 입력가능한 수인지 확인하고 저장
	} while (mon < 1 || mon > 12);
	
	return mon;
}

int Using_Show::Day_Input() { // 일을 입력받는 함수

	do {
		cout << "\n\t\t\t\t　▶ 일(日) 을 입력해주세요 : ";
		date = err_Using.Number_Check(EDATE, "");
	} while (date < 1 || date > 31);

	return date;
}

//★★★★★★★★★★★★★ 미션 3 : 객체 매개변수 전달 ★★★★★★★★★★★★★
void Using_Show::Second_show(Using_Show &us, DayUsing &dayuse, int &uindex, int &account) { // 사용내역 보여주는 함수

	int total_out = 0;
	int total_in  = 0;
	string tmpstr, tapstring = "";
	int tmpint;

	system("cls");
	cout << "\n\t\t\t\t\t< " << us.mon << "월  " << us.date << "일 사용내역 >\n\n";

	cout << "\t번호\t입금&출금\t방법\t\t내용\t\t금액\t\t등록시간" << endl;
	cout << "-----------------------------------------------------------------------------------------------------" << endl;

	//★★★★★★★★★★★★★ 미션 3 : 객체 매개변수 전달 ★★★★★★★★★★★★★
	String_sort(dayuse, uindex, tapstring);

	for (int i = 0; i < uindex; i++) { // for문을 이용해서 배열에 있는 것을 모두 출력
		if (dayuse.money[i] < 10000)
			tmpstr = "　";
		else
			tmpstr = "";

		if (dayuse.inout[i] == "지출") {
			cout << "\t" << i+1 << " )\t" << dayuse.inout[i] << "\t\t<" << dayuse.way[i] << ">\t\t" << dayuse.use[i] << tapstring << "\t- " << dayuse.money[i] << "원" << tmpstr << "\t" << dayuse.storetime[i] << endl;
			total_out += dayuse.money[i];
		}
		else {
			cout << "\t" << i+1 << " )\t" << dayuse.inout[i] << "\t\t<" << dayuse.way[i] << ">\t\t" << dayuse.use[i] << tapstring << "\t+ " << dayuse.money[i] << "원" << tmpstr << "\t" << dayuse.storetime[i] << endl;
			total_in += dayuse.money[i];
		}
	}
	cout << " \n\t\t\t\t▶ 총 지출금액 : " << total_out << " 원";
	cout << " \n\t\t\t\t▶ 총 수입금액 : " << total_in << " 원 " << endl;
	cout << " \n\t\t\t\t◆ 현재 사용가능금액 : " << account << " 원\n\n";
}

//★★★★★★★★★★★★★ 미션 4 : 소멸자 ★★★★★★★★★★★★★
Using_Show::~Using_Show() {
	// 생성되고 소멸되는 부분이 많기 때문에 아무것도 쓰지 않았습니다.
}