#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


/*
	* 빅 쓰리(big three)
	
	- 복사 생성자, 할당 연산자(=), 소멸자를 빅 쓰리라고 부른다.
	  그 이유는 세 가지 함수 중 하나라도 필요하다면 세가지를 모두 정의해야하기 때문이다.
	  세 가지 함수 중 하나라도 정의하지 않으면 컴파일러는 스스로 기본 함수를 만들어주지만, 의도와 다르게 실행될 수 있다.
	  그러므로, 프로그래머가 직접 정으ㅟ해줘야 한다!!
*/



class PFArrayD
{
public:
	PFArrayD();
	PFArrayD(int capacityValue);
	PFArrayD(const PFArrayD& PFAoBJECT);				// 복사 생성자

	void addElement(double element);
	bool full() const { return (capacity == used) ; }	// 배열이 꽉차면 true, 아니면 false를 반환
	int getCapacity() const { return capacity; }
	int getNumberUsed() const { return used; }

	void emptyArray() { used = 0; }						// 배열을 비움
	double& operator [] (int index);					// 요소를 읽고 값을 변경함

	PFArrayD& operator = (const PFArrayD& rightside);	// 할당 연산자의 오버로딩 ( 반드시 멤버함수여야 한다, friend XXX)

	~PFArrayD();										// 소멸자

private:
	double *a;											// double형 배열을 위한 포인터
	int capacity;										// 배열의 크기
	int used;											// 현재 사용중인 배열의 위치

};

int main()
{
/*
	- 동적 할당 배열의 기본 유형으로서 클래스가 가능하다.
	  또한, 클래스의 멤버 변수로서 동적 할당 배열을 가질 수도 있다.

	* -> 연산자
	- 화살표 연산자(arrow operator) -> 는 역참조 연산자(*)와 점 연산다를 동적 구조체나 클래스 객체의
	  멤버를 주어진 포인터로 가리키기 위해 합친 것이다.
*/
	struct Record
	{
		int number;
		char grade;
	};

	Record *p;			// Record형의 포인터 변수 p 선언
	p = new Record;		// Record형의 변수를 임의로 생성한 후, 주 소 값을 반환하여 p에 대입
	p->number = 2001;
	p->grade = 'A';		// 값을 할당. (*p).grade = 'A'; 와 완전히 같은 표현!!

	cout << p->number << " " << p->grade << endl;
	delete p;

	cout<<"------------------------------------------------------------------------------" << endl;


/*
	* this 포인터
	
	- 클래스의 멤버 함수를 정의할 때, 호출 객체를 참조하는 것이 필요한 경우가 있다.
	  this포인터는 호출 객체를 가리키는 시스템의 정의 포인터이다.

	- 즉, this는 호출 객체의 이름이 아니라 호출 객체를 가리키는 포인터의 이름이다.
	  this 포인터는 호출 객체의 값을 변경할 수 없으며, 항상 그것을 가리키도록 설정되어 있따.
	  ★특히, 할당 연산자(=)를 오버로딩 할때 자주 사용된다.

	- this 포인터는 호출 객체를 가리키는 포인터이므로, 정적 멤버 변수의 정의에서는 사용할 수 없다.
	  정적 멤버 변수는 this 포인터가 가리킬 수 있는 호출 객체를 가지고 있지 않다.



	* 할당 연산자의 오버로딩

	- 할당 연산자는 일반적으로 반환 값이 void인 함수처럼 사용된다.
	  그러나 시스템 정의 연산자는 참조를 반환하며, 이 연산자는 특수한 목적으로 사용이 가능하다.
	  예를 들어, a = b = c; 의 문장은 a = (b = c); 와 같은 의미를 갖는다.
				  첫 번째, 연산 b = c 는 새로 갱신된 b의 값을 반환하므로,
				  위의 수식은 c의 값이 b와 a에 동시에 설정되는 수식이다.
	  즉, 할당 연산자를 오버로딩 할대도, 오버로드 방식이 이와 같은 방법으로 확실하게 사용되도록 하기 위해,
	  수식의왼쪽 항과 같은 타입을 반환하도록 할당 연산자를 정의하는 것이 필요하다.

	- 할당 연산자를 오버로딩 할때는, 그 클래스의 멤버여야 하며, 그 클래스의 프렌드여서는 안된다.
	  (연산자의 인자 수가 하나뿐인 이유!)
*/
	int i = 1;
	PFArrayD a = PFArrayD(20);
	while(!a.full())
	{
		a.addElement(i+i/100.0);
		i++;
	}
	for(i=0; i<a.getNumberUsed(); i++) cout << a[i] << " " ;
	cout << endl;

	PFArrayD b = PFArrayD(a);									// 복사 생성자의 사용
	for(i=0; i<b.getNumberUsed(); i++) cout << b[i] << " " ;
	cout << endl;

	PFArrayD c = PFArrayD();
	c = a;
	for(i=0; i<c.getNumberUsed(); i++) cout << c[i] << " " ;	// 할당 연산자의 오버로딩 사용
	cout << endl;

/*
	* 얕은 복사와 깊은 복사
	
	- 중복 할당 연산자 또는 복사 연산자를 정의 할 때, 객체의 멤버 변수의 내용을 단순히 복사한다면 '얕은 복사(shallow copy)'라 한다.
	  기본 할당 연산자와 기본 복사 연산자는 얕은 복사를 실행한다.
	  만일, 포인터나 동적 할당 데이터가 포함되지 않는다면 얕은 복사는 잘 동작한다.

	- 멤버 변수가 동적 배열을 가리킬 때는, 일반적으로 얕은 복사를 사용하지 않고 깊은 복사를 사용하게 된다.
	  '깊은 복사(deep copy)'는 동일한 복사이지만 분리되어 있는 복사를 가지기 위하여 각 멤버 변수가 가리키는 것의 복사를 만들게 된다.
	  중복 할당 연산자 또는 복사 생성자를 정의할 때 구현된다.
*/

	return 0;
}


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