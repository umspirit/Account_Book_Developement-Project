#include "myclass.h"
#include "Error_Check.h"


//★★★★★★★★★★★★★ 미션 4 : 소멸자 ★★★★★★★★★★★★★
Error_Check::Error_Check() { 
	cout << "Error_Check 객체가 생성되었습니다.\n";
}

bool Error_Check::Function_Select(int select, string endnum, string str) { // select 값에 맞는 함수를 실행시키는 함수

	switch (select) { // 맞는 값이 들어갔는지 체크를 하게 되는데, 기능별로 함수를 호출합니다.
	case 1:
		return Money_isDigit(str, endnum); // 돈을 제대로 숫자로 입력했는지 검사
	case 2:
		return Date_Digit(str); // 날짜를 월, 일에 맞게 제대로 입력했는지 검사
	case 3:
		return Select_Digit(str, endnum); // 그 외의 모든 것들이 제대로 입력됬는지 검사
	}
}

bool Error_Check::Money_isDigit(string str, string endnum) { // 입력된 돈의 값이 올바른지 확인하는 함수

	for (unsigned int i = 0; i < str.length() && i < endnum.length() ; i++) { // string의 각각의 자리수를 검사합니다
		if (str.at(i) < '0' || str.at(i) > '9') {							  // // 문자를 입력한 것을 검사합니다.
			cout << "\n\t\t\t　＠ 숫자만으로 입력해주세요 : ";
			return false;
		}
	}
	return true;
}

bool Error_Check::Date_Digit(string str) { // 날짜입력이 올바른지 확인하는 함수

	for (unsigned int i = 0; i < str.length(); i++) { // string의 각각의 자리수를 검사합니다
		if (str.at(i) < '0' || str.at(i) > '9') {	  // // 문자를 입력한 것을 검사합니다.
			cout << "\n\t\t\t　＠ 월, 일에 맞게 숫자를 입력해주세요 : ";
			return false;
		}
	}
	return true;
}

bool Error_Check::Select_Digit(string str, string endnum) { // 그 외의 선택한 값들이 올바른지 확인하는 함수

	for (unsigned int i = 0; i < str.length() && i < endnum.length(); i++) { // string의 각각의 자리수를 검사합니다
		if (str.at(i) < '0' || str.at(i) > endnum.at(i)) {					 // 문자를 입력한 것을 검사합니다.
			cout << "\n\t\t\t　＠ 0 ~ " << endnum << "번을 입력해주세요 : ";
			return false;
		}
	}
	if (str.length() == endnum.length()) // 맞게 입력한 경우
		return true;
	else { // 잘못된 숫자 값을 입력했을 경우 여기로 옵니다.
		cout << "\n\t\t\t　＠ 0 ~ " << endnum << "번을 입력해주세요 : ";
		return false;
	}
}

int Error_Check::Number_Check(int n, string endnum) { // 숫자를 체크하는 함수 
													  // 모든 숫자를 체크하는 함수들은 여기로 처음에 도달하게 됩니다.
	string str; 
	bool check = true;

	while (true) {
		cin >> str;							  // 입력한 값이 문자인지 아닌지 검사하기 위해서 string으로 입력받습니다.
		if (Function_Select(n, endnum, str))  // 숫자면
			break;
	}
	return atoi(str.c_str());
}

bool Error_Check::Modify_Digit(string str, string endnum) { // Data_Modify 함수에서 입력된 값을 확인하기 위한 함수
															// Data_Modify 함수에서만 ' * '입력을 받기위해서 만들었습니다.
	if (!strcmp(str.c_str(), "*")) {						// *일 때
		return true;
	}
	else {
		for (unsigned int i = 0; i < str.length() && i < endnum.length(); i++) {
			if (str.at(i) < '0' || str.at(i) > endnum.at(i)) {
				cout << "\n\t\t\t　＠ 0 ~ " << endnum << "번을 입력해주세요 : ";
				return false;
			}
		}
		if (str.length() == endnum.length())
			return true;
		else {
			cout << "\n\t\t\t　＠ 0 ~ " << endnum << "번을 입력해주세요 : ";
			return false;
		}
	}
}

string Error_Check::Modify_Check(string endnum) { // Data_Modify 함수에서 입력된 값을 확인하기 위한 함수
												  // Data_Modify 함수에서만 ' * '입력을 받기위해서 만들었습니다.
	string str;
	bool check = true;

	while (true) {
		cin >> str;
		if (Modify_Digit(str, endnum))  // 숫자면
			break;
	}
	return str;
}

//★★★★★★★★★★★★★ 미션 4 : 소멸자 ★★★★★★★★★★★★★
Error_Check::~Error_Check() {
	cout << "Error_Check 객체가 소멸되었습니다.\n";
}