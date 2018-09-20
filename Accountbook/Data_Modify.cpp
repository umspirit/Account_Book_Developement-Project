#include "myclass.h"
#include "Data_Modify.h"
#include "Error_Check.h"


Error_Check err_Modify;

//�ڡڡڡڡڡڡڡڡڡڡڡڡ� �̼� 4 : ������ �ڡڡڡڡڡڡڡڡڡڡڡڡ�
Data_Modify::Data_Modify() { // ������
	cout << "Data_Modify ��ü�� �����Ǿ����ϴ�.\n";
}

int Data_Modify::Menu_Show() { // �޴��� �����ִ� �Լ���
	system("cls");
	cout << "\t\t\t\t�١١١١١١١١١١١١١١١١١١١١�\n\n";
	cout << "\t\t\t\t���������� ����γ��� ���� �޴�\n\n";
	cout << "\t\t\t\t�١١١١١١١١١١١١١١١١١١١١�\n\n";
	cout << "\t\t\t\t��. ������ ������[0]. ������\n\n";

	cout << "\n\t\t\t\t���� �Է� : ";
	dselect = err_Modify.Number_Check(ESELECT, "1");

	return dselect;
}
//�ڡڡڡڡڡڡڡڡ� �̼� 3 : ��ü �Ű����� ���� �ڡڡڡڡڡڡڡڡ�
void Data_Modify::Menu_Select(STAT &status, int &dindex, int &account, DayUsing &dayuse) {
	switch (dselect) {
	case 1:
		//�ڡڡڡڡڡڡڡڡ� �̼� 3 : ��ü �Ű����� ���� �ڡڡڡڡڡڡڡڡ�
		Delete_Menu(status, dindex, account, dayuse); // ���� ��� �Լ� ����
		break;
	case 0:
		break;
	}
}

int Data_Modify::Month_Input() {

	do {
		cout << "\n\t\t\t\t���� ��(��) �� �Է����ּ��� : ";
		dmonth = err_Modify.Number_Check(EDATE, "");
	} while (dmonth < 1 || dmonth > 12);

	return dmonth;
}

int Data_Modify::Day_Input() {

	do {
		cout << "\n\t\t\t\t���� ��(��) �� �Է����ּ��� : ";
		dday = err_Modify.Number_Check(EDATE, "");
	} while (dday < 1 || dday > 31);

	return dday;
}

//�ڡڡڡڡڡڡڡڡ� �̼� 3 : ��ü �Ű����� ���� �ڡڡڡڡڡڡڡڡ�
bool Data_Modify::Select_Show(int &dindex, DayUsing &dayuse) { // ��, ���� �Է��ϰ�, �װ��� ���� ����� �ڷḦ �����ؼ� �����ش�.

	cout << "\n\n\t\t\t\t\t<��" << dmonth << " ����" << dday << " �ϡ�>\n\n";

	if (dindex == 0) { // �����Ͱ� �������� ���� ��
		cout << "\t\t\t\t !!!! �����Ͱ� �������� �ʽ��ϴ� !!!!\n";
		return false;
	}
	else { // �ڷ���� �����ؼ� �����ݴϴ�.
		for (int i = 0; i < dindex; i++) {
			cout << "\t\t\t\t" << i + 1 << ")\t<" << dayuse.way[i] << ">  " << dayuse.inout[i] << "���� : " << dayuse.use[i];
			if (dayuse.inout[i] == "����")
				cout << "  \t�ݾ� : - " << dayuse.money[i] << "��\n";
			else
				cout << "  \t�ݾ� : + " << dayuse.money[i] << "��\n";
		}
		return true;
	}
}
//�ڡڡڡڡڡڡڡڡ� �̼� 3 : ��ü �Ű����� ���� �ڡڡڡڡڡڡڡڡ�
void Data_Modify::Delete_Menu(STAT &status, int &dindex, int &account, DayUsing &dayuse) { // �ڷḦ �����ϴ� �Լ�

	while (true) {
		if (dindex == 0) {
			return;
		}

		cout << "\n\t\t\t\t  ! [0]�� ������ / [*] : ��� �׸� ���� !\n";
		cout << "\n\t\t\t\t�����������Ͻ� �׸��� �������ּ��� : ";
		string tmp;
		tmp = err_Modify.Modify_Check(to_string(dindex));
		dselect = atoi(tmp.c_str());

		if (!strcmp(tmp.c_str(), "*")) { // O�� O�� �� �ִ� �����͸� ��� �����ϴ� ���
			for (int i = dindex - 1; i >= 0; i--) {
				if (dayuse.inout[i] == "����")
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
		else if (dselect != 0) { // O�� O�� �� �ִ� Ư�� �����͸� �����ϴ� ���
			if (dayuse.inout[dselect] == "����")
				account += dayuse.money[dselect - 1];
			else
				account -= dayuse.money[dselect - 1];

			for (int i = dselect - 1; i + 1 <= dindex; i++) { // ������ ������ ���� �ڷḦ ���ܼ� ����
				dayuse.use[i] = dayuse.use[i + 1];
				dayuse.way[i] = dayuse.way[i + 1];
				dayuse.money[i] = dayuse.money[i + 1];
				dayuse.inout[i] = dayuse.inout[i + 1];
				dayuse.storetime[i] = dayuse.storetime[i + 1];
			}
			dindex--; // 1���� ���������� �ڷᰳ�� 1 ����
			Select_Show(dindex, dayuse); // �߰����� ������ ���� �Լ�ȣ��
		}
		else if (dselect == 0) { // ���� ��� ���� -> �޴� ����
			system("cls");
			return;
		}
		File_store(dmonth, dday); // ������ O�� O���� ���Ͽ� �ڷ� ������Ʈ
	}
}

//�ڡڡڡڡڡڡڡڡڡڡڡڡ� �̼� 4 : �Ҹ��� �ڡڡڡڡڡڡڡڡڡڡڡڡ�
Data_Modify::~Data_Modify() {
	cout << "Data_Modify ��ü�� �Ҹ�Ǿ����ϴ�.\n";
}