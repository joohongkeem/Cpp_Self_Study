#include <iostream>
using namespace std;

/*

 - 나열형(enumeration type)은 정수형 상수 리스트에 의해서 정의되는 값을 가진다.
   > switch문의 case 레이블에서 사용되는 식별자 리스트를 정의하는데 매우 편리하다.

   ★
 - 나열형의 상수들이 정수 값을 가지고 많은 경우 정수와 같이 취급되지만,
   나열형은 정수형과 다른 유형이며, 정수형과는 다르게 취급되어야 한다.
   나열형을 레이블로 사용하고, 나열형 변수를 사용하여 산술 계산을 하는 것을 피해야 한다.
*/

int main()
{
	enum MonthLength {Jan = 31, Feb = 28, Mar = 31, Apr = 30, May = 31, Jun = 30,
		Jul = 31, Aug = 31, Sep = 30, Oct = 31, Nov = 30, Dec = 31};

	cout << Jan << endl;
	cout << Dec << endl;			// 나열형의 둘 이상의 상수가 동일한 정수 값을 가질 수 있다.


	enum Direction {NORTH,SOUTH,EAST,WEST};
	
	cout << NORTH << endl;
	cout << SOUTH << endl;
	cout << EAST << endl;
	cout << WEST << endl;			// 자동으로 0, 1, 2, 3이 할당된다.

	
	enum MyEnum { ONE = 17, TWO, THREE, FOUR = -3, FIVE};

	cout << ONE << endl;		// 17
	cout << TWO << endl;		// 18
	cout << THREE << endl;		// 19
	cout << FOUR << endl;		// -3
	cout << FIVE << endl;		// -2


	return 0;
}