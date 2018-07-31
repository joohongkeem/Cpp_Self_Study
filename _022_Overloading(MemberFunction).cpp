#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


/* 
	* 멤버 함수로의 오버로딩
	
	- '_021_Overloading(Baisc)'에선 연산자를 독립 함수로 클래스 외부에 정의하여 오버로딩하였다.
	  But, 연산자를 멤버 연산자(함수)로서 오버로딩 하는 것 또한 간증하다.
	
	  [★★주의사항★★]
		- 이항 연산자를 멤버 연산자로 오버로딩할 경우에는 연산자는 2개의 인자가 아닌,
		  하나의 인자를 갖는다. 
		> 호출된 객체는 첫 번째 인자처럼 사용된다★★★★
			
			Ex) Money account1, account2, total;
				total = account1+ account2;

			-> 위에서 account1 은 호출된 객체이고
			           account2는 연산자 + 의 하나의 인자가 된다.
				
*/

class Money
{
public:
	// 생성자
	//
	Money();				
	Money(double amount);
	Money(int theDollars);
	Money(int theDollars, int theCents);

	void output() const;

	// 멤버 함수로서 연산자를 오버로딩할 때에는, 
	// 멤버 변수를 직접 참조할 수 있기때문에 accessor와 mutator함수가 필요없다.
	// But, const가 잘 작동하는지 확인해보기위해 mutator 함수를 정의함
	//
	void setmoney();

	// ★★★★★★★★★★★★★★★★★★★★★★★★★★
	// - 첫 번째 객체가 호출 객체이기 때문에, 수정을 방지하기 위해 후미에 const 선언
	//
	const Money operator + (const Money& amount2) const;
	const Money operator - (const Money& amount2) const;
	bool operator == (const Money& amount2) const;
	/*
		* 단항 연산자 오버로딩
		- 하나의 피연산자(인자)를 갖는 연산자의 오버로딩
		> ★★★★★★★★★★
		  아래와 유사한 방법으로 ++와 -- 연산자를 오버로딩 할 수 있다.
		  But, 사용시에 ++x, --x와 같이 전위식으로 사용할 수 있다.
			   후위식으로 사용하는 것은 다음장에 등장!!
	*/
	const Money operator - () const;

private:
	int dollars;
	int cents;

	// 실수형을 받아, 달러부분과 센트 부분으로 나누어 주기 위한 함수
	// - 함수내에서만 호출되므로 private으로 선언
	// - 함수 내부에서 멤버 변수의 값을 변경하면 안되므로 const로 선언
	// 
	int dollarsPart(double amount) const;
	int centsPart(double amount) const;
};


int main()
{
	Money account1;
	Money account2(3.14);
	Money account3(10);
	Money account4(5, 6);

	account1.output();
	account2.output();
	account3.output();
	account4.output();

	cout<< "---------------------------------------------------------------------------\n" ;
	
	// 이렇게 사용하려고 만든 함수가 아니기때문에 출력이 좀 이상하다
	// 
	(-account1).output();
	(-account2).output();
	(-account3).output();
	(-account4).output();
	
	cout<< "---------------------------------------------------------------------------\n" ;
	
	(account2+account3).output();
	(account2+account1+account4).output();

	
	cout<< "---------------------------------------------------------------------------\n" ;

	(account3-account2).output();
	(account1-account4).output();
	
	
	cout<< "---------------------------------------------------------------------------\n" ;

	// 이런식의 출력은 불가능하다.
	//
	//cout << account2 == account2  << endl;
	//cout << 1==1 <<endl; 가 안되는 이유와 같다!!

	if(account1 == account3) cout << "같다" << endl;
	else cout << "다르다" << endl;

	if(account1 == account1) cout << "같다" << endl;
	else cout << "다르다" << endl;

	
	cout<< "---------------------------------------------------------------------------\n" ;

	Money joohong, eunji;
	joohong.setmoney();
	eunji.setmoney();

	joohong.output();
	eunji.output();

	cout << "합 -> " ;
	(joohong+eunji).output();
	cout << "차 -> " ;
	(joohong-eunji).output();

	// ★★★★★★★★★★★★★★★★★★
	//(joohong+eunji).setmoney();
	//(-joohong).setmoney();
	//
	// - + 연산자 정의 앞에 const를 붙이지 않는다면, 위의 문장들이 가능해진다
	// > 이러한 사태를 막기위해 const 로 선언해주는것 ★★★★★★★★★★★★★★★★★★
	//
	// - But, 아래처럼 하는건 상관 없다
	//

	Money Sum = joohong+eunji;
	Sum.output();
	Sum.setmoney();
	Sum.output();

	cout<< "---------------------------------------------------------------------------\n" ;
				
									// ★★★★★★★★★★★★★★★★★★★★★★★★★★★★★
	(Money(13,5) + 45).output();	// 잘 출력되지 않는다!!! (_024_Overloading(casting,friend).cpp 참고)
									// 이상한 값이 출력된다.
									//
									// 심지어 (45+Money(13,5)).output(); 는 실행조차 되지 않는다.
	return 0;
}


Money::Money():dollars(0),cents(0)
{
}
Money::Money(double amount):dollars(dollarsPart(amount)),cents(centsPart(amount))
{
}
Money::Money(int theDollars):dollars(theDollars),cents(0)
{
}
Money::Money(int theDollars, int theCents):dollars(theDollars),cents(theCents)
{
}

// 실수형을 받아, 달러부분과 센트 부분으로 나누어 주기 위한 함수
// - 함수내에서만 호출되므로 private으로 선언
// - 함수 내부에서 멤버 변수의 값을 변경하면 안되므로 const로 선언
// 
// ★★ 선언에서 const를 붙여줬으므로, 정의에서도 뒤에 const를 붙여줘야 한다.
int Money::dollarsPart(double amount) const
{
	return static_cast<int> (amount);
}

int Money::centsPart(double amount) const
{
	return static_cast<int>((amount-dollarsPart(amount))*100);
}


void Money::output() const
{

	double total = dollars + cents/100.0;
	cout << "잔액 : $ "<<total <<endl;
}

// 반드시 뒤에 const를 적어줘야한다 (호출된 객체의 값 수정 방지)
//
const Money Money::operator +(const Money& secondOperator) const
{
	// ★★★★★★★★★★★★★★★★★★★★
	// - 멤버 함수로의 오버로딩에서, 호출된 객체는 첫번째 인자처럼 사용되기 때문에
	//   호출된 객체는 첫 번째 인자처럼 사용된다.
	//   즉, cents, dollars를 멤버변수를 호출하면, 첫번째 인자로 사용할 수 있는 것이다.
	//		-> Money 클래스 객체 안의 멤버 함수이기때문에, 멤버변수 자체를 첫번째 인자로 사용하는것!!
	//
	int allCents1 = cents + dollars * 100;
	int allCents2 = secondOperator.cents + dollars * 100;
	int flag = 0;

	int sumAllCents = allCents1 + allCents2;
	if(sumAllCents < 0){
		flag = 1;
		sumAllCents = -sumAllCents;
	}

	int finalDollars = sumAllCents / 100;
	int finalCents = sumAllCents % 100;

	if(flag){
		finalDollars = -finalDollars;
		finalCents = -finalCents;
	}

	return Money(finalDollars, finalCents);
}
// 반드시 뒤에 const를 적어줘야한다 (호출된 객체의 값 수정 방지)
//
const Money Money::operator -(const Money& secondOperator) const
{
	// ★★★★★★★★★★★★★★★★★★★★
	// - 멤버 함수로의 오버로딩에서, 호출된 객체는 첫번째 인자처럼 사용되기 때문에
	//   호출된 객체는 첫 번째 인자처럼 사용된다.
	//   즉, cents, dollars를 멤버변수를 호출하면, 첫번째 인자로 사용할 수 있는 것이다.
	//
	int allCents1 = cents + dollars * 100;
	int allCents2 = secondOperator.cents + dollars * 100;
	int flag = 0;

	int diffAllCents = allCents1 - allCents2;
	if(diffAllCents < 0){
		flag = 1;
		diffAllCents = -diffAllCents;
	}

	int finalDollars = diffAllCents / 100;
	int finalCents = diffAllCents % 100;

	if(flag){
		finalDollars = -finalDollars;
		finalCents = -finalCents;
	}

	return Money(finalDollars, finalCents);
}
// 반드시 뒤에 const를 적어줘야한다 (호출된 객체의 값 수정 방지)
//
bool Money::operator ==(const Money& secondOperand) const
{
	return ( (dollars == secondOperand.dollars)
			&& (cents == secondOperand.cents));
}

// 반드시 뒤에 const를 적어줘야한다 (호출된 객체의 값 수정 방지)
//
const Money Money:: operator -(void) const
{
	return Money(-dollars, -cents);
}


void Money::setmoney()
{
	cout << "Dollars 입력: ";
	cin >> dollars;
	cout << "Cents 입력: ";
	cin >> cents;

}