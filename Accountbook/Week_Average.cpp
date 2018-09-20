#include "myclass.h"
#include "Week_Average.h"
#include "Error_Check.h"

Error_Check err_Average;


//★★★★★★★★★★★★★ 미션 4 : 생성자 ★★★★★★★★★★★★★
Week_Average::Week_Average() { 
	cout << "Week_Average 객체가 생성되었습니다.\n";
	wmonth = 0;
	wweek = 0;
	wselect = 0;
	total_in = 0;
	total_out = 0;
	year_total = 0;
	sum = 0;
	mon = 0;
}

void Week_Average::Manual_Show() { // 메뉴를 보여주는 함수

	system("cls");
	cout << "=====================================================================================================\n";
	cout << "\t\t\t　　         기간별 사용량 조회 메뉴입니다　　　　\n";
	cout << "=====================================================================================================\n\n";
	cout << "\t\t\t◆ 메뉴를 선택해주세요\n\n";
	cout << "\t\t\t ①. 주간 통계  ②.한 달 통계  ③.월별 통계  [0].나가기\n";
	
	do {
		cout << "\n\t\t\t ▶ 입력 : ";
		wselect = err_Average.Number_Check(ESELECT, "3");
	} while (wselect < 0 || wselect > 3);

	mon = 1;
	total_in = 0;
	total_out = 0;
}

void Week_Average::Month_Input(int &tmp_month) { // 월을 입력받는 함수

	do {
		cout << "\n\t\t\t ▶ 월(月)을 입력해주세요 : ";
		wmonth = err_Average.Number_Check(EDATE, "12");
	} while (wmonth < 1 || wmonth > 12);

	tmp_month = wmonth;
}

int Week_Average::Mneu_Select(int &start, int &end, int &tmp_month) { // 메뉴를 고르는 함수

	switch (wselect) {
	case 1:
		Month_Input(tmp_month); // 월 입력
		Week_Input(start, end); // 주 입력
		switch (wweek) {
		case 1:
			start = 1;
			end = 8;
			break;
		case 2:
			start = 9;
			end = 16;
			break;
		case 3:
			start = 17;
			end = 24;
			break;
		case 4:
			start = 25;
			end = 31;
			break;
		}
		break;
	case 2:
		Month_Input(tmp_month);
		start = 1;
		end = 31;
		break;
	case 3:
		start = 1;
		end = 31;
		break;
	case 0:
		system("cls");
		return 0;
	}
	system("cls");

	return wselect;
}

void Week_Average::Week_Input(int &start, int &end) { // 주를 입력받는 함수

	cout << "\n=====================================================================================================\n";
	cout << "\t\t\t        조회하고 싶은 주차를 선택해주세요\n";
	cout << "=====================================================================================================\n";
	cout << "\t\t\t                ①. 1주차 (1 ~ 8)\n";
	cout << "\t\t\t                ②. 2주차 (9 ~ 16)\n";
	cout << "\t\t\t                ③. 3주차 (17 ~ 24)\n";
	cout << "\t\t\t                ④. 4주차 (25 ~ 31)\n";
	cout << "\t\t\t               [0]. 나 가 기\n";

	do {
		cout << "\n\t\t                ▶ 입력 : ";
		wweek = err_Average.Number_Check(ESELECT, "4"); // 입력받은 숫자가 올바른지 확인		
	} while (wweek < 0 || wweek > 4);
}

// 주차 사용확인, 한 달 통계, 월별 사용량을 계산하는 함수
//★★★★★★★★★★★★★ 미션 3 : 객체 매개변수 전달 ★★★★★★★★★★★★★
void Week_Average::Calculate(int week_start, int week_end, int dindex, DayUsing dayuse, int month) { 
	
	switch (wselect) {
	case 1:
		for (int j = 0; j < dindex; j++) {
			if (dayuse.inout[j] == "지출")
				total_out += dayuse.money[j];
			else if (dayuse.inout[j] == "수입")
				total_in += dayuse.money[j];
		}
		break;
	case 2:
		for (int j = 0; j < dindex; j++) {
			if (dayuse.inout[j] == "지출")
				total_out += dayuse.money[j];
			else if (dayuse.inout[j] == "수입")
				total_in += dayuse.money[j];
		}
		break;
	case 3:
		for (int i = 0; i < dindex; i++) {
			if (dayuse.inout[i] == "지출") {
				total_out += dayuse.money[i];
			}
		}
		if (month == 12 && week_start == week_end)
			year_total += int(total_out);

		break;
	}
}

// 월 사용량을 계산하는 함수
//★★★★★★★★★★★★★ 미션 3 : 객체 매개변수 전달 ★★★★★★★★★★★★★
void Week_Average::Go(int week_start, int week_end, int dindex, DayUsing dayuse, int month) {
	
	total_in = 0;
	for (int i = 0; i < dindex; i++) {
		if (dayuse.inout[i] == "지출") {
			total_in += dayuse.money[i];
		}
	}
	cout << "\n 월 사용량(%) : ";
}

// 주, 월, 년에 따라서 계산한 값을 출력하는 함수
//★★★★★★★★★★★★★ 미션 3 : 객체 매개변수 전달 ★★★★★★★★★★★★★
void Week_Average::Total_Print(int week_start, int week_end, int dindex, DayUsing dayuse, int month) {

	switch (wselect) {
	case 1:
		sum = 0;
		for (int j = 0; j < dindex; j++) {
			if (dayuse.inout[j] == "지출")
				sum += dayuse.money[j];
		}
		cout << "\n\t\t\t" << wmonth << " 월 " << week_start << " 일 사용량(%) :\t" << roundf((sum * 100) / total_out) << " %\t 지출액 :\t" << sum << " 원";

		if (week_start == week_end) {
			cout << "\n\n\t\t\t\t▶ " << wweek << "주차 총 지출 : " << total_out << " 원\t>";
			cout << "\n\t\t\t\t▶ " << wweek << "주차 총 수입 : " << total_in << " 원\t>\n";
			sum = 0;
		}

		break;
	case 2:
		if (week_start == 1) {
			cout << "\n\n\t\t\t\t\t < " << wmonth << " 월 사용통계 >\n";
			cout << "=====================================================================================================\n";
		}

		if (week_start <= 8) {
			for (int i = 0; i < dindex; i++) {
				if (dayuse.inout[i] == "지출")
					sum += dayuse.money[i];
			}
			if (week_start == 8) {
				cout << "\n\n\t\t\t\t    - 1주차( 1- 8) 사용량(%) : " << roundf((sum * 100) / total_out) << " %";
				sum = 0;
			}
		}
		else if (week_start > 8 && week_start <= 16) {
			for (int i = 0; i < dindex; i++) {
				if (dayuse.inout[i] == "지출")
					sum += dayuse.money[i];
			}
			if (week_start == 16) {
				cout << "\n\n\t\t\t\t    - 2주차( 9-16) 사용량(%) : " << roundf((sum * 100) / total_out) << " %";
				sum = 0;
			}
		}
		else if (week_start > 16 && week_start <= 24) {
			for (int i = 0; i < dindex; i++) {
				if (dayuse.inout[i] == "지출")
					sum += dayuse.money[i];
			}
			if (week_start == 24) {
				cout << "\n\n\t\t\t\t    - 3주차(17-24) 사용량(%) : " << roundf((sum * 100) / total_out) << " %";
				sum = 0;
			}
		}
		else if (week_start > 24 && week_start <= 31) {
			for (int i = 0; i < dindex; i++) {
				if (dayuse.inout[i] == "지출")
					sum += dayuse.money[i];
			}
			if (week_start == 31) {
				cout << "\n\n\t\t\t\t    - 4주차(25-31) 사용량(%) : " << roundf((sum * 100) / total_out) << " %";
				sum = 0;
			}
		}

		if (week_start == week_end) {
			cout << "\n\n\t\t\t\t   ▶ " << wmonth << "월(月) 총 지출 : " << total_out << " 원";
			cout << "\n\t\t\t\t   ▶ " << wmonth << "월(月) 총 수입 : " << total_in << " 원\n";
			sum = 0;
		}

		break;
	case 3:
		if (month == 1 && week_start == 1) {
			total_out = 0;
			cout << "=====================================================================================================\n";
		}

		for (int j = 0; j < dindex; j++) {
			if (dayuse.inout[j] == "지출")
				total_out += dayuse.money[j];
		}

		if (week_start == week_end) {
			if(month % 2 == 1)
				cout << "\t\t\t" << month << " 월 사용 :\t" << roundf((total_out * 100) / year_total) << " %\t";
			else
				cout << "\t" << month << " 월 사용 :\t" << roundf((total_out * 100) / year_total) << " %\n";
		}

		if (month == 12 && week_start == week_end) {
			cout << "\n\t\t\t-----------------------------------------------------";
			cout << "\n\t\t\t\t   ▶ 1년 총 사용량 : " << year_total << " 원" << endl;
			year_total = 0;
		}

		if (month > mon) {
			mon++;
			total_out = 0;
		}

		break;
	}
}

//★★★★★★★★★★★★★ 미션 4 : 소멸자 ★★★★★★★★★★★★★
Week_Average::~Week_Average() {
	cout << "Week_Average 객체가 소멸되었습니다.\n";
}