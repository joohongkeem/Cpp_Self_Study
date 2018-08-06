// DigitalTime 클래스를위한 인터페이스

#ifndef DTIME_H
#define DTIME_H

#include <iostream>
using std::istream;
using std::ostream;

namespace DTimeSavitch
{
	class DigitalTime
	{
	public:
		DigitalTime();	// 디폴트 생성자 : 시간 값을 0:00으로 초기화한다.
		DigitalTime(int theHour, int theMinute);

		int getHour() const;
		int getMinute() const;

		void advance(int minutesAdded);	// 분을 더한다.
		void advance(int hoursAdded, int minutesAdded);	// 시:분을 더한다.

		friend bool operator == (const DigitalTime& time1, const DigitalTime& time2);
		friend istream& operator >> (istream& ins, DigitalTime& theObject);
		friend ostream& operator << (ostream& ins, const DigitalTime& theObject);

	private:
		int hour;
		int minute;

	};
}

#endif