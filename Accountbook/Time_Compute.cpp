#include "myclass.h"
#include "Time_Compute.h"


//�ڡڡڡڡڡڡڡڡڡڡڡڡ� �̼� 4 : ������ �ڡڡڡڡڡڡڡڡڡڡڡڡ�
Time_Compute::Time_Compute() { 
	cout << "Time_Compute ��ü�� �����Ǿ����ϴ�.\n";
	SetPtime();
}

void Time_Compute::SetTime() { // �ð��� ������Ʈ�ϴ� �Լ�(�ʱ�ȭ)
	time(&the_time);
	SetPtime();
}

void Time_Compute::SetPtime() { // �ð��� tm����ü�� �ٽ� �ִ� �Լ�
	p_time = localtime(&the_time);
}

int Time_Compute::getMonth() { // ���� ��ȯ�ϴ� �Լ�
	return p_time->tm_mon + 1;
}

int Time_Compute::getDay() { // ���� ��ȯ�ϴ� �Լ�
	return p_time->tm_mday;
}

string Time_Compute::ReturnString(string &daystr) { // ���������� �ð��� ������ ���ڿ��� ��ȯ�ϴ� �Լ�
	char timestr[20];								   // �� ���忡 ���̴� ���ڿ��� ��ȯ

	SetTime(); // �ð� ������Ʈ
	strftime(timestr, sizeof(timestr), "%Y/%m/%d-%H:%M", p_time);
	daystr = timestr;

	return daystr;
}

//�ڡڡڡڡڡڡڡڡڡڡڡڡ� �̼� 4 : �Ҹ��� �ڡڡڡڡڡڡڡڡڡڡڡڡ�
Time_Compute::~Time_Compute() {
	cout << "Time_Compute ��ü�� �Ҹ�Ǿ����ϴ�.\n";
}