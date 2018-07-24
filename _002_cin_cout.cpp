// 간단한 콘솔 입/출력 프로그램을 작성하기 위해서는 iostream 라이브러리에 정의된
// cin, cout, cerr 객체를 활용하면 된다.
//
#include <iostream>
#include <string>
using namespace std;


int main()
{

	// 문자열을 출력하라 수 있다.
	cout << "Hello World!\n" << "Welcome to C++.\n";


	// 변수의 값을 출력할 수 있다.
	int man = 11;
	cout << man << "guys are playing Soccer now.\n";


	// 산술식도 표현이 가능하며, endl을 통해 줄바꿈을 할 수 있다.
	int a = 10, b = 20;
	cout << "10 + 20 = " << a + b << endl;


	// 2개의 string형 변수 사이에 '+'기호를 사용하여 하나의 스트링 변수로 합성할 수 있다.
	// [주의] 반드시, #include <string> 을 해줘야 한다.
	string s1 = "Happy", s2="Birthday";
	cout << s1+s2 << endl;

	puts("-------------------------------------------------------------------------------------");

	double x = 19.9000000;
	cout << x << endl;			// 19.9 출력

	// ★
	// 이 세 문장을 입력하면, 이 다음에 표현된 cout문장은 정확히 소수점 이하 3개의 숫자표현
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(3);

	cout << x << endl;			// 19.900 출력

	
	puts("-------------------------------------------------------------------------------------");

	
	int _int;
	char _char;
	double _double;

	cout << "정수, 문자, 실수 입력 : ";
	cin >> _int >> _char >> _double;
	cout << "입력값 : " << _int << "," << _char << "," << _double << endl;







	return 0;
}