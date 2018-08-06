#include <iostream>
using std::cout;
using std::endl;

#include "_050_pfarrayd.h"

PFArrayD::PFArrayD() : capacity(50), used(0)
{
	a = new double[capacity];
}

PFArrayD::PFArrayD(int size) : capacity(size), used(0)
{
	a = new double[capacity];
}

/* 
	* 복사 생성자(copy constructor)★★★★★

	- 복사 생성자는 클래스와 동일한 타입인 하나의 인자를 갖는 생성자이다.
	  하나의 인자는 반드시 참조 호출 인자여야만 하며, 일반적으로는 한정자 const를 가진다.

	- C++이 객체를 복사하고자 할때는 언제든 복사 생성자를 자동 호출한다고 볼 수 있다.
	  복사 생성자는 다음 세가지 상황에서 호출된다
		1) 클래스의 객체가 선언되고 괄호 안에서 같은 타입의 다른 객체로 초기화 되는 경우
		   ( 이 경우는 복사 생성자를 보통 다른 생성자와 같은 방법으로 사용하는 것이다.)
	    2) 함수가 클래스형의 값을 반환하는 경우
		3) 클래스형의 인자가 call-by-value 인자인 "plugged in"인 경우
		   이 경우에는 복사 생성자가 "plugging in"의 의미를 정의한다.

	- 만일 클래스의 복사 생성자가 정의되지 않았다면, C++ 시스템은 자동으로 복사 생성자를 만들어 준다.
	  But, 이 기본 복사 생성자는 멤버 변수의 내용을 단순히 복사하므로, 포인터나 동적 변수를 포함하는
	       멤버 변수를 가진 클래스에서는 정확하게 동작하지 않을 수도 있다.
	  따라서, 만일 클래스 멤버 변수가 포인터나 동적 배열, 동적 데이터를 포함하고 있따면 반드시 복사 생성자를 정의하여야 한다.
	  즉, 포인터와 new 연산자를 가진 모든 클래스는 반드시 복사 생성자를 가져야 한다.

*/
PFArrayD::PFArrayD(const PFArrayD& pfaObject)
: capacity(pfaObject.getCapacity()), used(pfaObject.getNumberUsed())
{
	a = new double[capacity];
	for(int i=0; i<used; i++)
		a[i] = pfaObject.a[i];
}

void PFArrayD::addElement(double element)
{
	if(used >= capacity)
	{
		cout << "배열이 꽉찼습니다.\n"<<endl;
		exit(0);
	}
	a[used++] = element;

}

bool PFArrayD::full() const
{
	return capacity == used;
}

int PFArrayD::getCapacity() const
{
	return capacity;
}

int PFArrayD::getNumberUsed() const
{
	return used;
}

void PFArrayD::emptyArray()
{
	used = 0;
}

double& PFArrayD::operator [] (int index)			// [] 연산자의 오버로딩
{
	if(index>=used)
	{
		cout << "잘못된 index 입니다.\n" << endl;
		exit(0);
	}
	return a[index];
}


PFArrayD& PFArrayD::operator = (const PFArrayD& rightSide)	// = 연산자의 오버로딩(반드시 멤버함수)
{

/*
	★★★★★★★★★★★★★★★★★★★★★★★
	- 중복 할당 연산자를 정의할 때 가장 중요한 점
		1) 멤버 연산자로서 정의하기
		2) 양쪽에 동일한 객체가 있더라도 잘 동작하는지 반드시 확인하기
*/
	if(capacity != rightSide.capacity)					// 양쪽의 객체의 크기가 같은지 먼저 확인후, 크기를 먼저 맞춰준다.
	{
		delete [] a;
		a = new double[rightSide.capacity];
	}

	capacity = rightSide.capacity;
	used = rightSide.used;

	for(int i=0; i<used; i++)
		a[i] = rightSide.a[i];

	return *this;											//★★ this 포인터를 사용하여 반환한다.

}


/* 
	* 소멸자

	- 동적 할당 변수는 적절히 delete를 호출하지 않으면 사라지지 않는다는 문제가 있다.
	  이 문제를 해결하기 위하여, C++는 '소멸자(destructor)'라는 특별한 멤버함수를 사용한다.

	- 소멸자는 객체가 그 영역을 벗어나는 경우에 자동으로 실행되는 멤버 함수이다.
	  만일 클래스형의 객체가 함수의 지역 변수라면, 소멸자는 함수 호출이 종료되기 전의 마지막 동작에서 자동적으로 호출된다.
	 
	- 한 클래스는 오직 하나의 소멸자만을 가지며, 한 클래스의 소멸자를 중복 정의할 수 없다.
*/
PFArrayD::~PFArrayD()
{
	delete [] a;
}