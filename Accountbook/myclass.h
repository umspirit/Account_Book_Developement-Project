#ifndef MY_CLASS
#define MY_CLASS

#include <iostream>
#include <Windows.h>
#include <string> // string을 쓰기 위해서 string 을 include 
#include <fstream>
#include <math.h>
#include <time.h>

using namespace std;
// 일을 입력받는 변수

extern int	smoney; // 돈을 입력받는 변수
extern int	month; // 월을 입력받는 변수
extern int	day;   // 일을 입력받는 변수
static int	index[13][32];
enum STAT { START, RUN };
enum ERRNAME {EMONEY = 1, EDATE, ESELECT, EMODIFY};

static struct User_Info { // 유저의 이름과 사용가능 금액을 저장하기 위한 변수
											     //★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★
	char *name    = new char[20]; // 아이디               미션 9 : string을 char* 로 바꾸기
	char *pw	  = new char[20];   // 비밀번호   //★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★
	int  *account = new int; // 사용가능금액을 저장하는 변수
}userinfo;

static class DayUsing { // 하루 사용내용

public:
	string *use			= new string[40]; // 내용
	string *inout		= new string[40]; // 사용방법
	string *way			= new string[40]; // 지출 or 수입
	int    *money		= new int[40];	  // 사용액
	string *storetime	= new string[40]; // 등록시간

}**dayusing = new DayUsing*[13];  // 365일의 사용내역과 사용금액을 저장할 수 있도록 설계


class AccountBook_Start { // 가계부 시작 클래스
	int aselect;
	string id, id2, pw, pw2;

public:

	//★★★★★★★★★★★★★ 미션 4 : 생성자 ★★★★★★★★★★★★★
	AccountBook_Start();
	void Menu_Display();
	int Menu_Select();
	void Account_Register(int &account, int IOnum);
	bool Underflow_Money(int &account, int &month, int &day);
	void UseWay_Check(int select);
	void show();
	void setID();
	void setPasswd();
	void System_exit();
	//★★★★★★★★★★★★★ 미션 4 : 소멸자 ★★★★★★★★★★★★★
	~AccountBook_Start();
};

void Dinamic();
void Data_Reading();
void Data_UseReading();
void Dinamin_Clear();
void File_store(int month, int day);
void Performance(int n);

#endif