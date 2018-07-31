#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

/*
	* 생성자(Constructor)
	- 클래스의 객체가 선언될 때 자동으로 호출되는 멤버 함수
		-> 몇 개 또는 모든 멤버 변수의 값을 초기화하는 데뿐만 아니라
		   그 외, 다른 종류의 초기화에도 사용된다.
    - 생성자는 다음 두 가지 점을 제외하고는 다른 멤버 함수 정의와 같은 방법으로 정의한다.
		1) 생성자는 클래스와 똑같은 이름을 가져야 한다.
		   예를 들어, 클래스의 이름이 BankAccount라면, 이 클래스의 모든 생성자는
		   BankAccount라는 이름을 가져야 한다.
	    2) 생성자의 정의에서는 어떤 값도 리턴할 수 없다. 
		   더욱이 함수 정의의 시작 또는 함수 헤더에는 void를 포함해서 어떤 형도 쓸 수 없다.
		3) 일반적으로, 생성자는 public영역에 있어야 한다.


*/
class DayofYear
{
public:
	// 생성자 - month와 day를 인자 값으로 초기화한다.
	// (★주의★) 반환형 아예 X, void도 안된다!!
	//
	DayofYear(int monthValue, int dayValue);	
	DayofYear(int monthValue);
	DayofYear();		// 디폴트 생성자 ★★ -> 이거 없으면 DayofYear date; 불가능!!!

	// mutator
	//
	void set();

	// accessor
	//
	void get();

	// SpecialDay클래스에서 반환받기 위한 함수
	//
	int getday();
	int getmonth();

private:
	int month;
	int day;
};

class SpecialDay
{
public:
	SpecialDay();
	SpecialDay(int month, int day, char* name);
	SpecialDay(DayofYear day, char* name);
	void get();
private:
	DayofYear date;		// 클래스의 멤버 변수가 또 다른 클래스일 수 있다.
	char datename[20];
};

int main()
{
	DayofYear date1(10,5), date2(5);		// 인자 있는 객체 선언방법 1
	DayofYear date3 = DayofYear(12,8);		// 인자 있는 객체 선언방법 2
	//date4 = DayofYear(3,12);				// 요거는 불가능!!!

	date1.get();
	date2.get();
	date3.get();



	DayofYear date5 = DayofYear();			// 인자 없는 객체 선언방법 1
	//date5 = DayofYear();					// 요거는 X
	//date5 = DayofYear;					// 요것두 X
	DayofYear date;							// 인자 없는 객체 선언방법 2
	//DayofYear date();						// 요거는 X
	
	date.get();
	date.set();
	date.get();
					//
					// 디폴트 생성자가 없으면 에러 발생!!
					// [★주의점★] 디폴트 생성자로 객체를 생성할때는 뒤에 괄호 X
					// DayofYear date; 는 가능하지만 DayofYear date(); 는 안된다!!!★★★

	/*
	 * 디폴트 생성자(default constructor)
	 - 인자를 취하지 않는 생성자
	 - 때로는 기본적으로 생성되고, 때로는 기본적으로 생성되지 않는다.★★★
	 > 클래스를 정의하면서 어떤 종류의 생성자도 포함시키지 않는다면, 디폴트 생성자 자동생성
	   다른일은 전혀 하지 않고, 클래스형의 초기화되지 않은 객체를 제공.
     > 만약, 1개 이상의 인자를 취하는 생성자가 하나라도 포함되어있고, 디폴트 생성자가 없다면
	   디폴트 생성자가 존재하지 않게 된다!!! -> 디폴트 생성자로 객체 선언시 오류발생!!!!

	*/


// --------------------------------------------------------------------------------------------------


	// ★★ 클래스를 멤버변수로 사용한 다양한 초기화의 예시!!!
	//

	SpecialDay sday1(12,8,"주홍생일");
	sday1.get();
	
	SpecialDay sday2;
	sday2.get();
	sday2 = SpecialDay(3,12,"은지생일");
	sday2.get();

	DayofYear firstmeet(10,12);
	SpecialDay sday3(firstmeet, "처음만난날");
	sday3.get();

	SpecialDay today(DayofYear(7,31),"오늘");
	today.get();

	return 0;
}

// 생성자의 정의
// (★주의★) 반환형 아예 X, void도 안된다!!
//
DayofYear::DayofYear(int monthValue, int dayValue)
				:month(monthValue), day(dayValue)		// '초기화 섹션'
														// ★★★이런 표기법을 자주 사용한다.
{
}
DayofYear::DayofYear(int monthValue)
				:month(monthValue), day(1)
{
}
DayofYear::DayofYear()
{
	// 인자를 갖는 생성자가 1개 이상 포함되어 있으므로, 디폴트 생성자 반드시 정의해줘야함!
	// 초기화된 객체를 생성만 할 뿐, 아무것도 하지 않는다.

}
void DayofYear::set(void)
{
	cout << "Month 입력 : " ;
	cin >> month;
	cout << "Day 입력 : " ;
	cin >> day;
}

void DayofYear::get(void)
{
	cout << "저장된 날짜는 '" << month << "월 " << day << "일' 입니다" << endl; 
}

int DayofYear::getday()
{
	return day;
}

int DayofYear::getmonth()
{
	return month;
}


SpecialDay::SpecialDay()
{
	// 인자를 갖는 생성자가 1개 이상 포함되어 있으므로, 디폴트 생성자 반드시 정의해줘야함!
	// 초기화된 객체를 생성만 할 뿐, 아무것도 하지 않는다.
}

SpecialDay::SpecialDay(int month, int day, char* name)
						:date(month,day)
{
	strcpy(datename, name);
}
SpecialDay::SpecialDay(DayofYear day, char* name)
						:date(day)
{
	strcpy(datename, name);
}

void SpecialDay::get()
{
	printf("%d월 %d일은 \"%s\"입니다.\n",date.getmonth(), date.getday(), datename);
}