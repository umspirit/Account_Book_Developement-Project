#ifndef MY_CLASS
#define MY_CLASS

#include <iostream>
#include <Windows.h>
#include <string> // string�� ���� ���ؼ� string �� include 
#include <fstream>
#include <math.h>
#include <time.h>

using namespace std;
// ���� �Է¹޴� ����

extern int	smoney; // ���� �Է¹޴� ����
extern int	month; // ���� �Է¹޴� ����
extern int	day;   // ���� �Է¹޴� ����
static int	index[13][32];
enum STAT { START, RUN };
enum ERRNAME {EMONEY = 1, EDATE, ESELECT, EMODIFY};

static struct User_Info { // ������ �̸��� ��밡�� �ݾ��� �����ϱ� ���� ����
											     //�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
	char *name    = new char[20]; // ���̵�               �̼� 9 : string�� char* �� �ٲٱ�
	char *pw	  = new char[20];   // ��й�ȣ   //�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
	int  *account = new int; // ��밡�ɱݾ��� �����ϴ� ����
}userinfo;

static class DayUsing { // �Ϸ� ��볻��

public:
	string *use			= new string[40]; // ����
	string *inout		= new string[40]; // �����
	string *way			= new string[40]; // ���� or ����
	int    *money		= new int[40];	  // ����
	string *storetime	= new string[40]; // ��Ͻð�

}**dayusing = new DayUsing*[13];  // 365���� ��볻���� ���ݾ��� ������ �� �ֵ��� ����


class AccountBook_Start { // ����� ���� Ŭ����
	int aselect;
	string id, id2, pw, pw2;

public:

	//�ڡڡڡڡڡڡڡڡڡڡڡڡ� �̼� 4 : ������ �ڡڡڡڡڡڡڡڡڡڡڡڡ�
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
	//�ڡڡڡڡڡڡڡڡڡڡڡڡ� �̼� 4 : �Ҹ��� �ڡڡڡڡڡڡڡڡڡڡڡڡ�
	~AccountBook_Start();
};

void Dinamic();
void Data_Reading();
void Data_UseReading();
void Dinamin_Clear();
void File_store(int month, int day);
void Performance(int n);

#endif