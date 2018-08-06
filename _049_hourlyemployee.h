// Employee클래스의 파생클래스인 HourlyEmployee클래스를 위한 인터페이스
//

#ifndef HOURLYEMPLOYEE_H
#define HOURLYEMPLOYEE_H

#include <string>
#include "_049_employee.h"

using std::string;

/*
	  클래스 Employee와 2개의 파생 클래스(시간제, 정규직) 을 같은 네임스페이스 안에 둘 필요는 없지만,
	  서로 관련있는 클래스들이므로 같은 네임스페이스에 두는 것이 좋다!!
*/
namespace SavitchEmployees
{

/*
	- 파생 클래스의 정의는 다른 클래스 정의와 비슷하게 시작하지만, 첫 줄에 콜론(:), 예약여 public, 기반 클래스의 이름이 추가된다.
	  
	- HourlyEmployee와 같은 파생클래스는 자동적으로 Employee와 같은 기반 클래스의 모든 멤버변수와 멤버 함수를 상속받고,
	  새로운 멤버 변수와 멤버 함수를 추가할 수 있다.
	  즉, HourlyEmployee클래스의 정의에서 멤버 변수 name, ssn, netPAy를 따로 정의하지 않았지만,
		  HourlyEmployee클래스의 모든 객체는 멤버 변수 name, ssn, netPAy를 '상속받아' 가지고 있는 것이다.
	  또한, 멤버 변수 뿐만 아니라, getName, getSsn, getNetPay, setName, setSsn, setNetPay, printCheck과 같은 Employee클래스의 멤버 함수 역시 상속받는다.
*/
	class HourlyEmployee : public Employee
	{
	public:
		HourlyEmployee();
		HourlyEmployee(const string& theName, const string& theSsn,
			double theWageRate, double theHours);
		
		void setRate(double newWageRate);
		double getRate() const;
		void setHours(double hoursWorked);
		double getHours() const;
		void printCheck();				// 만약 상속된 멤버함수의 정의를 변경하고 싶다면, 파생클래스의 정의에서 상속된 멤버 함수를 정의하면 된다.★★★★★★★
										// -> 이러한 경우에 상속된 멤버 함수를 '재정의(redefining)' 한다고 한다.
										// [★주의사항★] 오버로딩과는 다르다. 오버로딩은 함수가 2개가 되지만, 재정의는 하나의 함수만 갖게 되는 것이다!!!

	private:
		double wageRate;
		double hours;
	};
}

#endif