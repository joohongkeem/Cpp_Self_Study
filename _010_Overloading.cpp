#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

/*	
	* 오버로딩(Overloading)
	- 같은 함수 이름으로 두 가지 이상의 함수 정의가 주어지는 것
	- 함수 호출 시에, 컴파일러는 함수 호출의 인자와 일치하는
	  형식 매개변수의 개수와 형을 가지는 함수 정의를 사용한다.
	- (★)단, 반환되는 값의 형만 다른 2개의 정의로 함수 이름을 오버로딩 할 수 없다
	  또한, 매개변수의 개수나 형이 아닌 다른 것을 기반으로 오버로딩할 수 없다.

	-> 즉, 정리하자면 컴파일러에서의 다중 오버로딩된 함수의 선택 기준은
		1) 정확한 일치
		- 인자의 개수와 형이 정확하게 (자동 형 변환 없이) 정의와 맞는다면 그 정의를 선택
		2) 자동 형 변환을 사용한 일치
		- 만일 정확하게 일치하지 않지만, 자동 형 변환을 사용하여 일치된다면 그 정의를 사용


*/

double avg(int a, int b);
double avg(int a, int b, int c);
										// ★★★★★★★★★★★★★★★★★★★★★★★★★★
double dev(double a, double b=4);		// b가 주어지지 않는다면 default로 4를 사용한다!!!★★★
										// - default인자는 함수의 선언에서 주어진다!!! (정의x)★★★
										// - 하나 이상의 default인자를 가질 수 있지만,
										// - 모든 default 인자는 가장 오른쪽이여아 한다★★★★★★
										// - 생략된 인자는 가장 오른쪽의 인자라고 생각한다!!!!
										// double dev(double a, double b=3, double c= 4)라이고
										// dev(2,3)이라고 쓰면, 자동으로 c=4로 생각!!
										// -> 세번째인자를 생략하지않고, 두번째 인자를 생략할순 없다
int dev(int a, int b);

int main()
{
	cout << avg(3,4) << endl;
	cout << avg(3,4,5) << endl;

	int a= 60, b= 2;
	cout << dev(a,b) << endl;
	cout << dev(a) << endl;				// b가 주어지지 않는다면 default로 4를 사용한다!!!★★★
	/* 
	int a = 3, int b = 2; 가 정의되어있을때,
	int dev(int a, int b) 함수가 없는 상태에서 dev(a,b)를 호출하면,
	a와 b가 자동형변환으로 인해 3.0, 2.0으로 형변환하여 1.5가 출력된다
	But, int dev(int a, int b) 함수가 정의되어 있다면,
	그 함수가 호출되서 1이 출력된다.
	*/

	return 0;
}
double avg(int a, int b)
{
	return (a+b)/2.0;
}

double avg(int a, int b, int c)
{
	return (a+b+c)/3.0;
}
double dev(double a, double b)
{
	return a/b;
}
int dev(int a, int b)
{
	return a/b;
}