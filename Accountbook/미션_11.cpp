/*
�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�


�̼� 9

-  �̼�8���� ������� char* �� string���� �ٲٰ� string�� �� ����� char *�� �ٲٽÿ�

�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
*/

//�ڡڡڡڡڡڡڡڡ� �̼� 8 : ��Ƽ���Ϸ� �и��ϱ� �ڡڡڡڡڡڡڡڡ�

#include "myclass.h"
#include "Error_Check.h"
#include "Data_Modify.h"
#include "User_Infomation.h"

int main() { // ���� �Լ�
	
	Dinamic();			// ������ �����Ҵ�
	Data_Reading();		// �����ܾ� �о����
	Data_UseReading();	// ������ �о����

	User_Information User;
	AccountBook_Start AccountStart; // ����� ����

	return 0;
}