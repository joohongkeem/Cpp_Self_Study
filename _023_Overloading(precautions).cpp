#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

/*
	* 함수 호출 연산자 () 오버로딩
	
	- 함수 호출 연산자 ()는 반드시 멤버 함수로서 오버로딩되어야 한다. ★★★★★★★★★★★★★★★★
	> 이 방법은 클래스의 객체를 함수처럼 사용할 수 있게 한다.
	> 만약 AClass에서 정수형을 인자로 가지는 함수 호출 연산자를 오버로딩 하였고,
	  anObject가 AClass의 객체라면, anObject(42)는 호출된 anObject객체와 인자 42를 갖는 오버로드된 () 연산자를 호출한다.
	  리턴형은 void형을 포함하는 나머지 형이 될 것이다
	> 함수 호출 연산자()는 어떠한 인자의 개수를 허용한다는 점에서 보통의 연산자와 다르다.
	  따라서 함수 호출 연산자는 복수의 버전을 오버로딩할 수 있다.


	* &&, ||, 그리고 콤마 연산자의 오버로딩
	
	- 미리 정의된 &&와 ||는 bool형에 대하여 동작하고 짧은 순환 평가를 사용한다.
	  하지만, 오버로딩되어 사용될 떄는 완전 평가로 동작하기 때문에 일반적으로 오버로딩하여 사용하지 않는다.

    - 콤마 연산자 또한 문제점이 있다.
	  일반적인 사용에서 왼쪽에서 오른쪽으로 평가되는데, 오버로딩되어 사용될 경우 이러한 평가를 보장하지 못한다.
	  콤마 연산자 또한 오버로딩을 피해야 하는 연산자이다.

*/

class Distance
{
   private:
      int feet;             
      int inches;          
   public:
      Distance(){
         feet = 0;
         inches = 0;
      }
      Distance(int f, int i){
         feet = f;
         inches = i;
      }
      Distance operator()(int a, int b, int c)
      {
         Distance D;
         D.feet = a + c + 10;
         D.inches = b + c + 100 ;
         return D;
      }
      void displayDistance()
      {
         cout << "FEET : " << feet <<  " INCHES :" <<  inches << endl;
      }
      
};
int main()
{
   Distance D1(11, 10), D2;

   cout << "First Distance : "; 
   D1.displayDistance();

   D2 = D1(10, 10, 10); // invoke operator()
   cout << "Second Distance :"; 
   D2.displayDistance();

   return 0;
}