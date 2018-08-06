// 응용 프로그램
// - 명명되지 않은 네임스페이스의 보조 함수를 감추는 것을 보여준다.


#include <iostream>
#include "_048_dtime.h"

void readHours(int &theHour);

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	using DTimeSavitch::DigitalTime;

	int theHour;
	readHours(theHour);				// 구현파일 _048_dtime.cpp 에 있는 readHour함수와는 다른 함수이다.


	DigitalTime clock(theHour, 0), oldClock;

	oldClock = clock;
	clock.advance(15);
	if(clock == oldClock) cout << "Something is wrong.\n";

	cout << "너의 입력 : " << oldClock << endl;
	cout << "그로부터 15분 후 : " << clock << endl;
	clock.advance(2,53);
	cout << "그로부터 2시간 53분 후 : " << clock << endl;


	return 0;
}


void readHours(int &theHour)
{
	using std::cout;
	using std::cin;
	//
	// 앞에서 사용한 using 선언은 main안에서만 유효
	// 즉, 여기서 다시 cin, cout을 사용하기위해선 반복하여 선언해줘야 한다.


	cout << "시간을 입력하시오 : ";
	cin >> theHour;
}