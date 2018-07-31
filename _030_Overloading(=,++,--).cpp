#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

/* 
	* 할당 연산자
	- 할당 연산자 = 를 오버로딩하고 싶다면 멤버 연산자로 오버로딩해야 한다.
	  만약 할당 연산자를 오버로딩하지 않는다면 사용자 정의 클래스에 대한 할당 연산자를 자동으로 얻게 된다.
	  디폴트 할당 연산자는 하나의 클래스 객체의 멤버 변수의 값을 또 다른 클래스 객체의 해당 멤버 변수에 복사한다.
	  단순한 클래스에 대해 이 연산자는 원하는 대로 동작한다.
	  포인터와 함께 사용할 때 이 디폴트 할당 연산자는 원하는대로 동작하지 않는다.
	  향후에 이 관점에서 할당 연산자 오버로딩에 대해 논의한다.

*/


/*
	* 증/감 연산자의 오버로딩
	- 전위식으로 사용하느냐, 후위식에 사용하느냐에 따라 차이가 난다.
	  전위식 버전을 오버로딩할 때는 일반적인 방법(멤버 연산자가 아니고 하나의 매개변수를 취하거나, 멤버 연산자로서 매개변수가 없는)으로 오버로딩.
	  후위식 버전을 얻기 위해서는 int형의 두 번째 매개변수를 추가해야 한다.
	  이 두번째 매개변수는 실제로 int형의 인자를 연산자에게 주는 것이 아니라, 컴파일러에게 후위식 오버로딩을 알려주는 '마커 역할' 을 한다. ★★★
	
*/



class Money
{
public:
	Money();				
	Money(double amount);
	Money(int theDollars);
	Money(int theDollars, int theCents);

	friend ostream& operator <<(ostream& outputStream, const Money& amount);

	// ★★★★★★★★★★★★★★
	// 함수나 연산자 선언에서 매개변수의 이름을 주지 않아도 된다.
	// 매개변수가 사용되지 않으므로 매개변수가 없는 것처럼 이해한다.
	//
	Money operator ++();		// 전위 버전
	Money operator ++(int);	// 후위 버전
private:
	int dollars;
	int cents;

	int dollarsPart(double amount) const;
	int centsPart(double amount) const;
};

int main()
{
	Money myAccount(10,20);
	
	cout << "[ 전위증가 ]  " << endl;
	cout << "증감연산 전) " << myAccount << endl ;
	cout << "++myAccount ) " << ++myAccount << endl ;
	cout << "증감연산 후) " << myAccount << endl ;
	

	Money yourAccount(10,20);

	cout << "\n[ 후위증가 ]  " << endl;
	cout << "증감연산 전) " << yourAccount << endl ;
	cout << "yourAccount++ ) " << yourAccount++ << endl ;
	cout << "증감연산 후) " << yourAccount << endl ;
	
	return 0;
}

Money Money::operator ++()		// 전위 버전
{
	dollars++;
	cents++;

	return Money(dollars, cents);

}

Money Money::operator ++(int ignoreMe)		// 후위 버전
{
	int temp1 = dollars;
	int temp2 = cents;

	dollars++;
	cents++;

	return Money(temp1, temp2);

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

int Money::dollarsPart(double amount) const
{
	return static_cast<int> (amount);
}

int Money::centsPart(double amount) const
{
	return static_cast<int>((amount-dollarsPart(amount))*100);
}


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

