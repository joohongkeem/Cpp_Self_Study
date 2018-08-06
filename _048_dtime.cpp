// DigitalTime 클래스의 구현파일.
// - DigitalTime 클래스의 인터페이스는 헤더파일 _048_dtime.h 에 있다.

#include <iostream>
#include <cctype>
#include <cstdlib>
using std::istream;
using std::ostream;
using std::cout;
using std::cin;
#include "_048_dtime.h"

namespace	// 명명되지 않은 네임스페이스를 나타낸다.
{
	int digitToInt(char c)
	{
		return (int(c) - int('0'));
		//
		// 명명되지 않은 네임스페이스에서 정의된 이름들은 컴파일 단위 안에서만 사용될 수 있다.
		// 즉 이 보조 함수들은 _048_dtime.cpp 파일에서만 사용된다.
	}

	void readMinute(int& theMinute)
	{
		char c1, c2;
		cin >> c1 >> c2;
		if(!(isdigit(c1) && isdigit(c2)))
		{
			cout << "Error : illegal inpuit to readMinute\n" ;
			exit(1);
		}
		theMinute = digitToInt(c1)*10 + digitToInt(c2);

		if(theMinute<0 || theMinute > 59)
		{
			cout << "Error : illegal inpuit to readMinute\n" ;
			exit(1);
		}
	}

	void readHour(int& theHour)
	{
		char c1, c2;
		cin >> c1 >> c2;
		if( !( isdigit(c1) && (isdigit(c2) || c2 == ':' ) ) )
		{
			cout << "Error : illegal inpuit to readHour\n" ;
			exit(1);
		}
		
		if(isdigit(c1) && c2 == ':')
		{
			theHour = digitToInt(c1);
		}
		else
		{
			theHour = digitToInt(c1)*10 + digitToInt(c2);
			cin >> c2;	// : 를 삭제한다.
			if(c2 != ':')
			{
				cout << "Error : illegal inpuit to readHour\n" ;
				exit(1);
			}
		}

		if(theHour == 24) theHour = 0;

		if(theHour<0 || theHour> 23)
		{
			cout << "Error : illegal inpuit to readHour\n" ;
			exit(1);
		}
	}


}


namespace DTimeSavitch
{
	istream& operator >>(istream& ins, DigitalTime& theObject)
	{
		readHour(theObject.hour);
		readMinute(theObject.minute);		// 컴파일 단위 안에서는 별도의 명시 없이 명명되지 않은 네임스페이스 안의 이름을 쓸 수 있다.
		return ins;
	}

	ostream& operator << (ostream& outs, const DigitalTime& theObject)
	{
		outs << theObject.hour << ':' ;
		if(theObject.minute < 10)
			outs << '0';
		outs << theObject.minute;
		return outs;
	}

	bool operator == (const DigitalTime& time1, const DigitalTime& time2)
	{
		return (time1.hour==time2.hour && time1.minute==time2.minute);
	}

	DigitalTime::DigitalTime(int theHour, int theMinute)
	{
		if( theHour<0 || theHour>24 || theMinute<0 || theMinute>59)
		{
			cout << "Illegal argument to DigitalTime Constructor.\n";
			exit(1);
		}
		else
		{
			hour = theHour;
			minute = theMinute;
		}
		
		if(hour == 24) hour = 0;
	}

	DigitalTime::DigitalTime()
	{
		hour = 0;
		minute = 0;
	}

	int DigitalTime::getHour() const
	{
		return hour;
	}

	int DigitalTime::getMinute() const
	{
		return minute;
	}

	void DigitalTime::advance(int minutesAdded)
	{
		int grossMinutes = minute + minutesAdded;
		minute = grossMinutes%60;
		int hourAdjustment = grossMinutes/60;
		hour = (hour + hourAdjustment)%24;
	}

	void DigitalTime::advance(int hoursAdded, int minutesAdded)
	{
		hour = (hour + hoursAdded) % 24;
		advance(minutesAdded);
	}
}