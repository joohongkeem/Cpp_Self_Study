#define _CRT_SECURE_NO_WARINGS

#include <iostream>
#include <string>

using namespace std;

/*
	* 문자열을 다루는 두 가지 방법
		1) C-string 

		2) string클래스 

		- <string> 라이브러리에 정의되어 있으며, 정의문들은 std 네임스페이스에 명시되어 있다.
		> 따라서 프로그램에서 string 클래스를 사용하기 위해서는 
			#include <string>
			using namespace std; 
		  의 과정이 필요하다

		- string 클래스는 string 값과 string 변수들을 간단하게 조작할 수 있게 해준다.
		> '= 연산자'를 이용하여 string 변수에 값을 할당할 수 있으며,
		> '+ 연산자'를 이용하여 2개의 string을 서로 연결할 수 있다.
			ex) s3 = s1 + s2; 를 하면, s3의 저장공간보다 s1과 s2를 합친 스트링의 길이가 큰 경우
				s3의 저장공간이 자동적으로 증가하게 된다.

		- s3 = "Hello World\n"; 라는 코드를 작성하면,
		  실제 "Hello World\n"은 C-String에 속하지만 string형의 데이터는 아니지만, 자동으로 string형으로 형 변환을 해준다.

		- string 클래스에는 3개의 생성자가 있다.
			1) string str;
				- 디폴트 생성자, str 객체 이름을 갖는 string 생성

			2) string str("string");
				- "string" 값을 가지는 string 객체 생성

			3) string str(aString);
				- string 클래스의 객체 aString의 값을 복사한 str 객체 이름을 갖는 string 생성

*/



