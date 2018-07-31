#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


/* 
	* 기본 연산자 오버로딩

	- DayofYear day1(12,8), day2(3,12);		가 있을때,
	  add(day1,day2)가 아닌 day1+day2 를 사용하고 싶다면, 연산자 오버로딩을 해야 한다.
	  -> 연산자를 오버로딩 하는 것은 함수를 오버로딩 하는것돠 매우 유사하다.
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

	// accessor 함수
	// - 연산자의 정의가 class의 멤버함수가 아니므로, 접근하기 위한 mutator가 필요하다.
	//
	int getDollars() const;
	int getCents() const;

	// mutator 함수
	// - 연산자를 const로 선언하지 않는다면, (account1 + account2).set()이 가능해지는지 확인!!
	// - setmoney는 객체의 값을 변경하므로 const로 선언하면 안된다!!!
	//
	void setmoney();

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

/*
	★★★★★
	- 연산자를 오버로딩 하면 연산자는 클래스형을 인자로 사용하라 수 있다.
	> 오버로딩된 + 연산자와 일반적인 함수는 구문에서 약간의 차이를 보인다.
	  즉, + 기호는 함수 이름으로 사용될 수 있고, 연산자 키워드의 의미보다 우선한다.

    - 피연산자(인자)들은 모두 Money형의 상수형 참조 인자이다.
	> 최소 하나의 피연산자가 클래스형이면, 피연산자는 어떠한 형도 될 수 있다.
	> 피연산자는 call-by-value나 call-by-reference 모두 될 수 있고, const 수정자를 옵션으로 갖는다.
	  효율성 때문에, 보통 call-by-reference를 사용한다!
	  일반적으로, Money형의 값이 return되지만, 일반적인 경우 void형을 포함하여
				   어떠한 형의 값도 리턴될 수 있다.
    > 오버로딩된 이항 연산자 +와 -는 클래스 Money의 멤버 연산자가 아니기 때문에,
	  access함수와 mutator함수를 정의해야만 한다★★★
	  (+와 -를 멤버연산자로 오버로딩하는 방법은 다음 장을 참고하라! 각각의 장단점이 있다)
	
	- 이들은 멤버 함수가 아니기때문에 const를 함수 뒤에 붙이는게 아니라 앞에 붙인다.★★★

	★★★★
	- 오버로딩의 중요한 제약은 최소한 하나의 피연산자는 클래스형이여야 한다는 것이다
	> 예를들어 % 연산자를 오버로딩할 때,
	  피연산자가 모두 Money형이거나 하나가 Money형이고 하나가 double형인 경우는 가능하지만,
	  2개의 피연산자가 double형인 경우에는 불가능하다.

	
	★★★★★★★★★★★★★★★★★★
	- + 연산자 앞에 const를 붙이지 않는다면, (account1+account2).setmoney(); 가 가능해진다
	> 이러한 사태를 막기위해 const 로 선언해주는것 
	- 즉, const Money operator + (const Money& amount1, const Money& amount2); 에서
		  첫 번째 const : 리턴되는 객체를 변경할 수 없다!!
		
	
*/
const Money operator + (const Money& amount1, const Money& amount2);
const Money operator - (const Money& amount1, const Money& amount2);
bool operator == (const Money& amount1, const Money& amount2);

/*
	* 단항 연산자 오버로딩
	- 하나의 피연산자(인자)를 갖는 연산자의 오버로딩
	> ★★★★★★★★★★
	  아래와 유사한 방법으로 ++와 -- 연산자를 오버로딩 할 수 있다.
	  But, 사용시에 ++x, --x와 같이 전위식으로 사용할 수 있다.
	       후위식으로 사용하는 것은 다음장에 등장!!
*/
const Money operator - (const Money& amount1);


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
	//
	// - + 연산자 정의 앞에 const를 붙이지 않는다면, (joohong+eunji).setmoney(); 가 가능해진다
	// > 이러한 사태를 막기위해 const 로 선언해주는것 ★★★★★★★★★★★★★★★★★★
	//
	// - But, 아래처럼 하는건 상관 없다
	//

	Money Sum = joohong+eunji;
	Sum.output();
	Sum.setmoney();
	Sum.output();

	cout<< "---------------------------------------------------------------------------\n" ;

	// 왜이렇게 '-'연산이 잘 구현됐는지 확인하기 !!
	// 
	Money(-3,-4).output();
	cout << Money(-3,-4).getDollars()<<endl;			// -3
	cout << Money(-3,-4).getCents()<< endl;				// -4
														// 아주 잘 출력된다.

	
	cout<< "---------------------------------------------------------------------------\n" ;
						
									// ★★★★★★★★★★★★★★★★★★★★
	(Money(13,5) + 45).output();	// 정상적으로 잘 출력된다!!! (_024_Overloading(casting,friend).cpp 참고)
	(45+Money(13,5)).output();		// 이거는 요것도 잘 출력된다!!!
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

int Money::getDollars() const
{
	return dollars;
}
int Money::getCents() const
{
	return cents;
}


const Money operator +(const Money& amount1, const Money& amount2)
{
	int flags= 0;
	//int allCents1 = amount1.dollars*100 + amount1.cents;
	//int allCents2 = amount2.dollars*100 + amount2.cents;
	// 
	// 위에처럼 선언하면 private변수에 접근할 수 없으므로 아래처럼 mutator를 사용해야한다!
	//
	int allCents1 = amount1.getDollars()*100 + amount1.getCents();
	int allCents2 = amount2.getDollars()*100 + amount2.getCents();


	int sumCents = allCents1 + allCents2;
	if(sumCents< 0) {
		sumCents = -sumCents;	// sumCents는 음수값을 가질 수 있음
		flags=1;
	}
	int finalDollars = sumCents/100;
	int finalCents = sumCents%100;
	
	if(flags){	// sumCents가 0보다 작았다면, 반환값도 음수로 바꿔준다.
		finalDollars = -finalDollars;
		finalCents = -finalCents;	
	}

	// - 생성자는 객체를 리턴한다.
	// > 아래의 Money(finalDollars, finalCents) 와 같은 문장을 '무명 객체(anonymous object)'라 함
	return Money(finalDollars, finalCents);
}

const Money operator -(const Money& amount1, const Money& amount2)
{
	int flags= 0;
	//int allCents1 = amount1.dollars*100 + amount1.cents;
	//int allCents2 = amount2.dollars*100 + amount2.cents;
	// 
	// 위에처럼 선언하면 private변수에 접근할 수 없으므로 아래처럼 mutator를 사용해야한다!
	//
	int allCents1 = amount1.getDollars()*100 + amount1.getCents();
	int allCents2 = amount2.getDollars()*100 + amount2.getCents();


	int diffCents = allCents1 - allCents2;
	if(diffCents< 0) {
		diffCents = -diffCents;	// sumCents는 음수값을 가질 수 있음
		flags=1;
	}
	int finalDollars = diffCents/100;
	int finalCents = diffCents%100;
	
	if(flags){	// sumCents가 0보다 작았다면, 반환값도 음수로 바꿔준다.
		finalDollars = -finalDollars;
		finalCents = -finalCents;	
	}

	return Money(finalDollars, finalCents);
}

const Money operator -(const Money& amount)
{
	return Money(-amount.getDollars(), -amount.getCents());
}

bool operator ==(const Money& amount1, const Money& amount2)
{
	return( (amount1.getDollars() == amount2.getDollars())
		&& (amount1.getCents() == amount2.getCents()));
}

void Money::setmoney(void)
{
	cout << "dollars 입력 : " ;
	cin >> dollars;
	cout << "cents 입력 : " ;
	cin >> cents;
}