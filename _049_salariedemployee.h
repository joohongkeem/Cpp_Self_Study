// Employee클래스의 파생클래스인 SalariedEmployee클래스를 위한 인터페이스
//

#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H

#include <string>
#include "_049_employee.h"

using std::string;

/*
	  클래스 Employee와 2개의 파생 클래스(시간제, 정규직) 을 같은 네임스페이스 안에 둘 필요는 없지만,
	  서로 관련있는 클래스들이므로 같은 네임스페이스에 두는 것이 좋다!!
*/
namespace SavitchEmployees
{
	class SalariedEmployee : public Employee
	{
	public:
		SalariedEmployee();
		SalariedEmployee(const string& theName, const string& theSsn, double theWeeklySalary);

		double getSalary () const;
		void setSalary(double newSalary);
		void printCheck();				// 만약 상속된 멤버함수의 정의를 변경하고 싶다면, 파생클래스의 정의에서 상속된 멤버 함수를 정의하면 된다.★★★★★★★
										// -> 이러한 경우에 상속된 멤버 함수를 '재정의(redefining)' 한다고 한다.
										// [★주의사항★] 오버로딩과는 다르다. 오버로딩은 함수가 2개가 되지만, 재정의는 하나의 함수만 갖게 되는 것이다!!!

	private:
		double salary;

	};
}

#endif