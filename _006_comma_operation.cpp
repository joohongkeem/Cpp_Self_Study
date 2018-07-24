#include <iostream>
using namespace std;


// - 콤마 연산자는 여러 식의 리스트를 평가하고 마지막 식의 값을 반환한다.

int main()
{
	
	int result, first, second, third;

	result = (first = 2, second = first + 1);
	cout << result << endl;	// 3 출력
	//
	// 첫번째 식 first = 2 가 평가된 다음,
	// 두번째 식 second = first + 1 이 평가된다.
	// 그리고 할당문에서 가장 마지막에 평가된 값이 왼쪽 변수 result에 저장된다.

	
	// [주의★]
	// - 3개 이상의 식을 콤마 연산자를 통해 연결하려면, 
	//   실행 순서에 주의해야한다. (순서가 중요할 경우, 반드시 괄호로 묶어준다.)
	//
	result = ((first=2, second = first + 1), third = second + 1);
	cout << result << endl;
	//
	// - 괄호를 씌우지 않는다면 third= second + 1이 second = first + 1보다 먼저 계산될 수 있다.


	return 0;
}