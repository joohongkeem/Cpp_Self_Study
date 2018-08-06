#define _CRT_SECURE_NO_WARINGS
#include <iostream>

using namespace std;

/*
	* 네임스페이스(namespace)
	
	- 여러 프로그래머에 의해서 작성된 클래스와 함수를 사용한다면, 두 포르개럼가 서로 다른 것에 대해 동일한 이름을 사용할 수도 있다
	  이러한 문제를 다루기 위한것이 네임스페이스!
	  네임스페이스란 예를 들면 클래스와 정의와 변수의 선언과 같은 이름의 집합이다.
	  작동시키거나, 동작을 멈출 수 있으므로 다른 네임스페이스의 이름과 충돌할 때, 네임스페이스의 동작을 멈추게 할 수 있다.

	- std라는 네임스페이스는 iostream과 같은 표준 C++ 라이브러리 파일에서 정의된 모든 이름을 포함한다.

	- 모든 코드는 하나의 네임스페이스에 속하게 된다.
	  만일 프로그래머가 특정 네임스페이스를 명시하지 않는다면 작성한 코드는 '전역 네임스페이스'에 속하게 된다.
	  전역 네임스페이스는 using 지시자를 사용하지 않아도 된다.

	- 하나의 프로그램에서 하나 이상의 네임스페이스를 사용할 수 있다.
	  But, 2개의 네임스페이스를 사용하는 프로그램에서 하나의 이름이 2개의 네임스페이스에서 서로 다르게 정의되어 있다면, 오류가 발생한다.
	> But, 같은 프로그램에서 다른 네임스페이스를 사용하지 못한다는 얘기는 아니다. 예를들어 아래의 코드는 가능하다.
			{
				using namepsace NS1;
				myFtn();
			}
			{
				using namespace NS2;
				myFtn();
			}
	 첫 번째 코드에서는 네임스페이스에 NS1에서 myFtn을 정의하고 있으며, 두 번 째는 네임스페이스 NS2에서 myFtn을 정의하고 있다.

	> 블록은 여러 문장, 선언, 그리고 중괄호 {}안에 포함된 다른 코드의 나열이다.
	  한 블록의 시작 부분에서 호출된 using 지시자는 해당 블록에서만 적용된다.
	  즉, 위의 코드에서 첫 번째 블록은 using 지시자의 NS1영역(scope)라고 말하며, 
		  두 번째 블록은 using 지시자의 NS2영역 이라고 말한다.
	  이러한 영역 규칙(scope rule)을 통해 동일한 프로그램 안에서 서로 다른 네임 스페이스를 사용할 수 있다.

	- 일반적으로 using 지시자는 블록이 시작하는 부분에 위치한다.
	  만일 using 지시자가 블록의 중간부분에 있다면, 그 위치부터 블록의 끝까지 유효하다.
	  또한, using 지시자가 파일의 시작 부분에 있다면, using 지시자는 전체 파일에 적용된다.
*/

/*

	* 네임스페이스의 생성

	- 네임스페이스에 코드를 작성하기 위해서 '네임스페이스의 그룹화(namespace grouping)'를 다음과 같은 형식으로 작성할 수 있다.
			namespace NAME_SPACE_NAME
			{
				SOME_CODE;
			}
	  이러한 그룹화 중 하나를 코드에 포함하는 경우에 SOME_CODE에서 정의된 이름들을 NAME_SPACE_NAME에 추가하게 된다.
	  이렇게 추가된 이름들은 using namespace NAME_SPACE_NAME; 을 통해 사용할 수 있다.

*/

namespace Space1
{
	void greeting()
	{
		cout << "안녕하십니까? " << endl;
	}
	void printNum()
	{
		cout << " 0 1 2 3 4 5 6 7 8 9 " << endl;
	}
}
namespace Space2
{
	void greeting()
	{
		cout << "How are you? " << endl;
	}
	void printAlp()
	{
		cout << " a b c d e f g h i ... x y z " << endl;
	}
}

// * using 선언 (using declaration)
// - 네임스페이스의 특정 함수만 사용하고 싶은 경우!!
//   명시된 네임스페이스의 다른 이름들은 사용할 수 없다.
//
// [★주의★]
// - using namespace Space1;
//   위와 같은 것은 'using 지시자' 라고 한다!
//
// * using 선언과 using 지시자의 차이점?
//		1) using 선언은 사용 가능한 네임스페이스의 한 이름만을 만들지만, using 지시자는 사용 가능한 네임스페이스의 모든 이름을 만든다.
//		2) using 선언은 코드에서 사용할 수 있는 이름 하나를 소개함으로써 다른 이름들은 사용할 수 없다
//		   But, using 지시자는 네임스페이스의 모든 이름을 소개한다.
using Space1::printNum;
using Space2::printAlp;

int main()
{
	{
		using namespace Space1;
		greeting();
	}
	{
		using namespace Space2;
		greeting();
	}

	printNum();
	printAlp();			// 가능하다.

	using Space1::greeting;
	{
		using Space2::greeting;
		greeting();				// Space2의 greeting
		Space1::greeting();		// Space1의 greeting도 사용 가능
	}


}

