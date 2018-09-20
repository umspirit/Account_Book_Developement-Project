#ifndef CLASS_EXTENDS
#define CLASS_EXTENDS


// ★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★
//			미션 11 : Class_Extends 클래스가 Using_Show클래스를 상속받았습니다.
// ★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★
class Class_Extends : public Using_Show { // 입력된 정보를 수정하는 class

	int mon;
	int date;
public:
	//★★★★★★★★★★★★★ 미션 4 : 생성자 ★★★★★★★★★★★★★
	Class_Extends();
	//★★★★★★★★★★★★★ 미션 4 : 소멸자 ★★★★★★★★★★★★★
	~Class_Extends();
};

#endif // ㄴ