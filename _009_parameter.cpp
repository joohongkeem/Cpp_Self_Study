#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

// 1. Call-by-Value 함수
void VswapValue(int a, int b);
void VshowValues(int a, int b);
void VgetValue(int a);


// 2. Call-by-Reference 함수
//
// - 형식 매개변수를 call-by-reference 매개변수로 만들기 위해서 형 이름에 &를 덧붙인다
// - 함수 호출 시 대응하는 인자는 변수여야만 하고, 상수나 식은 안된다
// - 함수가 호출될 때 대응하는 변수 인자(값이 아닌)는 형식 매개변수로 대체된다.
// - 함수 몸체에 있는 형식 매개변수에 생긴 변화는 함수가 호출될 때 인자 변수에도 적용된다.
//
// ★★ C언어와 아주 다른 구조를 갖고 있다!!
//
void RswapValue(int &a, int &b);
void RshowValues(int a, int b);
void RgetValue(int &a);

int main()
{
	int a=0, b=0;

	cout << "# Call-by-value 함수"<<endl;
	VgetValue(a);
	VgetValue(b);
	VshowValues(a,b);
	VswapValue(a,b);
	VshowValues(a,b);

	cout << "# Call-by-reference 함수"<<endl;
	RgetValue(a);
	RgetValue(b);
	RshowValues(a,b);
	RswapValue(a,b);
	RshowValues(a,b);
	return 0;
}


void VswapValue(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
void VshowValues(int a, int b)
{
	cout << "a = " << a << ", b = "<< b << endl;
}
void VgetValue(int a)
{
	cout << "숫자 입력 : ";
	cin >> a;
}


void RswapValue(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void RshowValues(int a, int b)
{
	cout << "a = " << a << ", b = "<< b << endl;
}
void RgetValue(int &a)
{
	cout << "숫자 입력 : ";
	cin >> a;
}