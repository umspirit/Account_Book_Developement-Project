#ifndef USER_INFO
#define USER_INFO

class User_Information { // 사용자의 정보를 등록하는 클래스

public:

	//★★★★★★★★★★★★★ 미션 4 : 생성자 ★★★★★★★★★★★★★
	User_Information();
	//★★★★★★★★★★★★★ 미션 6 : friend 함수 ★★★★★★★★★★★★★
	friend void AccountBook_Start::setID(); // ID를 설정하는 함수
	//★★★★★★★★★★★★★ 미션 6 : friend 함수 ★★★★★★★★★★★★★
	friend void AccountBook_Start::setPasswd(); // 비밀번호를 설정하는 함수
	//★★★★★★★★★★★★★ 미션 4 : 소멸자 ★★★★★★★★★★★★★
	~User_Information();
};

#endif // !USER_INFO