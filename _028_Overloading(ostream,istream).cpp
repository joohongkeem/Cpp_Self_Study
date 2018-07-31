#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


/*

	* >>와 <<의 오버로딩

	- >>와 <<도 오버로딩될 수 있으며, 사용자가 정의한 클래스 객체의 입/출력에 사용할 수 있다.
	  다른 연산자에서 설명한 것과 다르지 않지만, 약간의 크기가 존재한다.

	- << 연산자는 cout과 함께 사용되는 +나 - 와 유사한 이항 연산자이다.
	  예를 들어, cout << "Hello\n" ; 를 살펴보자.
	  << 연산자의 첫 번째 피연산자는 사전에 정의된 객체 cout(iostream 라이브러리)이고,
				   두 번째 피연산자는 "Hello\n"라는 스트링 값이다.
	  사전에 정의된 객체 cout은 ostream형이고, 따라서 오버로딩할 때는 ostream형인 cout을 매개변수로 받는다.
	  <<의 2개의 피연산자를 모두 바꿀 수 있다!!(★★ 파일 입/출력을 다룰 때 'stream(파일 입/출력 객체)'에 대해 자세히 다룬다)
	
	- int n1, n2; 가 있을 때, n1+n2는 n1+n2 라는 값을 return한다.
	  Money amount(100); 이 있을 때, cout << amount ; 는 과연 무슨 값을 return 할까?
		(Hint)
		cout << "I have " << amount << "dollars\n"; 라는 코드는 사실
		(((cout << "I have ") << amount ) << "dollars\n"); 와 같다.
	
	  즉, cout << amount 는 ostream형(cout형)의 첫 번째 인자를 리턴하는 것이다!!!

	- >> 연산자의 오버로딩도 위와 비슷하지만, 이 연산자의 두 번째 인자가 입력 값을 받는 객체가 된다.
	  따라서, 두 번째 연산자는 일반적인 call-by-reference 매개변수가 되어야 한다.

	★★★★
	- 현실적으로 >>나 << 연산자는 멤버 연산자로 오버로딩할 수 없다.
	  원하는대로 작동하려면, 첫 번째 피연산자(인자)는 cout이나 cin이 되어야 하는데,
	  클래스의 멤버 연산자로 정의하ㅔ 되면 첫 번재 피연산자는 객체를 호출해야 하기 때문에 Money형이 되어야 한다.

	- 결론적으로, <<와 >>의 오버로딩은 아래의 코드와 같다.
*/	

class Money
{
public:
	Money();				
	Money(double amount);
	Money(int theDollars);
	Money(int theDollars, int theCents);

	// - friend 함수를 이용하는 방법을 사용할 것이다!
	// - 계속해서 반환 객체의 값을 변경해주므로 함수 앞에 const를 붙이면 안된다.
	// - friend 함수는 사실 멤버함수가 아니므로, 함수 뒤에 const를 붙이면 안된다.
	friend ostream& operator <<(ostream& outputStream, const Money& amount);
	friend istream& operator >>(istream& inputStream, Money& amount);

private:
	int dollars;
	int cents;

	int dollarsPart(double amount) const;
	int centsPart(double amount) const;
};

int main()
{
	Money myAccount(20,30), yourAccount;

	cin >> yourAccount;
	cout << "My Account is " << myAccount << endl;
	cout << "Your Account is " << yourAccount << endl;

	// <<가 참조를 리턴하기 때문에 << 를 연속으로 사용할 수 있다.
	// 마찬가지로, >>를 연속적으로 사용할 수 있다.
	//
	cout << "Our Accounts are " << myAccount << " and " << yourAccount << endl;

	return 0;
}

// friend함수는 선언에만 사용하고, 정의에는 적지 않는다.
//  + private 멤버변수에 접근할 수 있다.
//
ostream& operator <<(ostream& outputStream, const Money& amount) // 출력할 땐 amount의 값을 건들지 않는다
					// main 함수에서 cout이 outputStream에 플러그인 되었다.
{
	int absDollars = (amount.dollars>=0)? amount.dollars : -amount.dollars;
	int absCents = (amount.cents>=0)? amount.cents : -amount.cents;

	if(amount.dollars<0 || amount.cents<0) outputStream << "$ -";
	else outputStream << "$ ";

	outputStream << absDollars;

	if(absCents >=10) outputStream << '.' << absCents;
	else outputStream << "." << "0" << absCents;

	// 참조 리턴
	//
	return outputStream; 
}

istream& operator >>(istream& inputStream, Money& amount)
// main 함수에서 cin이 inputStream에 플러그인 되었다.
{
	char dollarSign;

	cout << "금액을 '$~~.~~' 의 형태로 입력하세요 : ";
	
	inputStream >> dollarSign;
	if(dollarSign != '$')
	{
		cout << "No dollar sign($) in Money input\n";
		exit(-1);
	}
	
	double amountAsDouble;
	inputStream >> amountAsDouble;

	// 멤버 연산자가 아니기 때문에 Money의 멤버함수에 대해 객체를 호출하도록 기술해야 한다.
	//
	amount.dollars = amount.dollarsPart(amountAsDouble);
	amount.cents = amount.centsPart(amountAsDouble);

	// 참조 리턴
	//
	return inputStream;
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


