﻿#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;


int main()
{
/*
	* 포인터(Pointer) : 변수의 메모리 주소이다.

	- 포인터는 주소이며, 주소는 정수이지만, 포인터는 정수가 아니다. (추상화)
	> 포인터를 주소처럼 사용할 것을 허용하지만, 숫자처럼 사용하는 것은 허용하지 않는다.
	> 정수형 변수에 포인터를 저장할 수 없고, 정수형 포인터 변수를 선언해야 포인터를 저장할 수 있다.



	* 포인터 변수 : 포인터는 변수에 저장될 수 있다. ( * : 역참조 연산자(dereferenceoperator) )
		ex) int *pa, *pb;
			double *dpa, *dpb;

	  But, 위와 같은 표기는 *를 빠뜨릴 수도 있으므로, 아래와 같은 표기법을 많이 사용한다.
		ex) typedef int* IntPtr;
			typedef double* DoublePtr;
			IntPtr pa, pb;
			DoublePtr dpa, dpb;
	
	* 포인터형은 다른 데이터형과 동일한 방법으로 사용 가능하다.
	> 함수의 인자로 포인터형을 사용할 수 있으며, 포인터형 데이터를 반환할 수 있다.
		ex) int* findOtherPointer(int* p);
		> 위의 코드는 정수에 대한 포인터를 인자로 갖고 있으며, 결과 값으로 정수의 포인터를 반환한다.
		
*/
	int *p1;
	int v1 = 150;			// & : 주소 연산자(address of operator)
	p1 = &v1;				// 기호 &은 변수의 주소 값을 나타내는데 사용되며, 
							// 함수 선언에서 call-by-reference 인자임을 명시하는데 사용된다.
	cout << v1 << endl;
	*p1 = 200;
	cout << v1 << endl;

	cout << "---------------------------------------------------------------------------------------------" << endl;

/*
	* new 연산자

	- new 연산자는 새로운 이름 없는 변수를 생성하고, 그 변수를 가리키는 포인터를 반환한다.
	> new 연산자 다음에 데이터 유형을 적어서 이름 없는 변수의 유형을 명시한다.

	- new 연산자로 생성되는 변수는 프로그램이 실행되는 동안 생성되고 반환되므로 
	  '동적 할당 변수(dynamically alloacted variables)' 또는 '동적 변수(dynamic variale)'라 한다.

	- new 연산자를 사용하여 클래스형 동적 변수를 생성할 때, 그 클래스의 생성자가 호출된다.
	  만약, 생성자를 명시하지 않았다면, 기본 생성자(default constructor)가 호출된다.
	  즉, 다음의 문장은 기본 생성자를 호출한다.
			SomeClass *classPtr;
			classPtr = new SomeClass;			// 기본 생성자 호출
			classPtr = new SomeClass(32.0, 18);	// SomeClass(double, int) 호출

	  위와 같은 방법으로, 동적 변수를 초기화할때도 비슷한 표기법을 사용할 수 있다.
			double *dPtr;
			dPtr = new double(98.6);			// *dPtr을 98.6으로 초기화
*/

	
	cout << "---------------------------------------------------------------------------------------------" << endl;

	// 연습문제1. 다음 코드의 출력을 적어보자.

	int *np1, *np2;
	np1 = new int;
	np2 = np1;										// int 형 동적변수를 하나 만들고, np1과 np2는 그걸 가리킴
	*np2 = 1000;									// np2가 가리키는 변수에 1000대입

	cout << *np1 << " " << *np2 << endl;			// 1000 1000 출력

	np1++;											// int형이므로 p1의 값 4증가, 다음 다음 메모리주소 가리킴
	*np1 = 555;
	cout << *np1 << " " << *np2 << endl;			// 555 1000 출력

	*np2 = 333;
	cout << *np1 << " " << *np2 << endl;			// 555 333 출력

	cout << "---------------------------------------------------------------------------------------------" << endl;

	// 연습문제2. 다음 코드의 출력을 적어보자.

	int *pp1 = new int, *pp2 = new int;
	*pp1 = 111;
	*pp2 = 222;

	cout << *pp1 << " " << *pp2 << endl;			// 111 222 출력

	*pp1 = *pp2 = 1234;
	cout << *pp1 << " " << *pp2 << endl;			// ★★★ (x=y=z)는 (x=(y=z))와 같다. ★★★★★★★★★★★★★★★★★★★★
													// cout << (*pp2 = 1234) << endl; 를 하면 1234 출력!!! ( ) 꼭 씌워야 함
													// 1234 1234 출력
	pp1 = pp2;
	cout << *pp1 << " " << *pp2 << endl;			// 1234 1234 출력

	pp2++;
	(*pp1)++;
	cout << *pp1 << " " << *pp2 << endl;			// 1235 쓰레기값 출력

	return 0;
}