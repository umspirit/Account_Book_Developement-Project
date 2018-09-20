#ifndef TIME_COMPUTE
#define TIME_COMPUTE

class Time_Compute {
	time_t the_time;
	struct tm *p_time;

public:

	//≮≮≮≮≮≮≮≮≮≮≮≮≮ 固记 4 : 积己磊 ≮≮≮≮≮≮≮≮≮≮≮≮≮
	Time_Compute();
	void SetTime();
	void SetPtime();
	int getMonth();
	int getDay();
	string ReturnString(string &daystr);
	//≮≮≮≮≮≮≮≮≮≮≮≮≮ 固记 4 : 家戈磊 ≮≮≮≮≮≮≮≮≮≮≮≮≮
	~Time_Compute();
};

#endif // !TIME_COMPUTE