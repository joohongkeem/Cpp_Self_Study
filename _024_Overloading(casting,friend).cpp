﻿#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


/*
	- 프렌드 함수는 멤버 함수가 아니지만 멤버 함수의 특권을 모두 가지고 있다.
	> 프렌드 함수에 대해 논하기 전에 생성자를 통한 자동 형 변환에 대하여 논의한다.
	> 이것은 우리에게 프렌드 함수로서 연산자 오버로딩하는 것에 대한 장점을 설명해준다.


	* 자동 형 변환에 대한 생성자

	- 만약 클래스 정의에 적절한 생성자가 포함된다면, 시스템은 형 변환을 자동으로 수행한다.
		Ex) Money baseAmount(100,60), fullAmount;
			fullAmount = baseAmount+25;
			fullAmount.output();
			을 하게 되면, $125.60이 출력이 된다.
				
			   ★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★
			-> 연산자 오버로딩을 멤버함수로 하면 이렇게 출력되지 않고, (_022_Overloading(MemberFunction).cpp 참고)
			   연산자 오버로딩을 클래스 외부에 함수로 선언하면 잘 출력된다. (_021_Overloading(Basic).cpp 참고) 
	  
	  But, 곰곰히 생각해보면 무엇인가 이상하다!
	       식에서 25는 적절한 형이 아니다! 왜냐면, 1개의 정수와 Money형에 대하여 덧셈을 오버로딩 하지 않았기 때문!!
		   즉, 클래스의 정의부에서 정수형을 Money형으로 변환하는 방법을 알려주지 않는 한,
		       25는 Money형으로 사용될 수 없다.
		   이 때, 어떠한 과정을 거치냐면, 
		       첫번째로, 시스템은 Money형과 정수형의 조합으로 연산자가 오버로딩 되었는지 체크한다. -> 없음
			   두번째로, 시스템은 정수형의 하나의 인자를가지는 생성자가 있는지 검사한다. -> 있음
						  이러한 생성자가 있으니, 이 생성자를 사용하여 정수 25를 Money형으로 변환시킨다.
			   만약, 두번째에 해당하는 생성자가 없다면, 형 변환이 일어나지 않음을 명심하자! ★★★★★★★★

	> 생성자에 의해 자동으로 일어나는 자동 형 변환은 +나 -같은 숫자 연산자 오버로딩에서는 일반적으로 행해진다.
	  하지만, 이러한 자동 형 변환은 일반적인 함수, 멤버 함수, 그리고 오버로딩된 함수의 인자에 같은 방법으로 적용됨!


	* [★함정★] 멤버 연산자와 자동 형 변환
  
	- 이항 연산자를 멤버 연산자로서 오버로딩 할때, 2개의 인자는 더이상 대칭적이지 않다.
	> 하나는 호출 객체이고, 나머지 하나는 인자이다. (여기서 멤버연산자로 오버로딩할때 치명적인 단점이 드러난다!!★★)
	> 어떠한 자동 형 변환도 두번째 인자에만 적용이 되기 때문에,
			fullAmount = 25 + baseAmount; 를 하게되면, 25는 객체를 호출하지 못하기 떄문에, baseAmount와의 덧셈이 불가능해진다.
	> But, 이항 연산자를 클래스 외부에서 오버로딩하면, 완벽하게 동일하게 작동한다

	★★★★★★★★★★★★★★★★★★★★★★★★★★★★★
	- 즉 정리하자면,
		연산자를 독립적으로 오버로딩할 경우의 
			장점 : fullAmount = 25 + baseAmount; fullAmout = baseAmout + 25; 모두 가능
			단점 : private 멤버 변수에 직접 접근할 수 없어, mutator, accessor 함수를 사용해야 한다.
		연산자를 멤버함수로 오버로딩할 경우의
			장점 : private 멤버 변수에 직접 접근할 수 있어, mutator, accessor 함수를 사용할 필요가 없다.
			단점 : fullAmout = baseAmout + 25; 의 값도 이상하게 출력되며,
			        fullAmount = 25 + baseAmount; 는 실행조차 되지 않는다.

		-> 이와 같은 두 가지 장점을 모두 가지는 방법이 '프렌드 함수로서 오버로딩' 하는 방법이다.
*/


/*
	* 프렌드 함수
	
	★★★
	- 만약, 잘 갖춰진 accessor와 mutator 함수가 있다면 이 함수들은 독립적인 연산자 오버로딩에 사용할 수 있다.
	  But, 멤버 변수를 읽기위해 여러개의 accessor에 접근해야 하므로, 코드를 읽기도 어려우며 또한 비효율적이다.
	  이를 해결하기 위해, 멤버 함수로서 연산자를 오버로딩할 수 있지만,
	  그렇게 하더라도 첫째 피연산자의 자동 형 변환을 할 수 없는 문제점을 가지고 있다.
	  프렌드 함수로서 +연산자를 오버로딩하는 방법은 멤버 변수로의 직접적인 접근과 모든 피연산자의 자동 형 변환이 가능하다.

	- 클래스의 '프렌드 함수(friend function)'는 클래스의 멤버 함수는 아니지만 클래스의 멤버 함수가 동작하는 것 처럼
	  클래스의 private멤버에 접근할 수 있다.
	  프렌드 함수를 만들기 위해서는 클래스 정의에서 프렌드 함수로 명명해야 한다.
	  클래스의 정의부에서 연산자나 함수 선언 앞에 friend 키워드를 사용함으로써 연산자나 함수를 클래스의 프렌드로 만들 수 있다.
	  하지만, 프렌드는 클래스의 멤버함수가 아니다.
	  프렌드는 클래스의 멤버에 비정상적으로 접근하는 정상적인 함수이다.★★
			> 연산자의 정의부에서는 함수 헤더 부분에 제한자 Money::를 사용하지 않는다.
			> 선언에서만 friend 키워드를 사용하고, 정의부에서는 friend 키워드를 사용하지 않는다.
			> 프렌드 연산자는 모든 인자에 대하여 자동 형 변환을 지원한다.
			> 프렌드 함수는 public 섹션이나 private 섹션 어느 곳에 위치해도 무방하지만, public 함수를 원하는 경우에는 public섹션에 선언해야한다.

	- 가장 일반적인 프렌드 함수는 연산자의 오버로딩이지만, 일반적인 함수도 가능하다.


	[★함정★]
	- 어떤 C++ 컴파일러는 프렌드 함수가 작동하지 않는다
			>> 이러한 문제를 해결하기 위해서는 아래의 두가지 방법중 적절한 방법을 선택해야한다.
					1) accessor와 mutator 함수와 함께 외부 함수를 선언하여 사용
					2) 멤버로서 연산자 오버로딩을 하여 사용하여야 한다.
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

	// - 연산자의 정의부에서는 함수 헤더 부분에 제한자 Money::를 사용하지 않는다.
	// - 선언에서만 friend 키워드를 사용하고, 정의부에서는 friend 키워드를 사용하지 않는다.
	// - 프렌드 연산자는 모든 인자에 대하여 자동 형 변환을 지원한다.
	// - 프렌드 함수는 public 섹션이나 private 섹션 어느 곳에 위치해도 무방하지만, public 함수를 원하는 경우에는 public섹션에 선언해야한다.
	//
	friend const Money operator + (const Money& amount1, const Money& amount2);
	friend const Money operator - (const Money& amount1, const Money& amount2);
	friend bool operator == (const Money& amount1, const Money& amount2);
	friend const Money operator - (const Money& amount1);

private:
	int dollars;
	int cents;

	int dollarsPart(double amount) const;
	int centsPart(double amount) const;
};



int main()
{
	Money account(120,50);
	account.output();

	(account+40).output();
	(40+account).output();		// friend함수를 이용하니 둘 다 잘 실행됐다.

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

// - 연산자의 정의부에서는 함수 헤더 부분에 제한자 Money::를 사용하지 않는다.
// - 선언에서만 friend 키워드를 사용하고, 정의부에서는 friend 키워드를 사용하지 않는다.
// - 프렌드 연산자는 모든 인자에 대하여 자동 형 변환을 지원한다.
// - 프렌드 함수는 public 섹션이나 private 섹션 어느 곳에 위치해도 무방하지만, public 함수를 원하는 경우에는 public섹션에 선언해야한다.
//
const Money operator +(const Money& amount1, const Money& amount2)
{
	int flags= 0;
	int allCents1 = amount1.dollars*100 + amount1.cents;
	int allCents2 = amount2.dollars*100 + amount2.cents;
	// 
	// 아래처럼 선언하던걸 드디어 위처럼 선언할 수 있어졌다!!
	//
	//int allCents1 = amount1.getDollars()*100 + amount1.getCents();
	//int allCents2 = amount2.getDollars()*100 + amount2.getCents();


	int sumCents = allCents1 + allCents2;
	if(sumCents< 0) {
		sumCents = -sumCents;
		flags=1;
	}
	int finalDollars = sumCents/100;
	int finalCents = sumCents%100;
	
	if(flags){
		finalDollars = -finalDollars;
		finalCents = -finalCents;	
	}


	return Money(finalDollars, finalCents);
}

const Money operator -(const Money& amount1, const Money& amount2)
{
	int flags= 0;
	int allCents1 = amount1.dollars*100 + amount1.cents;
	int allCents2 = amount2.dollars*100 + amount2.cents;
	// 
	// 아래처럼 선언하던걸 드디어 위처럼 선언할 수 있어졌다!!
	//
	//int allCents1 = amount1.getDollars()*100 + amount1.getCents();
	//int allCents2 = amount2.getDollars()*100 + amount2.getCents();


	int diffCents = allCents1 - allCents2;
	if(diffCents< 0) {
		diffCents = -diffCents;	
		flags=1;
	}
	int finalDollars = diffCents/100;
	int finalCents = diffCents%100;
	
	if(flags){
		finalDollars = -finalDollars;
		finalCents = -finalCents;	
	}

	return Money(finalDollars, finalCents);
}

const Money operator -(const Money& amount)
{
	return Money(-amount.dollars, -amount.cents);
}

bool operator ==(const Money& amount1, const Money& amount2)
{
	return( (amount1.dollars == amount2.dollars)
		&& (amount1.cents == amount2.cents));
}

