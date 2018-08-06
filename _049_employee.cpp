// Employee 클래스의 구현
// - Employee 클래스의 인터페이스는 헤더파일 _049_employee.h 에 있다.

#include <string>
#include <cstdlib>
#include <iostream>
#include "_049_employee.h"

using std::string;
using std::cout;

namespace SavitchEmployees
{
	Employee::Employee(): name("No name yey"), ssn("No number yet"), netPay(0)
	{
		// 의도적인 공백
	}

	Employee::Employee(const string& theName, const string& theNumber)
		: name(theName), ssn(theNumber), netPay()
	{
		// 의도적인 공백
	}

	string Employee::getName() const
	{
		return name;
	}

	string Employee::getSsn() const
	{
		return ssn;
	}

	double Employee::getNetPay() const
	{
		return netPay;
	}

	void Employee::setName(const string& newName)
	{
		name = newName;
	}

	void Employee::setSsn(const string& newSsn)
	{
		ssn = newSsn;
	}

	void Employee::setNetPay(double newNetPay)
	{
		netPay = newNetPay;
	}

	void Employee::printCheck() const
	{
		cout << "ERROR : printCheck Funtion called for an \n"
			<< "Undifferentiated Employee. Aborting the Program.\n";
		exit(1);
	}
}