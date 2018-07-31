#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

const int ARR_SIZE = 10;

void showarray(const int arr[], int size);
//
// 배열의 값을 보여주기만 하는 함수일 뿐, 수정을 하면 안되므로 const로 선언!!
// [주의★] 선언에서 const arr[] 했으면 정의에서도 반드시 const arr[]해야한다 !!!
void showarray(const int arr[][ARR_SIZE], int size);

int main()
{
	int arr[ARR_SIZE];		// 배열의 첨자에는 정수 or 상수 가능!!

	for(int i=0; i<ARR_SIZE; i++)
		arr[i] = i;

	showarray(arr,sizeof(arr)/sizeof(int));		// 배열의 개수만큼을 반환받을때
												// sizeof(배열명)/sizeof(자료형) 을 자주 사용


	int darr[ARR_SIZE][ARR_SIZE];

	for(int i=0; i<ARR_SIZE; i++)
		for(int j = 0; j<ARR_SIZE; j++)
			darr[i][j] = i*ARR_SIZE + j;
	showarray(darr, ARR_SIZE);

	return 0;
}

void showarray(const int arr[], int size)
{
	for(int i=0; i<size; i++)
	{
		cout << "arr[" << i << "] = " << arr[i] << endl;
	}

	//arr[5] = 30;
	//
	// 배열을 const 형태로 선언하였으므로, 값을 수정하는 작업이 있다면 에러 발생!!
}

void showarray(const int darr[][ARR_SIZE], int size)
{
	for(int i=0; i<size; i++)
	{
		for(int j = 0; j<size; j++)
			cout << "darr["<<i<<"]["<<j<<"] = "<<darr[i][j]<<endl;
	}
}