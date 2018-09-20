#include "myclass.h"
#include "Using_Show.h"
#include "Error_Check.h"

Error_Check err_Using;


//�ڡڡڡڡڡڡڡڡڡڡڡڡ� �̼� 4 : ������ �ڡڡڡڡڡڡڡڡڡڡڡڡ�
Using_Show::Using_Show() {
	cout << "Using_Show ��ü�� �����Ǿ����ϴ�.\n";
} 

void Using_Show::SetMon(int dmon) {
	mon = dmon;
}

void Using_Show::SetDay(int dday) {
	date = dday;
}

//�ڡڡڡڡڡڡڡڡڡڡڡڡ� �̼� 3 : ��ü �Ű����� ���� �ڡڡڡڡڡڡڡڡڡڡڡڡ�
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

void Using_Show::First_show() { // �ܼ�â�� ����� �Ѵ�.

	cout << "\t\t\t    =======================================\n";
	cout << "\t\t\t     ����������볻�� Ȯ�� �޴��Դϴ١������� \n";
	cout << "\t\t\t    =======================================\n\n";
}
/*�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
�̼� 3 ��ü �Ű����� ����
*///�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�

int Using_Show::Month_Input() { // ���� �Է¹޴� �Լ�

	do {
		cout << "\t\t\t\t���� ��(��) �� �Է����ּ��� : ";
		mon = err_Using.Number_Check(EDATE, ""); // �Է°����� ������ Ȯ���ϰ� ����
	} while (mon < 1 || mon > 12);
	
	return mon;
}

int Using_Show::Day_Input() { // ���� �Է¹޴� �Լ�

	do {
		cout << "\n\t\t\t\t���� ��(��) �� �Է����ּ��� : ";
		date = err_Using.Number_Check(EDATE, "");
	} while (date < 1 || date > 31);

	return date;
}

//�ڡڡڡڡڡڡڡڡڡڡڡڡ� �̼� 3 : ��ü �Ű����� ���� �ڡڡڡڡڡڡڡڡڡڡڡڡ�
void Using_Show::Second_show(Using_Show &us, DayUsing &dayuse, int &uindex, int &account) { // ��볻�� �����ִ� �Լ�

	int total_out = 0;
	int total_in  = 0;
	string tmpstr, tapstring = "";
	int tmpint;

	system("cls");
	cout << "\n\t\t\t\t\t< " << us.mon << "��  " << us.date << "�� ��볻�� >\n\n";

	cout << "\t��ȣ\t�Ա�&���\t���\t\t����\t\t�ݾ�\t\t��Ͻð�" << endl;
	cout << "-----------------------------------------------------------------------------------------------------" << endl;

	//�ڡڡڡڡڡڡڡڡڡڡڡڡ� �̼� 3 : ��ü �Ű����� ���� �ڡڡڡڡڡڡڡڡڡڡڡڡ�
	String_sort(dayuse, uindex, tapstring);

	for (int i = 0; i < uindex; i++) { // for���� �̿��ؼ� �迭�� �ִ� ���� ��� ���
		if (dayuse.money[i] < 10000)
			tmpstr = "��";
		else
			tmpstr = "";

		if (dayuse.inout[i] == "����") {
			cout << "\t" << i+1 << " )\t" << dayuse.inout[i] << "\t\t<" << dayuse.way[i] << ">\t\t" << dayuse.use[i] << tapstring << "\t- " << dayuse.money[i] << "��" << tmpstr << "\t" << dayuse.storetime[i] << endl;
			total_out += dayuse.money[i];
		}
		else {
			cout << "\t" << i+1 << " )\t" << dayuse.inout[i] << "\t\t<" << dayuse.way[i] << ">\t\t" << dayuse.use[i] << tapstring << "\t+ " << dayuse.money[i] << "��" << tmpstr << "\t" << dayuse.storetime[i] << endl;
			total_in += dayuse.money[i];
		}
	}
	cout << " \n\t\t\t\t�� �� ����ݾ� : " << total_out << " ��";
	cout << " \n\t\t\t\t�� �� ���Աݾ� : " << total_in << " �� " << endl;
	cout << " \n\t\t\t\t�� ���� ��밡�ɱݾ� : " << account << " ��\n\n";
}

//�ڡڡڡڡڡڡڡڡڡڡڡڡ� �̼� 4 : �Ҹ��� �ڡڡڡڡڡڡڡڡڡڡڡڡ�
Using_Show::~Using_Show() {
	// �����ǰ� �Ҹ�Ǵ� �κ��� ���� ������ �ƹ��͵� ���� �ʾҽ��ϴ�.
}