#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	// 입력 스트림 선언
	ifstream inputStream;	

	// 디스크의 텍스트 파일에 변수 입력 스트림을 연결
	inputStream.open("./_007_example.txt");

	string firstname, lastname;
	int height;
	double weight;

	inputStream >> firstname >> lastname >> height >> weight ;
	
	cout << "성 : " << firstname<< endl;
	cout << "이름 : " << lastname<< endl;
	cout << "키 : " << height<< endl;
	cout << "몸무게 : " << weight << endl;

	// 입력 스트림을 닫아준다.
	// ★★★★ 한번 닫은 입력스트림을 밑에서 재활용할 수가 없구나!! ★★★★
	inputStream.close();




	puts("-------------------------------------------------------------");

	// ★★★
	// 읽을 데이터가 있는 한 계속 읽어오는 방법 !!

	string text;
	ifstream inputStream2;	
	inputStream2.open("./_007_example2.txt");


	// ★★
	// 읽기가 성공하면 스트림 추출 연산자는 true를 반환하고,
	// 읽기에 실패하면 스트림 추출 연산자는 false를 반환한다.
	//
	while(inputStream2 >> text)
	{
		cout << text << endl;
	}
	inputStream2.close();
	return 0;
}