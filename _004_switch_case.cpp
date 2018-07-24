#include <iostream>
using namespace std;

/* 
 
 - switch문은 C++에서 유일하게 다중 분기를 구현한 실행 명령어이다.
   
   switch (Controlling_Expression)
   {
       case Constant_1:
				Statement_Sequence_1
				break;

       case Constant_2:
				Statement_Sequence_2
				break;

				...

       case Constant_n:
				Statement_Sequence_n
				break;
	   
	   default:
				Default_Statement_Sequence
   }

 - break문을 만나거나 switch문의 끝에 도달하면 switch문은 종료된다.
   break문을 만나지 않는다면, 계속해서 다음줄의 문장으로 진행한다!!
   >> 이것을 이용하면 여러 조건을 이용한 switch_case문이 가능하다!! [★★아래코드참고]
 - 해당하는게 없으면 default로 !
 - case에 명시된 상수 값은 모두 유일해야 한다!
 
 */



int main()
{
	
	cout << "성적을 입력하세요 : " ;
	char grade;
	cin >> grade;

	switch (grade)
	{
	case 'A':
	case 'a':
		cout << "A를 축하합니다!!"<< endl;
		break;
	case 'B':
	case 'b':
		cout << "B정도면 잘했죠!!"<< endl;
		break;
	case 'C':
	case 'c':
		cout << "C라니.. 노력하자!" << endl;
		break;
	default:
		cout << "..... 종료\n";
	}

}