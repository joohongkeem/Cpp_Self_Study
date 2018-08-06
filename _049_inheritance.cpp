/* 
	* 상속의 기초

	- 상속은 '기반 클래스(base class)'라 불리는 클래스로부터 '파생 클래스(derived class)'라 불리는 새로운 클래스를 생성하는 과정이다.
	  파생 클래스는 기반 클래스가 가진 모든 멤버 변수와 모든 함수를 자동적으로 가지게 되고,
	  추가적으로 새로운 멤버 함수와 멤버 변수를 가질 수 있다.
	  > 이 것을, 파생 클래스가 멤버 변수와 멤버 함수를 '상속(inherit)'받는다고 표현한다.

	- 예를들어, 정규 직원과 시간제 직원들의 기록을 관리하는 프로그램을 설계한다고 하자.
	  전체 직원은 시간제 급여를 받는 직원과, 매달 또는 매주 고정 급여를 받는 직원들로 이루어진다.
	  모든 직원은 이름과 주민번호를 갖고 있으며, 이 이름과 주민등록번호를 설정하고 변경하기 위한 멤버 함수들은
	  정규직이든 시간제이든 같을 것이다.

	  즉, 정규직 및 시간제를 포함하는 모든 직원을 대상으로 하는 Employee라는 클래스를 정의할 수 있으며
	  이 클래스를 이용하여 정규직 및 시간제 직원 각각을 위한 파생 클래스를 정의할 수 있을 것이다.

	  모든 직원에 대해 같은 Employee 객체를 사용할 수 있지만, 여기서 Employee 클래스를 정의하는 이유는
	  서로 다른 종류의 직원들을 위한 파생 클래스를 정의할 수 있도록 하기 위한 것이다.
	  특히, printCheck함수는 파생 클래스마다 그 정의가 바뀔 것이고, 
	  결과적으로 서로 다른 종류의 직원들은 서로 다른 종류의 수표를 가질 것이다.
	  (직원들의 차이가 없는 Employee 클래스에서 수표를 인쇄하는것은 이치에 맞지 않으므로, 
	   Employee 객체의 printCheck가 호출될경우 오류메시지와 함께 프로그램이 멈추도록 구현하였다.)

	  클래스 Employee로부터 파생된 모든 클래스는 자동적으로 클래스 Employee의 멤버 변수(name, ssn, netPay)를 갖게 된다.
	  또한, printCheck, getName, setName과 같은 멤버함수도 갖게 된다
	  즉, 파생 클래스가 멤버 변수와 멤버 함수를 '상속(inherit)'받게 되는 것이다.

	  클래스 Employee와 2개의 파생 클래스(시간제, 정규직) 을 같은 네임스페이스 안에 둘 필요는 없지만,
	  서로 관련있는 클래스들이므로 같은 네임스페이스에 두는 것이 좋다!!

	- 일반적으로, 기반 클래스는 '부모 클래스(parent class)' 라 하며, 파생 클래스는 '자식 클래스(child class)'라고 한다.
	  또한, 어떤 클래스의 부모의 부모의 부모 클래스는 '조상 클래스(ancestor class)'라고 하며,
	        만일 클래스 A가 클래스 B의 '조상(ancestor)'라면, 클래스 B는 클래스 A의 '자손(descendant)'이다.



	  ★★★★★★★★★★★★★★★★★★★★★★★★
	* 파생 클래스의 객체는 하나 이상의 타입을 가진다.

	- 시간제직원(HourlyEmployee)은 직원(Employee)의 파생 클래스이므로, 
	  HourlyEmployee의 모든 객체는 Employee객체가 사용될 수 있는 곳이면 어느 곳이나 사용될 수 있다.
	  특히, 함수가 타입 Employee의 인자를 요구할 때, 그 변수의 위치에 HourlyEmployee의 객체를 할당할 수 있다. ★★★
	  (But, 반대로 HourlyEmployee의 변수에는 타입 Employee의 객체를 할당할 수는 없다.★★★★)
	> 좀 더 일반적으로 말하면,
	  모든 클래스의 객체들은 조상 클래스의 객체가 사용될 수 있는 곳이라면 사용될 수 있다.!!
	  But, 자손 클래스가 사용될 수 있는곳에 조상 클래스의 사용은 대체로 허용되지 않는다.
*/



/*
	  ★★★★★★★★★★
	* 파생 클래스의 생성자

	- 기반 클래스의 생성자는 파생 클래스에서 상속받을 수 없는 대신, 
	  파생 클래스의 생성자에서 기반 클래스의 생성자를 호출할 수 있다.
	  파생 클래스의 생성자는 기반 클래스의 생성자를 특별한 방법으로 이용한다.
	  기반 클래스의 생성자는 기반 클래스로부터 상속받은 모든 데이터를 초기화 하는데 사용된다
	> 그러므로, 파생 클래스의 생성자는 기반 클래스의 생성자를호출하는 것으로 시작된다.
	  Ex)
	  		SalariedEmployee::SalariedEmployee(const string& theName,
				const string& theNumber, double theWeeklyPay)
				: Employee(theName, theNumber), salary(theWeeklyPay)
			{
				// 고의적으로 비워둠
			}
	> Employee(theName, theNumber)는 인자 theName과 theNumber를 가지고 기반 클래스의 Employee 클래스의 생성자를 호출하는 부분이다.

	  Ex)
	  		HourlyEmployee::HourlyEmployee()
				: Employee(), wageRate(0), hours(0)
			{
				// 고의적으로 비워둠
			}
	> 이 생성자의 정의에서는 기반 클래스 생성자의 디폴트생성자는 상속된 멤버 변수를 초기화하기위해 호출된다.
	  ★★★★★★★★★★
	  파생 클래스의 생성자의 초기화 부분에는 반드시 기반 클래스 생성자 중 하나가 포함되어야 한다.
	  만약, 파생 클래스의 생성자 정의가 기반 클래스의 생성자 호출을 포함하지 않는다면 기반 클래스의 디폴트 생성자가 자동으로 호출된다.★★
	  (디폴트 생성자가 없다면 오류가 발생한다.)

	- 기반 클래스 생성자에 대한 호출은 파생 클래스 새엉자의 첫 번째 동작이다.
	  따라서 클래스 B가 클래스 A에서 파생되고, 클래스 C가 클래스 B에서 파생된다면,
	  클래스 C의 객체가 생성될때, 먼저 클래스 A의 생성자가 호출되고, 그 다음에 클래스 B의 생성자가 호출되며,
	  마지막으로 클래스 C 생성자의 나머지 동작이 이루어진다.
*/


/*
	* 상속되지 않는 함수들
	
	- 일반적으로 파생클래스는 기반 클래스의 모든 '일반적인' 함수들을 상속받는다.
	  But, 특별한 목적으로 상속되지 않는 일부 특수한 함수들이 있다.
	  예를 들어, 생성자와 private 멤버 함수들은 상속되지 않았다.
	  소멸자와, 복사 생성자도 상속되지 않는다.
	  할당 연산자 '=' 또한 상속되지 않는다.
	  즉, 빅쓰리(소멸자, 복사 생성자, 할당 연산자) 는 상속되지 않는다.

*/

#define _CRT_SECURE_NO_WARNIGS
#include <iostream>
#include <string>
#include "_049_hourlyemployee.h"
#include "_049_salariedemployee.h"
using namespace std;
using SavitchEmployees::HourlyEmployee;
using SavitchEmployees::SalariedEmployee;	// 네임스페이스를 정의해주지 않으면 객체를 호출할 수 없다 ★★★


int main()
{
	HourlyEmployee joohong;
	joohong.printCheck();
	joohong.setName("Joohongkeem");
	joohong.setSsn("921208-1231432");
	joohong.setHours(69.4);
	joohong.setRate(7000);
	joohong.printCheck();

	SalariedEmployee eunji("Eunjiahn","960312-2132123",523420);
	eunji.printCheck();
	
/*
	- name은 기반 클래스 Employee의 private 멤버 변수이다.
	  이는, 클래스 Employee의 멤버 함수 정의 내에서만 직접 접근이 가능하다는 의미이다.
	  기반 클래스에서 private인 멤버 변수 또는 멤버함수는 다른 어떤 클래스의 멤버 함수에서, 심지어 파생 클래스의 멤버 함수에서도
	  그 이름 자체로는 접근할 수 없다.
	> 그러므로 클래스 HourlyEmployee 정의의 어떤 멤버 함수의 정의에서도 멤버 변수 name에 직접 접근할 수 없다.

	  즉, salariedemployee 클래스에

	   	void HourlyEmployee::setHourlyName(const string& theName)
		{
			name = theName;
		}

	  라는 함수를 정의할 수 가 없다!!! ★★★★★★★★★★★★★★★★★★★★★★

	> 즉, 기반 클래스의 private 변수에 접근하기 위해서는, getName과 같은 'accessor 함수' 와 setName과 같은 'mutator 함수'를 사용해야 한다.




	* ★private 제한자★

	- private 멤버 변수(또는 멤버 함수)는 기반 클래스의 인터페이스 및 구현의 외부분만 아니라
	  파생 클래스의 멤버 함수에서조차도 직접 접근이 불가능하다.
	  (private 변수는 accessor 및 mutator 멤버 함수를 통해 간접적으로라도 접근할 수 있지만,
	   멤버 함수는 그 조차도 불가능하다!!
	   But, 그것은 문제가 되지 않는다.
	        그 이유는 private 멤버 함수는 단지 도움 함수처럼 사용되야 하므로 정의된 클래스 안에서만 사용하도록 제한되기 때문이다.
			만약 멤버 ㅎ삼수를 상속된 다수의 클래스에서 도움 멤버 함수로 사용하고자 한다면, 더 이상 도움함수가 아니므로 public으로 만들어야 한다.


	* ★protected 제한자★
	
	- 파생 클래스의 정의와 구현에서 private 멤버 변수와 private 멤버 함수에 접근할 수 없다.
	  만약, 멤버 변수 또는 멤버 함수 앞에 'protected 제한자'를 사용한다면,
	        파생 클래스 이외의 클래스 또는 함수에서는 private 제한자를 사용하는 것과 같은 효과가 있지만,
			파생 클래스(를 포함한 모든 자손 클래스)에서는 이름을 직접 사용하여 접근할 수 있다.

*/

	return 0;
}