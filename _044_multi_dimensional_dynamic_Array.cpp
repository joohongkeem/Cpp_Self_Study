#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


/*
	* 다차원 동적 배열

	- 다차원 배열은 배열의 배열이라는 점을 기억해야 한다.
	  예를 들어, 2차원 동적 배열을 생성하기 위해서는 먼저 int*형 (int형의 1차원 동적 배열에 대한 데이터형)의 1차원 배열을 먼저 생성하고,
	  각 원소에서 int형의 1차원 동적 배열을 생성해야 한다.
*/

typedef int* IntArrayPtr;

int main()
{
	int d1,d2;
	cout << "2차원 배열의 행의 크기 arr[*][ ] : ";
	cin >> d1;
	cout << "2차원 배열의 열의 크기 arr[ ][*] : ";
	cin >> d2;

	IntArrayPtr *m = new IntArrayPtr[d1];			// 행을 먼저 만들어주고(★★★ m은 int형 더블 포인터 ★★★, 뒤에는 int형 포인터)
	for(int i=0; i<d1; i++)
		m[i] = new int[d2];							// 열을 만들어 준다.

		
	for(int i=0; i<d1; i++)
		for(int j=0; j<d2; j++)
			m[i][j] = i*j + j-i;

	for(int i=0; i<d1; i++)
	{
		for(int j=0; j<d2; j++)
				cout << m[i][j] << " ";
		cout<<endl;
	}



	return 0;
}
