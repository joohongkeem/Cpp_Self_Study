#define _CRT_SECURE_NO_WARINGS

#include <iostream>
#include <string>

using namespace std;

/*

	* 원소값 접근
		- str[i] : i번째 인덱스에 위치한 문자 값을 입/출력
		
		- str.at(i) : i번째 인덱스에 위치한 문자 값을 입/출력
		
		- str.substr(int position, int length) : position 값에서 시작하여 length 값만큼의 길이를 가지는 문자열인 서브스트링 값을 리턴

	* 할당/변경자
		- str1 = str2;
			: 문자 저장 곤간을 설정하고 str2의 값으로 초기화 시킴
			  str1을 위하여 공간을 설정하고, str1의 저장공간을 str2의 저장공간 크기로 설정함
		
		- str1 += str2;
			: str2 문자 값을 str1의 뒤에 연결시킴. size 값은 적절히 선택됨

		- str.empty()
			: str이 빈 스트링인 경우 true값을, 아니면 false값을 리턴함

		- str1 + str2
			: str2 값이 str1의 끝 부분에 연결된 스트링을 리턴함. size값은 적절히 선택됨

		- str.insert(pos, str2)
			: str2 값을 pos 위치부터 시작하는 str 값에 삽입함

		- str.remove(pos, length)
			: pos 위치부터 시작하여 length크기만큼 서브스트링의 값을 삭제함

	* 비교
		- str == str2	str1 != str2
			: 값이 서로 동일한지 여부를 확인하여 Boolean 값을 리턴함

		- str1 < str2	str1 > str2		str1 <= str2	str1 >= str2
			: 스트링 값의 크기를 비교하는 네가지 방법, 값의 크기는 사전적 순서에 따라 결정함

		- str.find(str1)
			: str에서 str1 값이 처음으로 존재하는 인덱스 값을 리턴함

		- str.find(str1, pos)
			: str에서 str1 값이 처음으로 존재하는 인덱스 값을 리턴함, pos 위치부터 str1 값을 찾음

		- str.find_first_of(str1, pos)
			: str에서 str1에 존재하는 문자가 있는지 여부를 확인함, pos 위치부터 str1 문자의 존재 여부를 확인함

		- str.find_first_not_of(str1, pos)
			: str에서 str1에 존재하지 않는 문자가 존재하는 여부를 확인하며, pos 위치부터 시작함
*/

int main()
{

/*
	* string 클래스를 이용한 입/출력

	- string 객체도 다른 종류의 데이터들과 마찬가지로 << 연산자 및 cout을 사용하여 출력할 수 있다.
	
	- string 객체도 다른 종류의 데이터들과 마찬가지로 >> 연산자 및 cin을 사용하여 입력할 수 있지만,
	  '>> 연산자'는 공백 문자가 오는 경우 입력을 생략하며, 추가적으로 공백 문자가 존재하면 입력 과정을 멈추게 된다.
	  즉, '>> 연산자'와 cin을 이용하여 단어를 읽을 수 있지만, 라인 또는 공백을 포함한 스트링을 읽어올 수 없다. 

	★★★★★★★
	- 만약, 공백을 포함하여 전체 한 라인을 읽고자 하는 경우, getline함수를 사용할 수 있다.
	  string 객체를 이용하여 getline  함수를 사용하는 방법은 C-String 사용법과는 다르다.
	  즉, cin.getline() 라는 표현을 사용할 수 없고, getline함수에 cin 객체를 인자로 사용하여야 한다.
*/

	string line;
	cout << "Enter a line of input : " ;
	getline(cin, line);
	cout << "Your Input : " << line << endl; 
	//
	// 입력 라인상에 존재하는 문장 전후에 공백들이 존재하면, string객체는 cin을 통해 공백을 읽어올 수 없지만
	// getline 함수를 사용하면 이 공백들도 읽어 들여서 string 값의 일부로 인식하게 된다.
	// (getline 함수는 <string> 라이브러리에 정의되어 있다.
	//  또한, getline 함수에 cin 객체 대신에 텍스트 파일을 연결하여 파일로부터 데이터를 입력할 수 있다.)
	//
	// c(in.get 함수는 char형 값을 읽지만, string형 값은 읽지 않는다.)


	cout<< "---------------------------------------------------------------------------------------------------" << endl;
/*
	★★★★★★★
	[getline 함수 upgrade]
	
	- line 이라는 string 객체가 선언되어 있을 때,
	  getline(cin, line); 는 개행문자('\n')를 만나는 경우 입력이 중단되지만,
	  getline(cin, line, '?'); 를 사용하면 '?'를 만나는 경우 입력 수행이 중단된다!!

	- getline 함수를 void 함수처럼 취급하는것도 타당성이 있어보이지만,
	  getline 함수는 사실 첫 번째 인자, 즉 cin에 대한 참조(refernce)를 리턴한다.
	  따라서, 다음의 코드는 라인 텍스트를 읽어서 s1에 저장하고, 공백이 아닌 문자들을 s2에 저장한다.
*/
	string line2,s;
	cout << "Enter a line of input & string : " ;
	getline(cin,line2) >> s;
	cout << " getline(cin, line2) 후 \n" ;
	cout << "line2 = " << line2 << endl;
	cout << "s = " << s << endl;
	//
	// 위처럼 코드를 짜면 getline(cin,line2); 와 cin>>s; 가 호출되는 것과 같다
	// But, 순서를 바꾼다면? (아래 코드 참고) ★★★★★★★★★
	// cin의 뒤에 '\n'가 버퍼에 남아 원하는대로 동작하지 않는다.
	//
	cout << "Enter a string : " ;
	cin >> s;
	cout << "Enter a line : " ;
	getline(cin,line2);
	cout << "line2 = " << line2 << endl;
	cout << "s = " << s << endl;

	
	cout<< "---------------------------------------------------------------------------------------------------" << endl;

/*
	* string 클래스를 이용한 스트링 처리

	- string 객체를 이용하여 문자를 다룰 때는 배열 원소를 이용하여 문자를 다루는 방법과 동일하다.
	> 따라서 string 객체를 사용하여 문자를 다루는 경우 배열을 통해 문자를 처리하는 기능과
	  또한 자동적으로 데이터 저장공간이 확장되는 등의 배열이 가지고 있지 않은 기능도 함께 사용할 수 있다.

	- 예를 들어, lastName 이름을 가진 string 객체의 경우,
	  lastName[i] 은 스트링의 i번째 문자를 지칭한다.
	  lastName.length(); 는 현재 채워진 배열 공간의 길이를 자동적으로 알려주게 된다.

	- 배열의 괄호 안에 string 클래스의 객체가 명시되는 경우, 배열의 인덱스 범위가 유효한지 여부를 확인하지 않는다.
	> 만약, 인덱스의 범위가 유효하지 않다면(즉, 인덱스의 값이 string객체의 길이보다 크거나 또는 동일한 경우),
	  그 결과 값을 예측할 수 없으며 보통 좋지 않은 결과를 초래하게 된다.
		-> ★★★ at 멤버 함수를 사용하면 유효한 값을 가지지 않는 인덱스를 확인할 수 있다.★★★

	- at 멤버 함수를 사용하는 경우 a[i]로 표현하는 대신에 a.at(i) 표현을 사용하는데,
	  이런 경우, at 멤버 함수는 i값이 정당한 인덱스의 값인지 여부를 판별해준다.
	  만약, a.at(i)의 i값이 유효하지 않으면 실행 에러 메시지가 발생하여 무엇이 잘못됐는지 여부를 파악할 수 있다.
*/
	string str("joohong");
	cout << str[6] << endl;			// g출력
	cout << str[7] << endl;			// 분명 잘못된 인덱스 접근이지만, 정상적으로 실행되고 아무런 문자가 출력되지 않는다.★★★★★★

	// at 멤버함수 ★★★★
	//
	cout << str.at(6) << endl;		// 'g' 출력
	//cout << str.at(7) << endl;	// 잘못된 인덱스 접근이므로, 에러메시지를 발생시킨다!!
									// But, 일부 C++ 컴파일러들에서는 a.at(i)의 인덱스 i값이 유효하지 않은 경우 별다른 설명없이 에러메시지를 발생시키기도 한다.


	cout<< "---------------------------------------------------------------------------------------------------" << endl;

/*
	- 스트링에 존재하는 단일 문자에 char형 값을 할당함으로써 str[i] 등과 같은 인덱스 변수로 변환될 수 있다.
	  at 멤버 함수는 true 또는 false 값을 리턴하기 때문에 at 함수를 이용하여 위와 같은 일을 수행할 수 있다.
*/
	str.at(0) = 'J';
	cout << str << endl;
	str[0] = 'j';
	cout << str << endl;


	return 0;
}