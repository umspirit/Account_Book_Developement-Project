#ifndef TIME_COMPUTE
#define TIME_COMPUTE

class Time_Compute {
	time_t the_time;
	struct tm *p_time;

public:

	//�ڡڡڡڡڡڡڡڡڡڡڡڡ� �̼� 4 : ������ �ڡڡڡڡڡڡڡڡڡڡڡڡ�
	Time_Compute();
	void SetTime();
	void SetPtime();
	int getMonth();
	int getDay();
	string ReturnString(string &daystr);
	//�ڡڡڡڡڡڡڡڡڡڡڡڡ� �̼� 4 : �Ҹ��� �ڡڡڡڡڡڡڡڡڡڡڡڡ�
	~Time_Compute();
};

#endif // !TIME_COMPUTE