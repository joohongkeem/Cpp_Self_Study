#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


/*
	* 배열 연산자 [ ] 의 오버로딩

	- 사용자 정의 클래스의 객체에 사용하기 위해 [ ] 를 오버로딩할 수 있다.
	  만약, [ ] 를 할당 연산자의 왼쪽에 사용하고 싶다면 연산자는 참조를 리턴하도록 정의되어야 한다.
	  [ ] 연산자는 멤버 함수로서 오버로딩 되어야 한다.

	- 지금까지 보았던 연산자와 다르기 때문에 [ ] 의 구문을 재검토 하는 것이 도움을 준다.
	  [ ] 는 멤버 함수로 오버로딩됨을 유의하라. ★★
	  식 a[2]에서 a는 호출 객체이고, 2는 멤버 연산자의 인자이다.
	  [ ] 를 오버로딩 할 때, "index" 인자는 enum, char, short, int, long 또는 unsigned 중의 하나인 정수형이 되어야 한다.

*/


/* 
	아래의 코드는 2개의 인덱스 1과 2(0과 1이 아님)를 가지고 문자 배열처럼 행동하는 CharPair 클래스를 정의했따.
	식 a[1]과 a[2]는 배열 인덱스 변수처럼 행동한다.
	오버로딩된 연산자 [ ] 정의를 살펴보면, 참조 리턴하며 그것은 객체가 아니고 멤버 변수를 참조한다는 사실을 알 수 있다.
	멤버 변수를 참조 리턴하는 이유는 멤버 변수가 배열의 인덱스 변수와 유사하기 때문이다.
	a[1]를 변경하면 멤버 변수 first가 변경된다.
	이것은 어떠한 private 멤버 변수에도 접근할 수 있음을 명심하라.
	first와 second가 private 멤버라고 할지라도 fisrt와 second의 이름으로 접근하는 것이 아니라, 
	a[1]과 a[2]의 이름으로 간접 접근하기 때문에 코드는 적합하다.
*/


class CharPair
{
public:
	CharPair() {/*인라인 디폴트 생성자*/}
	CharPair(char firstValue, char secondValue) 
				:first(firstValue), second(secondValue)
	{/*인라인 생성자*/}

	// ★★★★★★★★★★★
	char& operator [](int index);

private:
	char first;
	char second;
};

int main()
{

	CharPair a;
	a[1] = 'A';
	a[2] = 'B';

	cout << "a[1] and a[2] are : " << a[1] << a[2] << endl;

	cout << "Enter Two Letters(No spaces) : " ;
	cin >> a[1] >> a[2] ;
	cout << "Your Input)" << endl;

	cout << "a[1] and a[2] are : " << a[1] << a[2] << endl;

	return 0;
}


char& CharPair::operator [](int index)
{

	// 멤버 변수가 배열 인덱스와 유사하게 동작하기 때문에
	// 클래스의 객체가 아니라 멤버 변수를 리턴함을 명시하라 ★★★★★★★
	if(index == 1) return first;
	else if(index == 2) return second;
	else
	{
		cout << "Illegal index Value.\n" << endl;
		exit(1);
	}

}