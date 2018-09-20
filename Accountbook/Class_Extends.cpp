#include "myclass.h"
#include "Using_Show.h"
#include "Class_Extends.h"


//★★★★★★★★★ 미션 11 : 클래스를 상속받고 활용 ★★★★★★★★★

//★★★★★★★★★★★★★ 미션 4 : 생성자 ★★★★★★★★★★★★★
Class_Extends::Class_Extends() {
	cout << "Using_Show class를 상속받았습니다.\n";
	mon = 0;
	date = 0;
}

//★★★★★★★★★★★★★ 미션 4 : 소멸자 ★★★★★★★★★★★★★
Class_Extends::~Class_Extends() {
	cout << "Class_Show 객체가 소멸되었습니다.\n";
}