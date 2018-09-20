#include "myclass.h"
#include "Data_Modify.h"
#include "Error_Check.h"
#include "Using_Show.h"
#include "Week_Average.h"
#include "Class_Extends.h"
#include "Time_Compute.h"


DayUsing		dayuse;
Using_Show		user;
Data_Modify		datamf;
Error_Check		error;
Week_Average	weekcheck;
Class_Extends	classext;
Time_Compute	timecom;

//★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★
// 미션 3 : Using_Show 클래스 객체포인터 -> 미션 5 : 객체포인터를 객체선언으로 수정
//★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★

int smoney	= 0;	 // 지출 금액보다 가진 돈이 적을 경우를 검사하기 위해 쓰는 변수
int month	= 0;	 // 월을 저장하는 변수
int day		= 0;	 // 일을 저장하는 변수
int wstart	= 0;	 // 일의 시작값
int wend	= 0;	 // 일의 종료값
enum STAT status;	 // 가계부의 상태를 저장하는 열거형 변수


void Performance(int n) {
	int outindex = 0;

	while (outindex < n) {
		cout << "\nRUNNING... ";
		for (int i = 0; i < n; i++) {
			if (i < n-1)
				cout << "#";
			if (i == n-1)
				cout << "# SUCCESS !!\n";
			outindex++;
			Sleep(20);
		}
		Sleep(300);
		outindex++;
	}
}

void Dinamic() { // 2차원 배열 동적할당하기 위해서 사용한 함수
	for (int i = 0; i < 13; i++) { 
		dayusing[i] = new DayUsing[32]; 
	}
}
	
void Data_Reading() {							//★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★
	ifstream faccount("데이터베이스/계좌.txt");	//			미션 7 : file 입출력 중 파일에서 값 읽어오기 
												//★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★
	if (!faccount.is_open()) {
		cout << "잔액을 불러올 수 없습니다.";
	}
	else {
		while (!faccount.eof()) { // 사용자가 가지고 있는 잔액을 불러옵니다.
			faccount >> *userinfo.account;
		}
		if (faccount.is_open() == true)
			faccount.close();	  // 열었던 파일을 닫습니다.
	}
}

void Data_UseReading() {					//★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★
											//			미션 7 : file 입출력 중 파일에서 값 읽어오기
	for (int i = 1; i <= 12; i++) {			//★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★
		for (int j = 1; j <= 31; j++) {		// 1월부터 12월까지의 데이터를 읽어옮니다.
			string strmon;		// 월 저장
			string strdate;		// 일 저장
			string fstring;		// 텍스트파일경로가 저장됩니다.

			strmon = to_string(i);
			strdate = to_string(j);
			fstring = "데이터베이스/데이터/" + strmon + "/" + strmon + "월" + strdate + "일.txt"; // 텍스트파일 경로

			ifstream fusing(fstring);

			if (fusing.is_open() == false) { // 파일을 열지 못했을 경우
				// 너무 많이 뜨기 때문에 출력문 생략
			}
			else {
				while (!fusing.eof()) { // 파일의 끝까지 가져온다.
					fusing >> dayusing[i][j].inout[index[i][j]] >> dayusing[i][j].way[index[i][j]] >> dayusing[i][j].use[index[i][j]] >> dayusing[i][j].money[index[i][j]] >> dayusing[i][j].storetime[index[i][j]];
					index[i][j]++;
				}
				index[i][j]--; // 마지막 값이 쓰레기 값이 읽어와지는데 index를 1감소 시킴으로서 오류를 없앰
				if (fusing.is_open() == true)
					fusing.close();			 // 파일이 열려있으면 닫는다.
			}
		}
	}
}

void Dinamin_Clear() { // 동적할당 해제하는 함수

	//구조체 User_Info 동적할당 해제
	delete userinfo.account;

	// DayUsing class 2차원 배열 동적할당 해제
	for (int i = 0; i < 13; i++) { 
		delete []dayusing[i];
	}
	delete []dayusing;
	cout << "\n 동적 할당이 모두 해제되었습니다. \n";
}

void File_store(int month, int day) {						

	string fstring;								//★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★
	ofstream faccount("데이터베이스/계좌.txt");	//					미션 7 : file 입출력 중 파일에 저장
	faccount << *userinfo.account;				//★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★
	faccount.close();

	if (status == START) { // 모두 데이터 저장 (가계부가 종료될 때 실행)
		for (int i = 1; i <= 12; i++) {		// 1월부터 12월까지의 데이터를 수정된 것을 모두 저장하기 위한 for문
			for (int j = 1; j <= 31; j++) {

				fstring = "데이터베이스/데이터/" + to_string(i) + "/" + to_string(i) + "월" + to_string(j) + "일.txt";

				if (index[i][j] > 0) { // 내용이 있는 파일만 저장
					ofstream fusing(fstring);
					int findex = 0;
					while (findex < index[i][j]) {
						fusing << dayusing[i][j].inout[findex] << "\t" << dayusing[i][j].way[findex] << "\t" << dayusing[i][j].use[findex] << "\t" << dayusing[i][j].money[findex] << "\t" << dayusing[i][j].storetime[findex] << endl;
						findex++;
					}
					fusing.close();
				}
				else { // 아무 내용도 기록되지 않은 파일은 삭제
					remove(fstring.c_str());
				}
			}
		}
		status = RUN;
	}
	else if (status == RUN) { // 업데이트된 데이터만 저장
		fstring = "데이터베이스/데이터/" + to_string(month) + "/" + to_string(month) + "월" + to_string(day) + "일.txt";
		if (index[month][day] > 0) {
			ofstream fusing(fstring);

			int findex = 0;
			while (findex < index[month][day]) {
				fusing << dayusing[month][day].inout[findex] << "\t" << dayusing[month][day].way[findex] << "\t" << dayusing[month][day].use[findex] << "\t" << dayusing[month][day].money[findex] << "\t" << dayusing[month][day].storetime[findex] << endl;
				findex++;
			}
			fusing.close();
		}
		else { // 아무 내용도 기록되지 않은 파일은 삭제
			remove(fstring.c_str());
		}
	}
}

//★★★★★★★★★★★★★ 미션 4 : 생성자 ★★★★★★★★★★★★★
AccountBook_Start::AccountBook_Start() {  // 가계부를 동작시키는 생성자
	system("cls");

	status = RUN;
	int outindex = 0;

	Performance(15);
	system("cls");
	show();

	while (true) {
		timecom.SetTime();
		Menu_Display();
		Menu_Select();
	}
}

void AccountBook_Start::show() { // 처음보여지는 함수 + ID / PW 를 확인합니다.
	bool good = true;

	cout << "\t\t   ★★★★★★★★★ 약방의 감초 가계부 ★★★★★★★★★\n\n";
	cout << "\t\t\t ↓ 사용자 아이디와 비밀번호를 입력해주세요. \n\n";
	cout << "\t\t\t\t◆ ID　　　: ";

	ifstream idpw("데이터베이스/IDPW.txt");

	idpw >> id >> id2 >> pw >> pw2;

	while (good) {
		setID();
		if (userinfo.name == id || userinfo.name == id2) {
			cout << "\t\t\t\t아이디가 확인되었습니다.";
			while (true) {
				cout << "\n\t\t\t\t◆ PW　　　: ";
				setPasswd();
				if (userinfo.pw == pw || userinfo.pw == pw2) {
					good = false;
					system("cls");
					return;
				}
				else {
					cout << "\t\t\t\t비밀번호가 일치하지 않습니다.\n";
				}
			}
		}
		else {
			cout << "\t\t\t아이디가 일치하지 않습니다.\n";
			cout << "\t\t\t ◆ ID　　　: ";
		}
	}
}

void AccountBook_Start::Menu_Display() { // 메뉴 보여주는 함수

	cout << "=====================================================================================================\n";
	cout << "\t\t\t　　　◆ 이용하실 서비스를 선택해주세요 ◆\n\n";
	cout << "\t\t\t         　　　①. 지출등록\n\n";
	cout << "\t\t\t         　　　②. 수입등록\n\n";
	cout << "\t\t\t         　　　③. 사용내역 조회\n\n";
	cout << "\t\t\t         　　　④. 기간별 사용량 조회\n\n";
	cout << "\t\t\t         　　　⑤. 데이터수정\n\n";
	cout << "\t\t\t　　　　　　　[0]. 사용종료(저장)\n";
	cout << "=====================================================================================================\n\n";
}

int AccountBook_Start::Menu_Select() { // 메뉴 선택할 수 있도록 입력을 받고 그 메뉴를 실행시켜준다.
	int num, tmp_month, tmp_day;

	do {
		cout << "\n\t\t\t　　　　　　   ▶ 입력 : ";
		num = error.Number_Check(ESELECT, "5"); // num에 저장할 수 있는 값인지 확인	
	} while (num < 0 || num > 5);

	switch (num) {
	case 1: // 지출 등록 기능 선택
		Account_Register(*userinfo.account, num);
		break;
	case 2: // 수입 등록 기능 선택
		Account_Register(*userinfo.account, num);
		break;
	case 3: // 사용내역확인 기능 선택
		// ★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★
		//	 미션 11 : 상속받는 class 활용 Using_Show를 상속받은 Class_Extends 클래스 객체 classext가 사용되었습니다.
		// ★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★
	{
		DayUsing tmpuse;
		classext.First_show();
		cout << "\n\t\t\t 1. 오늘날짜 확인 2. 다른날짜 확인 0. 나가기\n";
		cout << "\n\t\t\t　　　　　　   ▶ 입력 : ";
		num = error.Number_Check(ESELECT, "2");

		switch (num) {
		case 1:
			tmp_month = timecom.getMonth();
			tmp_day = timecom.getDay();
			classext.SetMon(tmp_month);
			classext.SetDay(tmp_day);
			break;
		case 2:
			tmp_month = classext.Month_Input();
			tmp_day = classext.Day_Input();
			break;
		case 0:
			system("cls");
			return 0;
		}
		tmpuse = dayusing[tmp_month][tmp_day];
		//★★★★★★★★★ 미션 3 : 객체 매개변수 전달 ★★★★★★★★★
		user.Second_show(classext, tmpuse, index[tmp_month][tmp_day], *userinfo.account);
	}
		break;
	case 4:
		int wselect;
		weekcheck.Manual_Show();
		wselect = weekcheck.Mneu_Select(wstart, wend, tmp_month);

		switch (wselect)
		{
		case 1:
			for (int i = wstart; i <= wend; i++)
				weekcheck.Calculate(wstart, wend, index[tmp_month][i], dayusing[tmp_month][i], i);
			for (int i = wstart; i <= wend; i++)
				weekcheck.Total_Print(i, wend, index[tmp_month][i], dayusing[tmp_month][i], i);
			break;
		case 2:
			for (int i = wstart; i <= wend; i++)
				weekcheck.Calculate(wstart, wend, index[tmp_month][i], dayusing[tmp_month][i], i);
			for (int i = wstart; i <= wend; i++)
				weekcheck.Total_Print(i, wend, index[tmp_month][i], dayusing[tmp_month][i], i);
			break;
		case 3:
			for (int i = 1; i < 13; i++) {
				for (int j = wstart; j <= wend; j++) {
					weekcheck.Calculate(j, wend, index[i][j], dayusing[i][j], i);
				}
			}
			for (int i = 1; i < 13; i++) {
				for (int j = wstart; j <= wend; j++) {
					weekcheck.Total_Print(j, wend, index[i][j], dayusing[i][j], i);
				}
			}
			break;
		case 0:
			system("cls");
			break;
		}
		break;
	case 5:
		num = datamf.Menu_Show(); // 데이터 수정 기능 선택
		if (num != 0) {
			tmp_month = datamf.Month_Input();
			tmp_day = datamf.Day_Input();

			//★★★★★★★★★ 미션 3 : 객체 매개변수 전달 ★★★★★★★★★
			dayuse = dayusing[tmp_month][tmp_day];
			if (datamf.Select_Show(index[tmp_month][tmp_day], dayuse) == true) {
				datamf.Menu_Select(status, index[tmp_month][tmp_day], *userinfo.account, dayuse);
				dayusing[tmp_month][tmp_day] = dayuse;
			}
		}
		else if (num == 0) {
			system("cls");
		}
		break;
	case 0: // 시스템 종료 기능 선택
		status = START;
		File_store(month, day);
		Dinamin_Clear();
		Performance(20);
		System_exit();
		break;
	}
	return num;
}

void AccountBook_Start::Account_Register(int &account, int IOnum) { // 지출을 입력해주는 함수
	string str;

	cout << "\n\t\t\t ①. 오늘 날짜\t ②. 다른 날짜\t [0]. 나가기\n\n";
	cout << "\t\t\t\t▶ 입력 : ";
	aselect = error.Number_Check(ESELECT, "2"); // 입력가능한 수인지 확인하고 저장
	
	switch (aselect) {
	case 1: // 오른 날짜로 가계부를 등록할 때
		month = timecom.getMonth(); // 오늘 날짜를 변수에 저장
		day = timecom.getDay();
		break;
	case 2: // 다른 날짜로 가계부를 등록할 때
		do {
			cout << "\n\t\t\t　▶ 월(月) 을 입력해주세요 : ";
			month = error.Number_Check(EDATE, "12"); // 입력가능한 수인지 확인하고 저장
		} while (month < 1 || month > 12);

		do {
			cout << "\n\t\t\t　▶ 일(日) 을 입력해주세요 : ";
			day = error.Number_Check(EDATE, "31"); // 입력가능한 수인지 확인하고 저장
		} while (day < 1 || day > 31);

		break;
	case 0: // 중단하고 나가기
		system("cls");
		return;
		break;
	}
	system("cls");

	while (true) {
		cout << "\n\t\t\t　▶ 지불방식을 선택해주세요\n\n";
		cout << "\t\t\t    ①. 현금   ②. 카드  [0]. 나가기 -> ";

		aselect = error.Number_Check(ESELECT, "2"); // 입력가능한 수인지 확인 후 저장
		system("cls");

		if (aselect != 0) { // 3번 나가기를 선택한 경우 실행안하고 함수종료

			if (IOnum == 1)		 // 1 == 지출일때
				cout << "\n\t\t\t　▶ 지출내용을 입력해주세요 : ";
			else if (IOnum == 2) // 2 == 수입일때
				cout << "\n\t\t\t　▶ 수입내용을 입력해주세요 : ";

			cin >> dayusing[month][day].use[index[month][day]];

			if (IOnum == 1)		 // 1 == 지출일때
				cout << "\n\t\t\t　▶ 지출금액을 입력해주세요 : ";
			else if (IOnum == 2) // 2 == 수입일때
				cout << "\n\t\t\t　▶ 수입금액을 입력해주세요 : ";
			dayusing[month][day].money[index[month][day]] = error.Number_Check(EMONEY, "");

			UseWay_Check(aselect);

			cout << "\n\t   =========================================================================";
			if (IOnum == 1) {		// 지출등록을 할 때
				if (Underflow_Money(account, month, day)) { // 지출금액이 사용가능액보다 작으면 if문 내용 실행
					dayusing[month][day].inout[index[month][day]] = "지출";
					account -= dayusing[month][day].money[index[month][day]];
					dayusing[month][day].storetime[index[month][day]] = timecom.ReturnString(str);
					cout << "\n\t\t\t   " << dayusing[month][day].money[index[month][day]] << " 원이 지출되어, 사용가능액은 " << account << " 원입니다.\n";
					index[month][day]++;
				}
			}
			else if (IOnum == 2) { // 수입등록을 할 때
				dayusing[month][day].inout[index[month][day]] = "수입";
				account += dayusing[month][day].money[index[month][day]];
				dayusing[month][day].storetime[index[month][day]] = timecom.ReturnString(str);
				cout << "\n\t\t\t   " << dayusing[month][day].money[index[month][day]] << " 원이 입금되어, 사용가능액은 " << account << " 원입니다.\n";
				index[month][day]++;
			}
			cout << "\t   =========================================================================\n";
			File_store(month, day);
		}
		else {// 입력을 그만하고 나갈 때
			system("cls");
			return;
		}
	}
}

bool AccountBook_Start::Underflow_Money(int &account, int &month, int &day) { // 사용가능금액보다 지출금액이 클 경우를 대비한 함수

	if (account - dayusing[month][day].money[index[month][day]] < 0) { // 사용가능액 - 지출금액 > 0 면 false를 return
		cout << smoney << "\t\t\t ! 지출금액이 사용가능 금액보다 큽니다. !\n";
		dayusing[month][day].use[index[month][day]] = "";
		dayusing[month][day].money[index[month][day]] = 0;

		return false;
	}
	return true;
}

void AccountBook_Start::UseWay_Check(int select) { // 현금인지 카드인지 결정

	if (select == 1) {// 현금으로 등록할 때
		dayusing[month][day].way[index[month][day]] = "현금";
	}
	else if (select == 2) { // 카드로 등록할 때
		dayusing[month][day].way[index[month][day]] = "카드";
	}
}

void AccountBook_Start::System_exit() { // 가계부 시스템 종료 함수
	exit(0); // 종료
}

//★★★★★★★★★★★★★ 미션 4 : 소멸자 ★★★★★★★★★★★★★
AccountBook_Start::~AccountBook_Start() {
	cout << "객체가 소멸되었습니다.";
};

void AccountBook_Start::setID() { // 이름 설정을 설정하는 함수
	cin >> userinfo.name;
}

void AccountBook_Start::setPasswd() { // 사용 가능액을 설정하는 함수
	cin >> userinfo.pw;
}