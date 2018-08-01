#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
using namespace std;



void newLine();
void getInt(int &number);

int main()
{

/*
	* get 멤버 함수
	
	- get 함수를 사용하면 하나의 문자를 입력하여 char형 변수에 저장할 수 있다.
	  입력 파일 스트림 또는 cin 스트림 종류에 상관없이 모든 입력 스트림은 get이라는 멤버 함수를 보유하고 있다.
	  지금까지 cin 객체는 문자입력(또는 다른 종류의 입력)을 위하여 >> 연산자를 사용하였다.
	  이 경우, 공백 읽기를 생갹하는 등의 일련의 작업들이 자동적으로 발생한다.
	  But, 경우에 따라서는 공백을 생략하고 싶지 않은 경우가 발생할 수 있다.
		   cin의 멤버 함수 get을 사용하여 cin.get으로 문자를 읽는 경우, 그 문자가 공백 여부와는 상관없이 무조건 읽어들이게 된다.

	- get 멤버 함수는 1개의 인자가 반드시 필요한데, 반드시 char형의 변수여야 한다.
	  이 인자는 입력 스트림에서 읽어 들인 입력 문자를 받아들인다.
	
	>> 아래와 같은 방식으로 코드를 작성하면 어떤 문자라도 입력이 가능하다.
	   만약에 입력문자가 공백이라면, 아무런 문제 없이 공백을 읽게 되고,
	   개행문자가 오는경우, 아무런 문제없이 개행문자가 char형 변수에 들어가게 된다.
	   get 멤버 함수를 이용하면, 라인의 끝부분을 찾을 수 있는데, 
	   예를 들어 다음과 같은 루프 프로그램은 라인에 존재하는 데이터를 읽다가 개행문자 다음 부분에서 입력이 중단된다.

	( get 함수를 통해 파일을 읽어올 수도 있다, 이 경우, cin 스트림 대신에 입력 파일 스트림을 사용하면 된다.)
*/
	cout << "Enter a line of input : ";
	char symbol;
	do
	{
		cin.get(symbol);
		cout<<symbol;
	}while(symbol!='\n');
	
/*
	* put 멤버 함수
	
	- put 멤버 함수는 입력 대신 출력을 위하여 사용된다는 점을 제외하고는 get 멤버함수와 유사하다.
	  즉, put 함수는 하나의 문자를 출력한다.
	  cout.put 멤버 함수는 char형 변수 또는 문자 상수와 같은 char형의 식으로 표현되는 인자를 지닌다.
	  예를 들어 cout.put("a"); 와 같은 코드는 'a' 문자를 화면에 출력한다.
	
	- cout.put 함수는 << 연산자를 이용하여 수행할 수 없는 부분에 대해서는 아무런 작업을 실행할 수 없다.
	  ( 출력스트림에 put함수를 사용하여, 텍스트 파일을 출력할 수 있다.)
*/



/*
	* newline 함수를 이용한 입력 확인
	- getInt() 함수는 입력되는 데이터가 옳은지 여부를 판단, 입력데이터가 잘못되었으면 새로운 값을 입력하라고 지시함.
	- newLine() 함수는 현재 라인에 남아 있는 문자들을 읽는 작업을 수행하지만, 실제로 아무런 처리를 하지 않는다.
	  >> 버퍼를 비우는 것과 같다!!
*/

	int n;
	getInt(n);
	cout << "Final value read in = " << n << endl
		<< "# End of Program.\n";


	return 0;
}

// ★★★★★★★★★★★★★★[자주 활용할 수 있는 함수들]★★★★★★★★★★★★★★★
// 현재 입력 라인에 남아 있는 모든 입력 데이터를 생략한다.
// 라인 끝에 위치한 '\n\문자 입력을 생략한다.
//
void newLine()
{
	char symbol;
	do
	{
		cin.get(symbol);
	} while(symbol != '\n');

	// 
	// ★★★★
	// 위처럼 코드를 짜야, '\n'까지 생략시킬 수 있다!!
}

// number 변수에 사용자가 입력한 값을 할당한다.
//
void getInt(int &number)
{
	char ans;
	do
	{
		cout << "Enter input Number : " ;
		cin >> number;
		cout << "You entered '" << number
			<< "', Is that correct? (Yes/No) : " ;
		cin >> ans;
		newLine();
	} while( (ans == 'N') || (ans == 'n'));
}
