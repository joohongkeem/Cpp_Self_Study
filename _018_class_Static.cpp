#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

/*
	- 가끔 동일한 클래스의 모든 객체가 공유하는 변수를 갖고 싶을 것이다.
	  예를 들어, 클래스의 모든 객체가 특정 멤버 함수를 호출한 횟수를 저장할 변수 !!
		-> 이러한 변수를 정적 변수(static variable)라 하며,
		   객체들이 서로 대화하거나 그들의 행동을 조정하는데 사용될 수 잇다.
		   전역변수의 오용을 피하면서, 전역변수의 장점을 취할 수 있게 해준다.
		   또한, 해당 클래스의 객체만이 직접 접근할 수 있도록 private가 될 수도 있다.
	
	- 함수가 객체의 데이터를 참조하지 않더라도 클래스의 멤버로 두기를 원한다면,
	  이 함수를 정적 함수로 만들면 된다.
		-> 정적 함수는 클래스의 객체를 이용한 일반적인 방법으로 호출할 수 있다.
		   But, 클래스 이름과 영역 지정 연산자를 사용하여 정적 함수를 호출하는 것이 좋다★★
				ex) Server::getTurn()
		-> 정적 함수는 객체 없이도 호출할 수 있으므로, 
		   정적 함수의 정의에서 호출 객체에 의해 좌우되는 것은 어떤 것도 사용할 수 없다.
		   즉, 정적 함수를 정의할 때는 함수에서 생성된 객체 또는 지역변수가 아닌 한
		       어떤 비정적 변수나 비정적 멤버 함수를 사용할 수 없다.
*/

class Server
{
public:
	Server(char letterName);
	void serveOne();
	static int getTurn();
	static bool stillOpen();


private:
	// 정적 변수는 선언 시작부분에 static이란 자격을 부여하는 키워드로 표시한다.
	//
	static int turn;
	static int lastServed;
	static bool nowOpen;
	char name;
};

// ★★★★★★★★★★★★★★★★★★★★★★★★★★★★★
// 정적 변수는 반드시 클래스의 정의 밖에서 초기화되어야 한다.
// -> private의 개념에 어긋나는 것처럼 보이지만 절대 아니다!!! 
//    두번씩 초기화 할 순 없으므로 반드시 클래스의 정의 밖에서 초기화!!!!!!
//
int Server::turn = 0;
int Server::lastServed = 0;
bool Server::nowOpen = true;

int main()
{
	Server s1('A'), s2('B');
	int number, count;
	do
	{
		cout << "How many in your Group? ";
		cin >> number;
		cout << "Your turns are : ";
		for(count=0; count<number; count++)
			cout << Server::getTurn() << " ";	
			//
			// s1.getTurn()으로 선언해도 되지만 Server::getTurn() 으로 선언하는게 좋다 ★★★★
			// Why?
			// 정적 함수는 클래스의 객체를 이용한 일반적인 방법으로 호출할 수 있다.
		    // But, 클래스 이름과 영역 지정 연산자를 사용하여 정적 함수를 호출하는 것이 좋다★★
		cout << endl;
		s1.serveOne();
		s2.serveOne();
	}while(Server::stillOpen());

	cout << "Now Closing service.\n";

	return 0;
}

Server::Server(char letterName)
{
	name = letterName;
}

// ★★★★★★★★★★★★★★★★★★★★★★★★★★★★★
// static키워드는 멤버 함수 선언에는 사용하지만 멤버 함수 정의에서는 사용하지 않는다.
//
int Server::getTurn()
{
	turn ++;
	return turn;
}

bool Server::stillOpen()
{
	return nowOpen;
}

void Server::serveOne()
{
	if(nowOpen && lastServed < turn)
	{
		lastServed++;
		cout << "Server " << name << " now serving " << lastServed << endl;
	}
	if(lastServed>=turn)	// Everyone served
		nowOpen = false;
}