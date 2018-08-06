/*
	* 파생 클래스의 할당 연산자와 복사 생성자

	- 오버로딩된 할당 연산자와 생성자는 상속되지 않는다.
	  그러나 파생 클래스에서 오버로딩된 할당 연산자와 복사 생성자의 정의에서는 이들을 사용할 수 있으며, 대부분 사용하여야 한다.
	  파생 클래스에서 할당 연산자를 오버로딩할 때 일반적으로 기반 클래스의 오버로딩된 할당 연산자를 사용한다.
	  이해를 돕기 위해, 오버로딩된 할당 연산자는 클르새의 멤버 함수처럼 정의되어야 한다는 것을 기억하자.

	  예를들어, 만약 클래스 Derived가 클래스 Base로부터 파생되었다면, 클래스 Derived의 오버로딩된 할당 연산자의 정의는
				 일반적으로 다음과 같이 시작할 것이다.

				Derived& Derived::operator = (const Derived& rightSide)
				{
					Base::operator =(rightSide);
					...
				}

	  정의의 몸체 부분의 첫 번재 라인은 클래스 Base의 할당 연산자를 호출하는 것이다.
	  이것은 상속된 멤버 변수와 데이터를 처리한다.
	  그리고 오버로딩된 할당 연산자의 정의는 클래스 Derived의 정의에 새로운 멤버 변수를 설정한다.


	- 파생 클레스에서 복사 생성자를 정의할 때에도 비슷한 상황이 발생한다.
	  만약 클래스 Derived가 클래스 Base의 파생 클래스라고 한다면, 클래스 Derived의 복사 생성자는 일반적으로
	  클래스 Base로부터 상속받은 멤버 변수와 저료를 설정하기 위해 클래스 Base의 복사 생성자를 이용한다.
	  소스코드는 일반적으로 다음과 같이 시작할 것이다.
				Derived::Derived(const Derived& Object )
										: Base(Object), (다른 초기화들....)
				{
					...
				}

	  기반 클래스의 복사 생성자 Base(Object)의 호출은 생성되고 있는 Derived 클래싀 객체의 상속받은 멤버 변수를 설정한다.
	  Object는 Derived형이므로 Base형이기도 하다. 따라서 Object는 클래스 Base의 복사 생성자에 적법한 인자이다.



	* 파생 클래스의 소멸자
	
	- 기반 클래스가 완벽하게 동작하는 소멸자를 가지고 있따면, 기반 클래스로부터 파생된 클래스의 소멸자를 매우 쉽게 정의할 수 있다.
	  파생 클래스의 소멸자가 호출되면 기반 클래스의 소멸자가 자동으로 호출된다.
	  이 동작은 항상 자동으로 이루어지기 떄문에, 기반 클래스의 소멸자를 호출하는 구문을 일부러 작성할 필요는 없다.
	  그러므로 파생 클래스 소멸자는 파생 클래스에서 새로 추가된 멤버 변수와 그들이 가리키는 자료들에 대해 delete 키워들 사용하는 것만
	  고려하면 된다.
	  상속된 멤버 변수에 대해 delete를 호출하는 것은 기반 클래스 소멸자의 일이다.
	  
	  클래스 B가 클래스 A로부터 파생되었고, 클래스 C가 클래스 B로부터 파생되었다고 가정하자.
	  클래스 C의 객체가 유효하지 않게 되면 먼저 클래스 C의 소멸자가 호출되고 클래스 B의 소멸자가 호출된 다음 마지막으로 클래스 A의 소멸자가 호출된다.
	  소멸자의 호출 순서는 생성자 호출 순서의 역순임을 기억하자!!
	  
*/


/*
	* protected와 private 상속

	- 지금까지는 파생 클래스를 정의할 때, 클래스 헤더에 public 키워드를 다음과 같이 사용하였다.
			
			class SalariedEmployee : public Employee
			{
				...
			};
	
	- 만약 다음과 같이 protected 키워드를 사용하여 상속한다면, public인 멤버들은 상속된 파생 클래스에서는 protected가 된다.

			class SalariedEmployee : protected Employee
			{
				...
			};

	- 만약 다음과 같이 private 키워드를 사용하여 상속한다면, 기반 클래스의 모든 멤버들은 파생 클래스에서 접근할 수 없다.
	  즉, 모든 멤버들이 기반 클래스에서 private였던 것처럼 상속된다.

	  		class SalariedEmployee : private Employee
			{
				...
			};
	
	- 또한 protected와 private 상속을 하게 되면 파생 클래스의 객체는 기반 클래스형의 인자로 사용될 수 없다.
	  즉, 만약 Derived가 Base로부터 protected 또는 private으로 상속되면 Derived형의 객체는 더이상 Base형의 객체가 될 수 없다.
	  즉, "is a" 관계는 protected와 private상속에서는 적용되지 않는다.
	  (즉, 잘 사용되지 않을뿐더러, 다른 방법으로도 그 목적을 충분히 달성할 수 있다.)
	> protected와 private상속은 public상속에 대해 설명했던 것을 생각하면 더이상 상속이 아니다.

	[참고]
	- "is a" 관계 : 상속의 관계
	- "has a" 관계 : 클래스를 멤버변수로 갖는 관계
	

*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "_050_pfarraydbak.h"

using namespace std;

void testPFArrayDBak();				// 클래스 PFArrayDBak의 테스트를 수행한다.

int main()
{
	cout << "이 프로그램은 PFArrayDBak 클래스를 확인하는 프로그램이다. " << endl;
	char ans;

	do
	{
		testPFArrayDBak();
		cout << "테스트를 계속 할까요? (y/n) : " ;
		cin >> ans;
	}while((ans=='y') || (ans=='Y'));


	return 0;
}

void testPFArrayDBak()
{
	int cap;
	cout << "원본 배열의 크기를 입력하세요 : " ;
	cin >> cap;
	PFArrayDBak a(cap);

	cout << cap << "개의 배열이 생성되었습니다." << endl;
	cout << "숫자를 입력하세요.(음수를 입력하면 종료)" << endl;

	double next;
	cin >> next;

	while((next>=0) && (!a.full()))
	{
		a.addElement(next);
		cin >> next;
	}

	if(next >= 0)
	{
		cout << "모든 숫자를 입력할 수 없습니다." << endl;
		while (next>=0) cin >> next;	// 아직 읽지 않은 입력들을 지운다.
	}
	
	int count = a.getNumberUsed();

	cout << count << " 개의 숫자들이 저장되었습니다."<<endl;
	int index;
	for(index=0; index<count; index++)
		cout << a[index] << " " ;
	cout<<endl;

	cout << "배열을 백업합니다. " << endl;
	a.backup();
	cout << "배열을 삭제합니다. " << endl;
	a.emptyArray();

	cout << a.getNumberUsed() << " 개의 숫자들이 저장되어 있습니다." << endl;

	cout << "배열을 복원합니다. " << endl;
	a.restore();

	count = a.getNumberUsed();
	cout << count << " 개의 숫자들이 저장되었습니다."<<endl;
	for(index=0; index<count; index++)
		cout << a[index] << " " ;
	cout<<endl;
}