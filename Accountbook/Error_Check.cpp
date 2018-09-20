#include "myclass.h"
#include "Error_Check.h"


//�ڡڡڡڡڡڡڡڡڡڡڡڡ� �̼� 4 : �Ҹ��� �ڡڡڡڡڡڡڡڡڡڡڡڡ�
Error_Check::Error_Check() { 
	cout << "Error_Check ��ü�� �����Ǿ����ϴ�.\n";
}

bool Error_Check::Function_Select(int select, string endnum, string str) { // select ���� �´� �Լ��� �����Ű�� �Լ�

	switch (select) { // �´� ���� ������ üũ�� �ϰ� �Ǵµ�, ��ɺ��� �Լ��� ȣ���մϴ�.
	case 1:
		return Money_isDigit(str, endnum); // ���� ����� ���ڷ� �Է��ߴ��� �˻�
	case 2:
		return Date_Digit(str); // ��¥�� ��, �Ͽ� �°� ����� �Է��ߴ��� �˻�
	case 3:
		return Select_Digit(str, endnum); // �� ���� ��� �͵��� ����� �Է���� �˻�
	}
}

bool Error_Check::Money_isDigit(string str, string endnum) { // �Էµ� ���� ���� �ùٸ��� Ȯ���ϴ� �Լ�

	for (unsigned int i = 0; i < str.length() && i < endnum.length() ; i++) { // string�� ������ �ڸ����� �˻��մϴ�
		if (str.at(i) < '0' || str.at(i) > '9') {							  // // ���ڸ� �Է��� ���� �˻��մϴ�.
			cout << "\n\t\t\t���� ���ڸ����� �Է����ּ��� : ";
			return false;
		}
	}
	return true;
}

bool Error_Check::Date_Digit(string str) { // ��¥�Է��� �ùٸ��� Ȯ���ϴ� �Լ�

	for (unsigned int i = 0; i < str.length(); i++) { // string�� ������ �ڸ����� �˻��մϴ�
		if (str.at(i) < '0' || str.at(i) > '9') {	  // // ���ڸ� �Է��� ���� �˻��մϴ�.
			cout << "\n\t\t\t���� ��, �Ͽ� �°� ���ڸ� �Է����ּ��� : ";
			return false;
		}
	}
	return true;
}

bool Error_Check::Select_Digit(string str, string endnum) { // �� ���� ������ ������ �ùٸ��� Ȯ���ϴ� �Լ�

	for (unsigned int i = 0; i < str.length() && i < endnum.length(); i++) { // string�� ������ �ڸ����� �˻��մϴ�
		if (str.at(i) < '0' || str.at(i) > endnum.at(i)) {					 // ���ڸ� �Է��� ���� �˻��մϴ�.
			cout << "\n\t\t\t���� 0 ~ " << endnum << "���� �Է����ּ��� : ";
			return false;
		}
	}
	if (str.length() == endnum.length()) // �°� �Է��� ���
		return true;
	else { // �߸��� ���� ���� �Է����� ��� ����� �ɴϴ�.
		cout << "\n\t\t\t���� 0 ~ " << endnum << "���� �Է����ּ��� : ";
		return false;
	}
}

int Error_Check::Number_Check(int n, string endnum) { // ���ڸ� üũ�ϴ� �Լ� 
													  // ��� ���ڸ� üũ�ϴ� �Լ����� ����� ó���� �����ϰ� �˴ϴ�.
	string str; 
	bool check = true;

	while (true) {
		cin >> str;							  // �Է��� ���� �������� �ƴ��� �˻��ϱ� ���ؼ� string���� �Է¹޽��ϴ�.
		if (Function_Select(n, endnum, str))  // ���ڸ�
			break;
	}
	return atoi(str.c_str());
}

bool Error_Check::Modify_Digit(string str, string endnum) { // Data_Modify �Լ����� �Էµ� ���� Ȯ���ϱ� ���� �Լ�
															// Data_Modify �Լ������� ' * '�Է��� �ޱ����ؼ� ��������ϴ�.
	if (!strcmp(str.c_str(), "*")) {						// *�� ��
		return true;
	}
	else {
		for (unsigned int i = 0; i < str.length() && i < endnum.length(); i++) {
			if (str.at(i) < '0' || str.at(i) > endnum.at(i)) {
				cout << "\n\t\t\t���� 0 ~ " << endnum << "���� �Է����ּ��� : ";
				return false;
			}
		}
		if (str.length() == endnum.length())
			return true;
		else {
			cout << "\n\t\t\t���� 0 ~ " << endnum << "���� �Է����ּ��� : ";
			return false;
		}
	}
}

string Error_Check::Modify_Check(string endnum) { // Data_Modify �Լ����� �Էµ� ���� Ȯ���ϱ� ���� �Լ�
												  // Data_Modify �Լ������� ' * '�Է��� �ޱ����ؼ� ��������ϴ�.
	string str;
	bool check = true;

	while (true) {
		cin >> str;
		if (Modify_Digit(str, endnum))  // ���ڸ�
			break;
	}
	return str;
}

//�ڡڡڡڡڡڡڡڡڡڡڡڡ� �̼� 4 : �Ҹ��� �ڡڡڡڡڡڡڡڡڡڡڡڡ�
Error_Check::~Error_Check() {
	cout << "Error_Check ��ü�� �Ҹ�Ǿ����ϴ�.\n";
}