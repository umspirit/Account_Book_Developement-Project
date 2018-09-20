#include "myclass.h"
#include "Data_Modify.h"
#include "Error_Check.h"


Error_Check err_Modify;

//★★★★★★★★★★★★★ 미션 4 : 생성자 ★★★★★★★★★★★★★
Data_Modify::Data_Modify() { // 생성자
	cout << "Data_Modify 객체가 생성되었습니다.\n";
}

int Data_Modify::Menu_Show() { // 메뉴를 보여주는 함수ㅡ
	system("cls");
	cout << "\t\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n";
	cout << "\t\t\t\t　　　　　 가계부내용 수정 메뉴\n\n";
	cout << "\t\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n";
	cout << "\t\t\t\t①. 데이터 삭제　[0]. 나가기\n\n";

	cout << "\n\t\t\t\t　▶ 입력 : ";
	dselect = err_Modify.Number_Check(ESELECT, "1");

	return dselect;
}
//★★★★★★★★★ 미션 3 : 객체 매개변수 전달 ★★★★★★★★★
void Data_Modify::Menu_Select(STAT &status, int &dindex, int &account, DayUsing &dayuse) {
	switch (dselect) {
	case 1:
		//★★★★★★★★★ 미션 3 : 객체 매개변수 전달 ★★★★★★★★★
		Delete_Menu(status, dindex, account, dayuse); // 삭제 기능 함수 실행
		break;
	case 0:
		break;
	}
}

int Data_Modify::Month_Input() {

	do {
		cout << "\n\t\t\t\t　▶ 월(月) 을 입력해주세요 : ";
		dmonth = err_Modify.Number_Check(EDATE, "");
	} while (dmonth < 1 || dmonth > 12);

	return dmonth;
}

int Data_Modify::Day_Input() {

	do {
		cout << "\n\t\t\t\t　▶ 일(日) 을 입력해주세요 : ";
		dday = err_Modify.Number_Check(EDATE, "");
	} while (dday < 1 || dday > 31);

	return dday;
}

//★★★★★★★★★ 미션 3 : 객체 매개변수 전달 ★★★★★★★★★
bool Data_Modify::Select_Show(int &dindex, DayUsing &dayuse) { // 월, 일을 입력하고, 그것을 토대로 저장된 자료를 나열해서 보여준다.

	cout << "\n\n\t\t\t\t\t<　" << dmonth << " 월　" << dday << " 일　>\n\n";

	if (dindex == 0) { // 데이터가 존재하지 않을 때
		cout << "\t\t\t\t !!!! 데이터가 존재하지 않습니다 !!!!\n";
		return false;
	}
	else { // 자료들을 나열해서 보여줍니다.
		for (int i = 0; i < dindex; i++) {
			cout << "\t\t\t\t" << i + 1 << ")\t<" << dayuse.way[i] << ">  " << dayuse.inout[i] << "내용 : " << dayuse.use[i];
			if (dayuse.inout[i] == "지출")
				cout << "  \t금액 : - " << dayuse.money[i] << "원\n";
			else
				cout << "  \t금액 : + " << dayuse.money[i] << "원\n";
		}
		return true;
	}
}
//★★★★★★★★★ 미션 3 : 객체 매개변수 전달 ★★★★★★★★★
void Data_Modify::Delete_Menu(STAT &status, int &dindex, int &account, DayUsing &dayuse) { // 자료를 삭제하는 함수

	while (true) {
		if (dindex == 0) {
			return;
		}

		cout << "\n\t\t\t\t  ! [0]번 나가기 / [*] : 모든 항목 삭제 !\n";
		cout << "\n\t\t\t\t　▶　삭제하실 항목을 선택해주세요 : ";
		string tmp;
		tmp = err_Modify.Modify_Check(to_string(dindex));
		dselect = atoi(tmp.c_str());

		if (!strcmp(tmp.c_str(), "*")) { // O월 O일 의 있는 데이터를 모두 삭제하는 경우
			for (int i = dindex - 1; i >= 0; i--) {
				if (dayuse.inout[i] == "지출")
					account += dayuse.money[i];
				else
					account -= dayuse.money[i];
				
				dayuse.use[i] = "";
				dayuse.way[i] = "";
				dayuse.money[i] = 0;
				dayuse.inout[i] = "";
				dayuse.storetime[i] = "";
			}
			dindex = 0;
		}
		else if (dselect != 0) { // O월 O일 의 있는 특정 데이터만 삭제하는 경우
			if (dayuse.inout[dselect] == "지출")
				account += dayuse.money[dselect - 1];
			else
				account -= dayuse.money[dselect - 1];

			for (int i = dselect - 1; i + 1 <= dindex; i++) { // 삭제된 곳부터 다음 자료를 땡겨서 저장
				dayuse.use[i] = dayuse.use[i + 1];
				dayuse.way[i] = dayuse.way[i + 1];
				dayuse.money[i] = dayuse.money[i + 1];
				dayuse.inout[i] = dayuse.inout[i + 1];
				dayuse.storetime[i] = dayuse.storetime[i + 1];
			}
			dindex--; // 1개가 삭제됬으니 자료개수 1 감소
			Select_Show(dindex, dayuse); // 추가적인 삭제를 묻는 함수호출
		}
		else if (dselect == 0) { // 삭제 기능 종료 -> 메뉴 선택
			system("cls");
			return;
		}
		File_store(dmonth, dday); // 삭제후 O월 O일의 파일에 자료 업데이트
	}
}

//★★★★★★★★★★★★★ 미션 4 : 소멸자 ★★★★★★★★★★★★★
Data_Modify::~Data_Modify() {
	cout << "Data_Modify 객체가 소멸되었습니다.\n";
}