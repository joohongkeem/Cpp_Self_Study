#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


/*
	* 참조(Reference)

	- 참조는 저장 위치의 이름이다. 다음에 기술된 대로 독립 참조(standlanoe reference)가 가능하다.
		ex) int robert;
			int& bob = robert;
			>> 위의 코드는 bob을 변수 robert에 대한 저장 위치를 참조하게 만든다.
			   즉, bob을 변수 robert의 엘리어스(alias, 별명)로 만드는 것이다.
				   bob의 변화도 robert를 변하게 만든다.

	- 위에 제시된 독립 참조는 코드의 혼란을 가져오고 문제를 일으킨다.
	  (대부분의 예시에서 독립참조는 문제가 있고, 특수한 경우에 유용하다.)
	  	
*/

//★★★★★★★★★★★★★★★★★★★
double& sampleFunction(double& variable);

int main()
{

	double m = 99;
	cout << sampleFunction(m) << endl;
	//
	// 99가 출력된다.
	// 99라는 값을 갖고 있는 m을 변수로 받아, 반환해주므로, 99가 출력

	sampleFunction(m) = 42;
	cout << m << endl;	
	//
	// 42가 출력된다.
	// 99를 갖고있는 m을 변수로 받아, 그 것을 참조해주므로 값을 변환시킬수 있다.



	return 0;
}

double& sampleFunction(double& variable)
{
	return variable;
}


/*
	* l-value와 r-value
	- l-value라는 용어는 할당 연산자의 왼쪽에 있는 것을 이야기할 때 사용한다.
	  r-value라는 용어는 할당 연산자의 오른쪽에 있는 것을 이야기할 때 사용한다.
	> 만약 함수에 의해 리턴된 객체를 l-value로 만들고 싶다면 반드시 참조로 리턴해야 한다.

	

	* 클래스형의 멤버 변수 리턴하기
	
	- 클래스형의 멤버 변수로 리턴할 때는 거의 모든 경우에 const 값에 의한 멤버 변수로 리턴해야만 한다.

		ex) 
		class Employee
		{
		public:
			Money& getSalary() { return salary; }
			...
		private:
			Money salary;
			...
		};

		> 이 예제에서 salary는 Employee 클래스의 몇몇 accessor 함수의 사용을 제외하고는 변경할 수 없는 private 멤버 변수이다.
		  getSalary 함수는 Money 타입의 salary 변수를 리턴한다.
		  만약 참조에 의하여 salary를 리턴하지 않으면, 새롭게 salary 임시 복사본이 생성되고 리턴될 것이다
		  이러한 오버로드를 피하기 위하여 예제에서 사용한 것처럼 참조에 의한 리턴을 사용했다.

		  Employee joe;
		  (joe.getSalary()).input();

		> 이렇게 private 변수 salary에 input을 할 수 있다!! (장점이 될 수도 있고, 단점이 될 수도 있다)

	- but, const Money& getSalary() { return salary; } 
	  의 경우엔, (joe.getSalary()).input(); 는 에러 메시지를 출력한다.

	- 가장 이상적인 선언은 const Money& getSalary() const { return salary; }
	
	> 일반적으로, 멤버 함수가 멤버 변수와 어떤 클래스형의 멤버 변수를 리턴할 때는 private멤버 변수에 대한 외부 접근을 피하기 위하여
	  참조에 의한 리턴을 하지 않는다.
	  만약 효율성을 이유로 참조에 의한 리턴을 원한다면, 리턴 값에 const를 추가하는 것은 멤버 변수에 대한 접근을 보호할 수 있도록
	  도와줄 것이다.

*/