#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

/*
	- call-by-reference 매개변수는 call-by-value 매개변수보다 효율적이다.
	> call-by-value 매개변수는 해당 인자의 값으로 초기화되는 지역변수이다.
	  그래서 함수가 호출되면 인자의 복사본이 생기게 된다.
    > call-by-reference 매개변수를 쓰면 매개변수는 인자로 대체될 공간확보자(placeholder)가 된다.
	  그래서 인자의 원본만 존재한다.
	  ★★★★
	  클래스에 대해서는 함수 매개변수의 값을 변경하지 않는다면, call-by-reference 를 사용하자!
	
	   ★★★
	>> call-by-refernce 매개변수를 사용하면서, 함수가 매개변수의 값을 변경할 수 없도록 하려면
	   매개변수형 앞에 const 수정자를 두면 된다!!!
	   이러한 매개변수를, 'constant 매개변수' 또는 'constant call-by-reference 매개변수'라 한다.
	>> 이렇게 선언하면, 함수의 정의 안에서 무심코 매개변수를 수정하면, 에러메시지를 보낸다.
	
	ex) 매개변수를 수정하면 안될때!!
		class DayofYear
		{
		public:
				...
				bool isLarger(const DayofYear& day1, const DayofYear& day2);
				...
		};
		
		bool isLarger(const DayofYear& day1, const DayofYear& day2)
		{
			if(day1.month > day2.month) return 1;
			else if(day1.month < day2.month) return 0;
			else
			{
				if(day1.day >= day2.day) return 1;
				else return 0;
			}
		}

	ex) 호출 객체의 값을 변경해선 안되는 멤버 변수를 작성할 때 ★★★★★★★
		- 함수 내부에서 멤버 변수의 값을 변경할 수 없음
		- 이 함수 내에서 상수화 되지 않은 함수의 호출을 허용하지 안흠
		- 멤버변수의 포인터의 리턴을 허용하지 않음
		class DayofYear
		{
		public:
				...
				void output() const;		// const는 다음과 같이 함수 선언의 끝에 적어준다!!!
				...
		};
		
		void DayofYear::output() const		// 함수 선언과 정의에 const 수정자를 일관되게 사용!!
		{
			...
		}


	★★★★
	- const 수정자는 모든 경우에 사용하거나, 아예 사용하지 않아야 한다.
	> const 수정자가 클래스 매개변수와 클래스의 멤버 함수에 적절하다면 필요한곳에서
	  항상 const 수정자를 사용해야만 한다.
	> 만일 클래스에 대해 const 수정자가 적절할 때마다 항상 사용하지 않을 것이라면,
	  절대로 이 클래스에 대해 const를 사용해선 안된다.

*/


int main()
{


	return 0;
}