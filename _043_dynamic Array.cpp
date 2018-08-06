#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;


/*
	* 동적 배열 사용하기

	1) 포인터형 정의하기 : 포인터가 가리키는 데이터형과 배열 원소의 데이터형을 동일하게 만든다.
		ex) typedef double* DoubleArrayPtr;

	2) 포인터 변수 선언하기 : 정의된 데이터 타입의 포인터 변수를 선언한다. 
								 포인터 변수는 메모리의 동적 할당 배열을 가리키며, 동적 배열의 이름처럼 사용된다.
		ex) DoubleArrayPtr a;
	
	3) new 연산 호출 : new 연산자를 사용하여 동적 배열을 생성
		ex) a = new double[arraySize];
	> 위의 예처럼 동적 배열의 크기는 대괄호 안에 입력된다.
	  대괄호 안에 입력되는 크기는 정수 변수, 또는 다른 정수 표현으로 주어질 수 있다.

	4) 일반 배열처럼 사용 : 포인터 변수(a)는 일반적인 배열과 같이 사용된다.
							   동적 배열을 가리키는 포인터 변수는 일반적인 배열 변수와 동일하게 사용되어야 하며,
							   다른 포인터 값은 할당되지 않아야 한다.

	5) delete[] 호출 : 프로그램 안에서 동적 할당 배열의 사용이 종료되었으면 포인터 변수와 함께 delete와 대괄호를 사용하여
						동적 배열을 삭제하고, 메모리 공간을 반환하여 재사용하도록 해야한다.
		ex) delete [] a;
*/

typedef int* IntPtr;
const int ARR_SIZE = 100;

int* doubler(int a[], int size);

int main()
{
	int arrsize=100;

	//int arr[arrsize];			// 상수식이 필요하므로 배열의 크기에 변수를 넣을 수는 없다.
	int arr[ARR_SIZE];			// ARR_SIZE는 상수형이므로 배열의 키그로 사용할 수 있다.

	for(int i=0; i<ARR_SIZE; i++) arr[i] = i;

	IntPtr p = arr;
	
	cout << arr[30] << " = " << p[30] << endl;
	//
	// - 배열 변수는 배열으 첫 번째 변수를 가리키는 일종의 포인터 변수
	//   -> int형 포인터 p에 arr의 주소를 할당할 수 있다
	//   -> [★주의사항★] 배열 변수의 메모리 값은 변경시킬 수 없으므로, arr=p는 불가능하다.

	cout<<"-------------------------------------------------------------------------------------------------"<<endl;

/*
	* 동적 배열의 생성과 사용

	- 배열의 크기를 직접 상수로 지정한다면, 
	  배열의 크기가 작을 경우 모든 경우에 동작하지 않게 되고, 너무 크면 메모리 공간이 낭비된다.
	  이러한 경우, 동적 할당 배열을 사용하면 이러한 문제를 피할 수 있다.

    - 동적 할당 배열은 new 연산자를 사용하여 생성된다.
	  동적 할당 배열의 포인터는 배열을 구성하는 각 요소에 대한 포인터와 포인터 형이 같다.
	> new를 호출할 때 동적 할당 배열의 크기는 데이터형 뒤에 나오는 대괄호 안에 입력해야 한다.
	
*/
	arrsize = 200;

	double *dptr = new double[arrsize];

	for(int i=0; i<arrsize; i++)
	{
		dptr[i] = i/1.0+i/1000.0 ;
	}
	cout<<dptr[30]<<endl;

	delete []dptr;
	//
	// ★★★★★★★★★★★★★★★★★★★★★★★★★★★
	// - 포인터 dptr이 가리키는 동적 할당 배열을 삭제하는 과정
	//	 []를 사용하여 '동적 할당 배열 변수'가 삭제될 것임을 알려준다.
	//
	//	 [★주의★]
	//	 delete dptr[]; 이 아니라 delete [] dptr; 이다 !!!

	cout << dptr[30] << endl;
	//
	// 동적배열 dptr이 삭제되었으므로 쓰레기값이 출력된다.


	

	cout<<"-------------------------------------------------------------------------------------------------"<<endl;


/*
	* 배열을 반환하는 함수
	
	- C++에서 배열 타입은 함수가 반환할 수 있는 데이터 형이 아니다.
	  int [] someFunction(); (X)
	> 그러므로, 유사한 함수를 생성하고자 한다면, 함수가 배열의 포인터를 반환하도록 해야 한다.
	  int* someFunction();  (O)
*/
	int sample[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	for(int i=0; i<10; i++) cout << sample[i] << " ";
	cout << endl;

	int *double_sample = doubler(sample, 10);

	for(int i=0; i<10; i++) cout << double_sample[i] << " ";
	cout << endl;

	delete [] double_sample;
	//
	// 프로그램이 종료되므로 여기의 delete문은 반드시 필요하진 않지만, 일반적으로 delete하는 것이 좋다.


	return 0;
}

int* doubler(int a[], int size)
{
	int *temp = new int[size];

	for(int i=0; i<size; i++)
		temp[i] = 2*a[i];
	return temp;
}