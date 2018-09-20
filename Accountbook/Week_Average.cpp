#include "myclass.h"
#include "Week_Average.h"
#include "Error_Check.h"

Error_Check err_Average;


//�ڡڡڡڡڡڡڡڡڡڡڡڡ� �̼� 4 : ������ �ڡڡڡڡڡڡڡڡڡڡڡڡ�
Week_Average::Week_Average() { 
	cout << "Week_Average ��ü�� �����Ǿ����ϴ�.\n";
	wmonth = 0;
	wweek = 0;
	wselect = 0;
	total_in = 0;
	total_out = 0;
	year_total = 0;
	sum = 0;
	mon = 0;
}

void Week_Average::Manual_Show() { // �޴��� �����ִ� �Լ�

	system("cls");
	cout << "=====================================================================================================\n";
	cout << "\t\t\t����         �Ⱓ�� ��뷮 ��ȸ �޴��Դϴ١�������\n";
	cout << "=====================================================================================================\n\n";
	cout << "\t\t\t�� �޴��� �������ּ���\n\n";
	cout << "\t\t\t ��. �ְ� ���  ��.�� �� ���  ��.���� ���  [0].������\n";
	
	do {
		cout << "\n\t\t\t �� �Է� : ";
		wselect = err_Average.Number_Check(ESELECT, "3");
	} while (wselect < 0 || wselect > 3);

	mon = 1;
	total_in = 0;
	total_out = 0;
}

void Week_Average::Month_Input(int &tmp_month) { // ���� �Է¹޴� �Լ�

	do {
		cout << "\n\t\t\t �� ��(��)�� �Է����ּ��� : ";
		wmonth = err_Average.Number_Check(EDATE, "12");
	} while (wmonth < 1 || wmonth > 12);

	tmp_month = wmonth;
}

int Week_Average::Mneu_Select(int &start, int &end, int &tmp_month) { // �޴��� ���� �Լ�

	switch (wselect) {
	case 1:
		Month_Input(tmp_month); // �� �Է�
		Week_Input(start, end); // �� �Է�
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

void Week_Average::Week_Input(int &start, int &end) { // �ָ� �Է¹޴� �Լ�

	cout << "\n=====================================================================================================\n";
	cout << "\t\t\t        ��ȸ�ϰ� ���� ������ �������ּ���\n";
	cout << "=====================================================================================================\n";
	cout << "\t\t\t                ��. 1���� (1 ~ 8)\n";
	cout << "\t\t\t                ��. 2���� (9 ~ 16)\n";
	cout << "\t\t\t                ��. 3���� (17 ~ 24)\n";
	cout << "\t\t\t                ��. 4���� (25 ~ 31)\n";
	cout << "\t\t\t               [0]. �� �� ��\n";

	do {
		cout << "\n\t\t                �� �Է� : ";
		wweek = err_Average.Number_Check(ESELECT, "4"); // �Է¹��� ���ڰ� �ùٸ��� Ȯ��		
	} while (wweek < 0 || wweek > 4);
}

// ���� ���Ȯ��, �� �� ���, ���� ��뷮�� ����ϴ� �Լ�
//�ڡڡڡڡڡڡڡڡڡڡڡڡ� �̼� 3 : ��ü �Ű����� ���� �ڡڡڡڡڡڡڡڡڡڡڡڡ�
void Week_Average::Calculate(int week_start, int week_end, int dindex, DayUsing dayuse, int month) { 
	
	switch (wselect) {
	case 1:
		for (int j = 0; j < dindex; j++) {
			if (dayuse.inout[j] == "����")
				total_out += dayuse.money[j];
			else if (dayuse.inout[j] == "����")
				total_in += dayuse.money[j];
		}
		break;
	case 2:
		for (int j = 0; j < dindex; j++) {
			if (dayuse.inout[j] == "����")
				total_out += dayuse.money[j];
			else if (dayuse.inout[j] == "����")
				total_in += dayuse.money[j];
		}
		break;
	case 3:
		for (int i = 0; i < dindex; i++) {
			if (dayuse.inout[i] == "����") {
				total_out += dayuse.money[i];
			}
		}
		if (month == 12 && week_start == week_end)
			year_total += int(total_out);

		break;
	}
}

// �� ��뷮�� ����ϴ� �Լ�
//�ڡڡڡڡڡڡڡڡڡڡڡڡ� �̼� 3 : ��ü �Ű����� ���� �ڡڡڡڡڡڡڡڡڡڡڡڡ�
void Week_Average::Go(int week_start, int week_end, int dindex, DayUsing dayuse, int month) {
	
	total_in = 0;
	for (int i = 0; i < dindex; i++) {
		if (dayuse.inout[i] == "����") {
			total_in += dayuse.money[i];
		}
	}
	cout << "\n �� ��뷮(%) : ";
}

// ��, ��, �⿡ ���� ����� ���� ����ϴ� �Լ�
//�ڡڡڡڡڡڡڡڡڡڡڡڡ� �̼� 3 : ��ü �Ű����� ���� �ڡڡڡڡڡڡڡڡڡڡڡڡ�
void Week_Average::Total_Print(int week_start, int week_end, int dindex, DayUsing dayuse, int month) {

	switch (wselect) {
	case 1:
		sum = 0;
		for (int j = 0; j < dindex; j++) {
			if (dayuse.inout[j] == "����")
				sum += dayuse.money[j];
		}
		cout << "\n\t\t\t" << wmonth << " �� " << week_start << " �� ��뷮(%) :\t" << roundf((sum * 100) / total_out) << " %\t ����� :\t" << sum << " ��";

		if (week_start == week_end) {
			cout << "\n\n\t\t\t\t�� " << wweek << "���� �� ���� : " << total_out << " ��\t>";
			cout << "\n\t\t\t\t�� " << wweek << "���� �� ���� : " << total_in << " ��\t>\n";
			sum = 0;
		}

		break;
	case 2:
		if (week_start == 1) {
			cout << "\n\n\t\t\t\t\t < " << wmonth << " �� ������ >\n";
			cout << "=====================================================================================================\n";
		}

		if (week_start <= 8) {
			for (int i = 0; i < dindex; i++) {
				if (dayuse.inout[i] == "����")
					sum += dayuse.money[i];
			}
			if (week_start == 8) {
				cout << "\n\n\t\t\t\t    - 1����( 1- 8) ��뷮(%) : " << roundf((sum * 100) / total_out) << " %";
				sum = 0;
			}
		}
		else if (week_start > 8 && week_start <= 16) {
			for (int i = 0; i < dindex; i++) {
				if (dayuse.inout[i] == "����")
					sum += dayuse.money[i];
			}
			if (week_start == 16) {
				cout << "\n\n\t\t\t\t    - 2����( 9-16) ��뷮(%) : " << roundf((sum * 100) / total_out) << " %";
				sum = 0;
			}
		}
		else if (week_start > 16 && week_start <= 24) {
			for (int i = 0; i < dindex; i++) {
				if (dayuse.inout[i] == "����")
					sum += dayuse.money[i];
			}
			if (week_start == 24) {
				cout << "\n\n\t\t\t\t    - 3����(17-24) ��뷮(%) : " << roundf((sum * 100) / total_out) << " %";
				sum = 0;
			}
		}
		else if (week_start > 24 && week_start <= 31) {
			for (int i = 0; i < dindex; i++) {
				if (dayuse.inout[i] == "����")
					sum += dayuse.money[i];
			}
			if (week_start == 31) {
				cout << "\n\n\t\t\t\t    - 4����(25-31) ��뷮(%) : " << roundf((sum * 100) / total_out) << " %";
				sum = 0;
			}
		}

		if (week_start == week_end) {
			cout << "\n\n\t\t\t\t   �� " << wmonth << "��(��) �� ���� : " << total_out << " ��";
			cout << "\n\t\t\t\t   �� " << wmonth << "��(��) �� ���� : " << total_in << " ��\n";
			sum = 0;
		}

		break;
	case 3:
		if (month == 1 && week_start == 1) {
			total_out = 0;
			cout << "=====================================================================================================\n";
		}

		for (int j = 0; j < dindex; j++) {
			if (dayuse.inout[j] == "����")
				total_out += dayuse.money[j];
		}

		if (week_start == week_end) {
			if(month % 2 == 1)
				cout << "\t\t\t" << month << " �� ��� :\t" << roundf((total_out * 100) / year_total) << " %\t";
			else
				cout << "\t" << month << " �� ��� :\t" << roundf((total_out * 100) / year_total) << " %\n";
		}

		if (month == 12 && week_start == week_end) {
			cout << "\n\t\t\t-----------------------------------------------------";
			cout << "\n\t\t\t\t   �� 1�� �� ��뷮 : " << year_total << " ��" << endl;
			year_total = 0;
		}

		if (month > mon) {
			mon++;
			total_out = 0;
		}

		break;
	}
}

//�ڡڡڡڡڡڡڡڡڡڡڡڡ� �̼� 4 : �Ҹ��� �ڡڡڡڡڡڡڡڡڡڡڡڡ�
Week_Average::~Week_Average() {
	cout << "Week_Average ��ü�� �Ҹ�Ǿ����ϴ�.\n";
}