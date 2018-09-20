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

//�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
// �̼� 3 : Using_Show Ŭ���� ��ü������ -> �̼� 5 : ��ü�����͸� ��ü�������� ����
//�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�

int smoney	= 0;	 // ���� �ݾ׺��� ���� ���� ���� ��츦 �˻��ϱ� ���� ���� ����
int month	= 0;	 // ���� �����ϴ� ����
int day		= 0;	 // ���� �����ϴ� ����
int wstart	= 0;	 // ���� ���۰�
int wend	= 0;	 // ���� ���ᰪ
enum STAT status;	 // ������� ���¸� �����ϴ� ������ ����


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

void Dinamic() { // 2���� �迭 �����Ҵ��ϱ� ���ؼ� ����� �Լ�
	for (int i = 0; i < 13; i++) { 
		dayusing[i] = new DayUsing[32]; 
	}
}
	
void Data_Reading() {							//�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
	ifstream faccount("�����ͺ��̽�/����.txt");	//			�̼� 7 : file ����� �� ���Ͽ��� �� �о���� 
												//�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
	if (!faccount.is_open()) {
		cout << "�ܾ��� �ҷ��� �� �����ϴ�.";
	}
	else {
		while (!faccount.eof()) { // ����ڰ� ������ �ִ� �ܾ��� �ҷ��ɴϴ�.
			faccount >> *userinfo.account;
		}
		if (faccount.is_open() == true)
			faccount.close();	  // ������ ������ �ݽ��ϴ�.
	}
}

void Data_UseReading() {					//�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
											//			�̼� 7 : file ����� �� ���Ͽ��� �� �о����
	for (int i = 1; i <= 12; i++) {			//�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
		for (int j = 1; j <= 31; j++) {		// 1������ 12�������� �����͸� �о�Ŵϴ�.
			string strmon;		// �� ����
			string strdate;		// �� ����
			string fstring;		// �ؽ�Ʈ���ϰ�ΰ� ����˴ϴ�.

			strmon = to_string(i);
			strdate = to_string(j);
			fstring = "�����ͺ��̽�/������/" + strmon + "/" + strmon + "��" + strdate + "��.txt"; // �ؽ�Ʈ���� ���

			ifstream fusing(fstring);

			if (fusing.is_open() == false) { // ������ ���� ������ ���
				// �ʹ� ���� �߱� ������ ��¹� ����
			}
			else {
				while (!fusing.eof()) { // ������ ������ �����´�.
					fusing >> dayusing[i][j].inout[index[i][j]] >> dayusing[i][j].way[index[i][j]] >> dayusing[i][j].use[index[i][j]] >> dayusing[i][j].money[index[i][j]] >> dayusing[i][j].storetime[index[i][j]];
					index[i][j]++;
				}
				index[i][j]--; // ������ ���� ������ ���� �о�����µ� index�� 1���� ��Ŵ���μ� ������ ����
				if (fusing.is_open() == true)
					fusing.close();			 // ������ ���������� �ݴ´�.
			}
		}
	}
}

void Dinamin_Clear() { // �����Ҵ� �����ϴ� �Լ�

	//����ü User_Info �����Ҵ� ����
	delete userinfo.account;

	// DayUsing class 2���� �迭 �����Ҵ� ����
	for (int i = 0; i < 13; i++) { 
		delete []dayusing[i];
	}
	delete []dayusing;
	cout << "\n ���� �Ҵ��� ��� �����Ǿ����ϴ�. \n";
}

void File_store(int month, int day) {						

	string fstring;								//�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
	ofstream faccount("�����ͺ��̽�/����.txt");	//					�̼� 7 : file ����� �� ���Ͽ� ����
	faccount << *userinfo.account;				//�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
	faccount.close();

	if (status == START) { // ��� ������ ���� (����ΰ� ����� �� ����)
		for (int i = 1; i <= 12; i++) {		// 1������ 12�������� �����͸� ������ ���� ��� �����ϱ� ���� for��
			for (int j = 1; j <= 31; j++) {

				fstring = "�����ͺ��̽�/������/" + to_string(i) + "/" + to_string(i) + "��" + to_string(j) + "��.txt";

				if (index[i][j] > 0) { // ������ �ִ� ���ϸ� ����
					ofstream fusing(fstring);
					int findex = 0;
					while (findex < index[i][j]) {
						fusing << dayusing[i][j].inout[findex] << "\t" << dayusing[i][j].way[findex] << "\t" << dayusing[i][j].use[findex] << "\t" << dayusing[i][j].money[findex] << "\t" << dayusing[i][j].storetime[findex] << endl;
						findex++;
					}
					fusing.close();
				}
				else { // �ƹ� ���뵵 ��ϵ��� ���� ������ ����
					remove(fstring.c_str());
				}
			}
		}
		status = RUN;
	}
	else if (status == RUN) { // ������Ʈ�� �����͸� ����
		fstring = "�����ͺ��̽�/������/" + to_string(month) + "/" + to_string(month) + "��" + to_string(day) + "��.txt";
		if (index[month][day] > 0) {
			ofstream fusing(fstring);

			int findex = 0;
			while (findex < index[month][day]) {
				fusing << dayusing[month][day].inout[findex] << "\t" << dayusing[month][day].way[findex] << "\t" << dayusing[month][day].use[findex] << "\t" << dayusing[month][day].money[findex] << "\t" << dayusing[month][day].storetime[findex] << endl;
				findex++;
			}
			fusing.close();
		}
		else { // �ƹ� ���뵵 ��ϵ��� ���� ������ ����
			remove(fstring.c_str());
		}
	}
}

//�ڡڡڡڡڡڡڡڡڡڡڡڡ� �̼� 4 : ������ �ڡڡڡڡڡڡڡڡڡڡڡڡ�
AccountBook_Start::AccountBook_Start() {  // ����θ� ���۽�Ű�� ������
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

void AccountBook_Start::show() { // ó���������� �Լ� + ID / PW �� Ȯ���մϴ�.
	bool good = true;

	cout << "\t\t   �ڡڡڡڡڡڡڡڡ� ����� ���� ����� �ڡڡڡڡڡڡڡڡ�\n\n";
	cout << "\t\t\t �� ����� ���̵�� ��й�ȣ�� �Է����ּ���. \n\n";
	cout << "\t\t\t\t�� ID������: ";

	ifstream idpw("�����ͺ��̽�/IDPW.txt");

	idpw >> id >> id2 >> pw >> pw2;

	while (good) {
		setID();
		if (userinfo.name == id || userinfo.name == id2) {
			cout << "\t\t\t\t���̵� Ȯ�εǾ����ϴ�.";
			while (true) {
				cout << "\n\t\t\t\t�� PW������: ";
				setPasswd();
				if (userinfo.pw == pw || userinfo.pw == pw2) {
					good = false;
					system("cls");
					return;
				}
				else {
					cout << "\t\t\t\t��й�ȣ�� ��ġ���� �ʽ��ϴ�.\n";
				}
			}
		}
		else {
			cout << "\t\t\t���̵� ��ġ���� �ʽ��ϴ�.\n";
			cout << "\t\t\t �� ID������: ";
		}
	}
}

void AccountBook_Start::Menu_Display() { // �޴� �����ִ� �Լ�

	cout << "=====================================================================================================\n";
	cout << "\t\t\t�������� �̿��Ͻ� ���񽺸� �������ּ��� ��\n\n";
	cout << "\t\t\t         ��������. ������\n\n";
	cout << "\t\t\t         ��������. ���Ե��\n\n";
	cout << "\t\t\t         ��������. ��볻�� ��ȸ\n\n";
	cout << "\t\t\t         ��������. �Ⱓ�� ��뷮 ��ȸ\n\n";
	cout << "\t\t\t         ��������. �����ͼ���\n\n";
	cout << "\t\t\t��������������[0]. �������(����)\n";
	cout << "=====================================================================================================\n\n";
}

int AccountBook_Start::Menu_Select() { // �޴� ������ �� �ֵ��� �Է��� �ް� �� �޴��� ��������ش�.
	int num, tmp_month, tmp_day;

	do {
		cout << "\n\t\t\t������������   �� �Է� : ";
		num = error.Number_Check(ESELECT, "5"); // num�� ������ �� �ִ� ������ Ȯ��	
	} while (num < 0 || num > 5);

	switch (num) {
	case 1: // ���� ��� ��� ����
		Account_Register(*userinfo.account, num);
		break;
	case 2: // ���� ��� ��� ����
		Account_Register(*userinfo.account, num);
		break;
	case 3: // ��볻��Ȯ�� ��� ����
		// �ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
		//	 �̼� 11 : ��ӹ޴� class Ȱ�� Using_Show�� ��ӹ��� Class_Extends Ŭ���� ��ü classext�� ���Ǿ����ϴ�.
		// �ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
	{
		DayUsing tmpuse;
		classext.First_show();
		cout << "\n\t\t\t 1. ���ó�¥ Ȯ�� 2. �ٸ���¥ Ȯ�� 0. ������\n";
		cout << "\n\t\t\t������������   �� �Է� : ";
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
		//�ڡڡڡڡڡڡڡڡ� �̼� 3 : ��ü �Ű����� ���� �ڡڡڡڡڡڡڡڡ�
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
		num = datamf.Menu_Show(); // ������ ���� ��� ����
		if (num != 0) {
			tmp_month = datamf.Month_Input();
			tmp_day = datamf.Day_Input();

			//�ڡڡڡڡڡڡڡڡ� �̼� 3 : ��ü �Ű����� ���� �ڡڡڡڡڡڡڡڡ�
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
	case 0: // �ý��� ���� ��� ����
		status = START;
		File_store(month, day);
		Dinamin_Clear();
		Performance(20);
		System_exit();
		break;
	}
	return num;
}

void AccountBook_Start::Account_Register(int &account, int IOnum) { // ������ �Է����ִ� �Լ�
	string str;

	cout << "\n\t\t\t ��. ���� ��¥\t ��. �ٸ� ��¥\t [0]. ������\n\n";
	cout << "\t\t\t\t�� �Է� : ";
	aselect = error.Number_Check(ESELECT, "2"); // �Է°����� ������ Ȯ���ϰ� ����
	
	switch (aselect) {
	case 1: // ���� ��¥�� ����θ� ����� ��
		month = timecom.getMonth(); // ���� ��¥�� ������ ����
		day = timecom.getDay();
		break;
	case 2: // �ٸ� ��¥�� ����θ� ����� ��
		do {
			cout << "\n\t\t\t���� ��(��) �� �Է����ּ��� : ";
			month = error.Number_Check(EDATE, "12"); // �Է°����� ������ Ȯ���ϰ� ����
		} while (month < 1 || month > 12);

		do {
			cout << "\n\t\t\t���� ��(��) �� �Է����ּ��� : ";
			day = error.Number_Check(EDATE, "31"); // �Է°����� ������ Ȯ���ϰ� ����
		} while (day < 1 || day > 31);

		break;
	case 0: // �ߴ��ϰ� ������
		system("cls");
		return;
		break;
	}
	system("cls");

	while (true) {
		cout << "\n\t\t\t���� ���ҹ���� �������ּ���\n\n";
		cout << "\t\t\t    ��. ����   ��. ī��  [0]. ������ -> ";

		aselect = error.Number_Check(ESELECT, "2"); // �Է°����� ������ Ȯ�� �� ����
		system("cls");

		if (aselect != 0) { // 3�� �����⸦ ������ ��� ������ϰ� �Լ�����

			if (IOnum == 1)		 // 1 == �����϶�
				cout << "\n\t\t\t���� ���⳻���� �Է����ּ��� : ";
			else if (IOnum == 2) // 2 == �����϶�
				cout << "\n\t\t\t���� ���Գ����� �Է����ּ��� : ";

			cin >> dayusing[month][day].use[index[month][day]];

			if (IOnum == 1)		 // 1 == �����϶�
				cout << "\n\t\t\t���� ����ݾ��� �Է����ּ��� : ";
			else if (IOnum == 2) // 2 == �����϶�
				cout << "\n\t\t\t���� ���Աݾ��� �Է����ּ��� : ";
			dayusing[month][day].money[index[month][day]] = error.Number_Check(EMONEY, "");

			UseWay_Check(aselect);

			cout << "\n\t   =========================================================================";
			if (IOnum == 1) {		// �������� �� ��
				if (Underflow_Money(account, month, day)) { // ����ݾ��� ��밡�ɾ׺��� ������ if�� ���� ����
					dayusing[month][day].inout[index[month][day]] = "����";
					account -= dayusing[month][day].money[index[month][day]];
					dayusing[month][day].storetime[index[month][day]] = timecom.ReturnString(str);
					cout << "\n\t\t\t   " << dayusing[month][day].money[index[month][day]] << " ���� ����Ǿ�, ��밡�ɾ��� " << account << " ���Դϴ�.\n";
					index[month][day]++;
				}
			}
			else if (IOnum == 2) { // ���Ե���� �� ��
				dayusing[month][day].inout[index[month][day]] = "����";
				account += dayusing[month][day].money[index[month][day]];
				dayusing[month][day].storetime[index[month][day]] = timecom.ReturnString(str);
				cout << "\n\t\t\t   " << dayusing[month][day].money[index[month][day]] << " ���� �ԱݵǾ�, ��밡�ɾ��� " << account << " ���Դϴ�.\n";
				index[month][day]++;
			}
			cout << "\t   =========================================================================\n";
			File_store(month, day);
		}
		else {// �Է��� �׸��ϰ� ���� ��
			system("cls");
			return;
		}
	}
}

bool AccountBook_Start::Underflow_Money(int &account, int &month, int &day) { // ��밡�ɱݾ׺��� ����ݾ��� Ŭ ��츦 ����� �Լ�

	if (account - dayusing[month][day].money[index[month][day]] < 0) { // ��밡�ɾ� - ����ݾ� > 0 �� false�� return
		cout << smoney << "\t\t\t ! ����ݾ��� ��밡�� �ݾ׺��� Ů�ϴ�. !\n";
		dayusing[month][day].use[index[month][day]] = "";
		dayusing[month][day].money[index[month][day]] = 0;

		return false;
	}
	return true;
}

void AccountBook_Start::UseWay_Check(int select) { // �������� ī������ ����

	if (select == 1) {// �������� ����� ��
		dayusing[month][day].way[index[month][day]] = "����";
	}
	else if (select == 2) { // ī��� ����� ��
		dayusing[month][day].way[index[month][day]] = "ī��";
	}
}

void AccountBook_Start::System_exit() { // ����� �ý��� ���� �Լ�
	exit(0); // ����
}

//�ڡڡڡڡڡڡڡڡڡڡڡڡ� �̼� 4 : �Ҹ��� �ڡڡڡڡڡڡڡڡڡڡڡڡ�
AccountBook_Start::~AccountBook_Start() {
	cout << "��ü�� �Ҹ�Ǿ����ϴ�.";
};

void AccountBook_Start::setID() { // �̸� ������ �����ϴ� �Լ�
	cin >> userinfo.name;
}

void AccountBook_Start::setPasswd() { // ��� ���ɾ��� �����ϴ� �Լ�
	cin >> userinfo.pw;
}