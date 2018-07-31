#define _CRT_SECURE_NO_WARNINGS

//★★ #define NDEBUG 가 있으면 assert를 무시한다. 
//	-> 단, 반드시 #include 전에 #define NDEBUG 를 선언해야한다.!!!
//
#define NDEBUG
#include <iostream>
#include <cassert>


using namespace std;

int main()
{
	int width,height;

	cout << " 너비와 높이 입력 : " ;
	cin >> width >> height;

	// assert문에 bool식을 넣음으로써 조건이 참 인지 거짓인지 알 수 있다.
	assert(width>=0 && height>=0);
	cout << "넓이 : " << width * height << endl;
	// 
	// 위의 코드는 너비와 높이에 0보다 작은수가 들어가면,
	// 프로그램을 끝내고 오류메시지를 보낸다.



	/* 
	* 스터브와 드라이버
	- 드라이버 프로그램 : 프로그램을 테스트하기 위한 특별한 프로그램
	  ex) double unitPrice(int diameter, double price)
		  {
		    return (9.99);
		  }
	      -> 스터브 : 테스트 되지 않은 프로그램을 
			           드라이버 프로그램으로 사용하기 위해서 단순화한 함수.

	*/
	return 0;
}