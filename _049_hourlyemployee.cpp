// Employee클래스의 파생클래스인 HourlyEmployee클래스의 구현
// - HourlyEmployee 의 인터페이스는 헤더파일인 _049_hourlyemployee.h 에 있다.
//

#include <string>
#include <iostream>
#include "_049_hourlyemployee.h"

using std::string;
using std::cout;
using std::endl;

/*
	  클래스 Employee와 2개의 파생 클래스(시간제, 정규직) 을 같은 네임스페이스 안에 둘 필요는 없지만,
	  서로 관련있는 클래스들이므로 같은 네임스페이스에 두는 것이 좋다!!
*/
namespace SavitchEmployees
{
	HourlyEmployee::HourlyEmployee()
		: Employee(), wageRate(0), hours(0)
	{
		// 고의적으로 비워둠
	}

	HourlyEmployee::HourlyEmployee(const string& theName,
		const string& theNumber, double theWageRate, double theHours)
		: Employee(theName, theNumber), wageRate(theWageRate), hours(theHours)
	{
		// 고의적으로 비워둠
	}

	void HourlyEmployee::setRate(double newWageRate)
	{
		wageRate = newWageRate;
	}


	double HourlyEmployee::getRate() const
	{
		return wageRate;
	}

	void HourlyEmployee::setHours(double hoursWorked)
	{
		hours = hoursWorked;
	}

	double HourlyEmployee::getHours() const
	{
		return hours;
	}

/*
	printCheck 함수 내에서 netPay가 사용되기 때문에, printCheck 함수 내에서 netPay의 값을 설정한다.

	★★★★★★★★★★
	그게 중요한게 아니고,
	파생 클래스에서 상속받은 멤버 함수를 재정의 할 때 함수 printCheck에서 const를 누락할 수 있다는 것을 주목하라.
	(employee.h 에서는 printCheck() const 이지만, 여기서는 const를 누락시켰다)
*/
	void HourlyEmployee::printCheck()
	{
		setNetPay(hours * wageRate);

		cout << " --------------------------------------- " << endl;
		cout << " 분    류 : 시간제 직원 " << endl;
		cout << " 이    름 : " << getName() << endl;
		cout << " 주민번호 : " << getSsn() << endl;
		cout << " 시    급 : " << wageRate << endl;
		cout << " 근무시간 : " << hours << endl;
		cout << " 수 령 액 : " << getNetPay() << endl;
	}
}