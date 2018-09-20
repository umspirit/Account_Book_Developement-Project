/*
★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★


미션 9

-  미션8에서 사용중인 char* 을 string으로 바꾸고 string을 쓴 사람은 char *로 바꾸시오

★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★
*/

//★★★★★★★★★ 미션 8 : 멀티파일로 분리하기 ★★★★★★★★★

#include "myclass.h"
#include "Error_Check.h"
#include "Data_Modify.h"
#include "User_Infomation.h"

int main() { // 메인 함수
	
	Dinamic();			// 데이터 동적할당
	Data_Reading();		// 계좌잔액 읽어오기
	Data_UseReading();	// 데이터 읽어오기

	User_Information User;
	AccountBook_Start AccountStart; // 가계부 시작

	return 0;
}