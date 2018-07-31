#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


/* 
	- 클래스 안에 또 다른 클래스를 정의할 수 있다.
		-> 클래스 안에 있는 클래스를 '중첩된 클래스(nested class)'라고 한다.

	class OuterClass
	{
	public:
		...
	private:
		class InnerClass
		{
			...
		};
		...
	};

	- 중첩된 클래스는 public도 private도 될 수 있다.
	> 중첩된 클래스가 위에 나타난 형태와 같이 private라면, 외부클래스 밖에서는 사용불가
	> 중첩된 클래스는 public이든 private든 외부 클래스의 멤버 함수를 정의할 때 사용할 수 있다.

	- 중첩된 클래스는 외부 클래스의 영역에 있기 때문에 
	  예에 있는 InnerClass와 같은 중첩된 클래스의 이름은 
	  외부 클래스의 밖에서 다른 무언가를 위해 사용할 수 있다.
	  그러나, 외부 클래스의 밖이라면, 중첩된 클래스의 형 이름은 OuterClass::InnerClass가 된다.

	- 클래스는 함수 정의 내부에서도 정의할 수 있다.
	  이러한 경우에 클래스는 함수 정의 안에서만 의미를 가지므로 '지역적 클래스' 라고 한다.
	  지역적 클래스는 정적 멤버를 포함할 수 없다!!!★★★

*/