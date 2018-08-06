// Employee 클래스를 위한 인터페이스
// - 서로 다른 종류의 employee들을 파생하기 위해 사용될 기반 클래스를 정의한다.
//

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using std::string;

namespace SavitchEmployees
{
	class Employee
	{
	public:
		Employee();
		Employee(const string& theName, const string& theSsn);
		
		string getName() const;
		string getSsn() const;
		
		double getNetPay() const;
		void setName(const string& newName);
		void setSsn(const string& newSsn);
		void setNetPay(double newNetPay);
		void printCheck() const;

	private:
		string name;
		string ssn;
		double netPay;

	};
}


#endif