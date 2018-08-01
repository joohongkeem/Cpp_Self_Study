#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
using namespace std;

/*
	* 문자열을 다루는 두 가지 방법
		1) C-string : 문자형 배열을 이용하여 문자열을 저장하고, 배열의 끝 부분에 널 문자 '\0'을 삽입하는 방법
			- C프로그램에서 계승받은 고전적인 방법
			- 오래된 스트링 표현법이지만, 이해하지 않으면 C++의 스트링 처리가 어려움
			- 예를 들어, "Hello"와 같은 스트링은 C++에서는 C-string으로 처리된다
		
		2) string클래스 
*/

/*
	* C-String 
	- 문자열을 표현하는 한 가지 방법은 문자로 구성된 배열을 이용하는 방법.
	> "Hello"라는 문자열을 배열로 표현하기 위해선, 6개의 인덱스 변수로 구성된 배열이 필요하게 된다.
	  (5개의 문자를 위한 5개의 인덱스 + 문자열의 끝을 표시하는 '\0'를 표시하기 위한 인덱스)
	> 여기서, '\0'을 널 문자라고 하며, 문자열의 끝을 표시하는 종료 표시자로 사용된다.
	> 이런식으로, 널문자를 이용하여 배열 형식으로 표현되는 문자열을 'C-String'이라고 한다.
	
	* C-String 변수
	- 문자를 저장하는 배열과 동일하지만 다르게 사용된다.
		>> char Array_name[MAX_SIZE + 1];
		   여기서, +1 은 '널문자'를 넣기 위해 필요한 공간!!

	* [★주의점★]
	- char shortString[] = ['a','b','c'];	에서는 뒤에 널 문자가 없으므로 크기가 3이 된다.
	  char shortString[] = "abc";			에서는 뒤에 널 문자가 들어가서 크기가 4가 된다.


	* <cstring> 라이브러리
	- C-String을 선언하고 초기화 시키는 경우 별도의 include 지시자 또는 using 문장을 명시할 필요는 없다
	  But, C-String을 사용하는 경우, 필연적으로 <cstring> 라이브러리에서 정의된 문자열 함수들을 사용하게 되므로
	       보통 #include <cstring> 을 해준다.
    - <cstring> 정의문은 std 네임스페이스에서 규정되어 있지 않고, 전역 네임스페이스에 저장되어 있기 때문에
	  별도의 using 문장이 필요하지 않다.

				함수								설명											

			strcpy(Target, Source)				Source의 값을 Target으로 복사

			strncpy(Target, Source, Limit)		Source의 값을 Target으로 
												최대 Limit값의 개수만큼 복사

			strcat(Target, Source)				Source의 값을 Target의 끝에 이어붙임

			strncat(Target, Source, Limit)		Source의 값을 Target의 끝에
												Limit 개수의 문자열을 이어붙임

			strcmp(String1, String2)			같으면 0, >이면 1양수, <이면 음수 반환

			strncmp(String1, String2, Limit)	strcmp와 동일하지만 Limit개만큼의 문자비교

			strlen(String)						문자열의 길이를 반환(널문자는 무시함)

	[★★★★★★★★ 주의사항 ★★★★★★★★]
	- C-String 에서는 '='와 '=='대신 strcpy, strcmp 함수를 사용해야 한다.
	> '='는 초기화에는 가능하지만, 할당은 불가능하다
		ex) char astring[10] = "Hello";		(가능)

			char astring[10];
			astring = "Hello";				(불가능)
*/


/* 
	* 명령형 인자
	- $ ./getline string1 string2 에서
	  코드가 int main(int argc, char* argv[]) 라면, argv[0] = 프로그램의 이름("./getline"), argv[1] = "string1", argv[2] = "string2" 이고, argc = 3이 된다.
	> 이 때, argv 매개변수가 'C-String 배열' !!!
*/

int main()
{
	// - C-String은 삽입 연산자(<<)를 이용하여 출력할 수 있다.
	// > 변수형으로도 출력이 가능하고, 따옴표 문자열을 이용하여 출력할 수도 있다.
	//
	char myname[10] = "joohong";
	cout << "My name is " << myname << endl;
	
	// - C-String은 입력 연산자(>>)를 이용하여 값을 채울 수 있지만 한 가지 유의할 사항이 있다.
	// > 다른 모든 종류의 데이터와 마찬가지로 C-String 변수를 입력 연산자(>>) 를 이용하여 읽어 들일 때,
	//	 모든 공백(여백, 탭 및 라인 공백)은 입력 과정에서 생략되며, 또한 공백 또는 라인 공백을 만나는 경우 입력이 중단된다.
	//
	char a[80], b[80];
	cout << "Enter Some Input : ";
	cin >> a >> b;
	cout << a << b << "#END" << endl;
	cin.ignore();
	//
	// Enter Some Input : ab cd ef gh 를 입력하면
	// abcd#END	일캐 출력된다.

	// ★★★★★★★★★★★★★★★★
	// 한 라인에 속하는 모든 내용을 한꺼번에 읽을 수 있는 쉬운 방법은 C-String을 C-String 변수에 할당하는 것이다.
	// 즉, 모든 입력스트림의 멤버함수로 사전에 정의된 'getline 함수'를 이용하는 것이다.
	// getline함수는 2개의 인자를 보유하고 있는데, 
	//		첫 번째 인자는 입력을 받아들이기 위한 C-String 변수이고,
	//		두 번째 인자는 C-String 변수의 선언 크기를 알려주는 정수이다.
	//		(즉, 두 번째 인자는, C-String 변수의 최대 배열 원소 개수를 뜻하며, 
	//			 결국, getline 함수가 최대로 받아들일 수 있는 문자의 총 수를 의미한다.)
	//
	char c[80];
	cout << "Enter Some Input : ";
	cin.getline(c, 80);
	cout << c << "#END" << endl;
	//
	// 위의 입력에서 ab cd ef gh 를하면 abcd는 위의 출력에서 출력되고, 버퍼에 남아있는 ' ef gh'가 잘 출력된다.
	// Q. 버퍼를 어떻게 비워야할까?

	char shortstring[5];
	cout << "Enter Some Input : ";
	cin.getline(shortstring, 5);
	cout << shortstring << "#END" << endl;
	//
	// asdasdas dasfasdfads 를 입력하면 "asda"만 출력된다. -> 5개를 할당했으나, 1개는 널문자를 위한 공간이기 때문에 그렇다!!!

	return 0;
}