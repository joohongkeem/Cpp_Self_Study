#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
// 벡터는 vector 라이브러리에 정의되어 있으며, 
// 이 라이브러리는 벡터를 std네임스페이스에 두고 있다!!
//
#include <vector>		
using namespace std;


/*	★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★
	* 벡터(vector)

	- 프로그램이 실행되는 동안 길이가 커지거나 줄어드는 배열로 생각할 수 있다.
	> C++에서는 일다나 프로그램이 배열을 생성하면, 길이를 변경할 수 없지만
	  벡터는 이게 가능하다!!
		-> 실행되는 동안 길이를 변경하라 수 있다는 점을 제외하면 배열과 같은 목적으로 사용!!

	- 벡터는 STL(표준 템플릿 라이브러리)에 있는 템플릿 클래스로부터 형성된다.

	- 벡터는 배열처럼 기본형이며, 배열처럼 자신의 기본형에 해당하는 여러 값을 저장한다.
	  기본형이 int인 벡터를 위한 변수v는 다음과 같이 선언한다.
			-> vector<int> v;
	  
	> vector<Base_Type> 이란 표현은 '템플릿 클래스(template class)임을 나타낸다.
	  즉, Base_Type으로 어떤 형을 집어 넣으면 이 Base_Type을 기본형으로 갖는 벡터를 위한 
	      클래스가 만들어질 것임을 읨히나다.
	> 벡터의 기본형은 클래스형을 포함해서 어떤 형이라도 사용할 수 있다.
	  vector<int>란 표현은 클래스 이름을 나타낸다.
	  즉, v를 vector<int> 형의 벡터로 선언한 것에는 (원소가 없는) 빈 벡터 객체를 생성하는
	      vector<int> 클래스의 디폴트 생성자 호출이 포함되어 있다.
    > 벡터의 원소들은 배열과 같이 0으로 시작하는 인덱스를 가진다.
	  배열처럼 대괄호를 사용한 표현으로 원소를 읽어오거나 변경할 수 있다.
	
	> [★★★주의사항★★★]
		- v[i] 을 이용하여 벡터 v[i]의 값을 변경할 수는 있지만,
		  v[i] 를 이용하여 i번째 원소를 초기화 할 수는 없다
		  >> 이미 값을 갖고 있는 원소를 변경하는것만 가능하다. ★★★★

		- 처음으로 벡터에 원소를 추가할 때는 보통 push_back이란 멤버 함수를 사용한다.
		  벡터에 원소를 추가할 때는 0번 위치, 1번 위치, 2번 위치, 등 의 순서대로 추가한다.
		  push_back 함수는 가능한 다음 번 위치에 원소를 추가한다.
			ex)
			vector<double> sample;
			sample.push_back(0.0);
			sample.push_back(1.0);
			sample.push_back(2.0);
					>> sample 벡터의 0, 1, 2번째 원소에 초기 값을 부여한다.
					   이 이후로는 sample[i] 를 이용하여 값을 변경할 수 있다.
					   (초기화 전에 sample[0] = 0.0을 하는 작업은 불가능!!! ★★★)


   > 벡터에 있는 원소의 수를 벡터의 크기(size) 라고 한다.
     size 멤버 함수를 사용하여, 벡터에 몇개의 원소가 있는지 확인할 수 있다!
	 위의 예시에서 sample.size()를 호출하면 3을 리턴할 것이다.
	 [주의사항★]
		- size함수는 int형 값이 아니라 unsigned int 형값을 리턴한다.
		  매우 안전하게 하고 싶다면, 주의하여 적절한 형을 사용해주면 된다.
			ex) for(int i=0; i<sample.size(); i++) 보다는
				for(unsigned int i=0; i<sample.size(); i++)을 사용하는게 더 좋다!!!

	★★★★★★
	> vector<int> v(10); 으로 v를 선언하다면, 
	  처음 10개의 원소는 0으로 초기화되고, v.size()는 10을 리턴할 것이다.
	  (정수 인자를 가진 생성자를 사용하면, 수치를 갖는 벡터는 이 수치형의 0으로 초기화)
	  또한, 이 이후엔 0부터 9까지의 i값에 대해 v[i]를 사용하여 i번재 원소의 값을 설정가능함!

*/

class DayofYear
{
public:
	DayofYear(int newmonth, int newday);
	DayofYear();
	
	// 클래스 벡터를 확인해보기 위해 멤버변수를 public으로 선언함
	//
	int month;
	int day;
};
class SpecialDay
{
public:
	SpecialDay();

	// 클래스 벡터를 확인해보기 위해 멤버변수를 public으로 선언함
	//
	char datename[20];
	DayofYear date;
};

int main()
{
	vector<int> v(10);

	for(unsigned int i=0; i<v.size(); i++)	// v.size()가 unsigned int 이므로 i도 형을 맞춰준다.
	{
		cout << v[i] << endl;
	}
	cout << v.size()<< endl;	// 10 출력
	//
	// 기본적으로 10개의 벡터가 0으로 초기화 되어있음


	//for(unsigned int i=0; i<v.size(); i++)
	//{
	//	v.push_back(i+1);
	//}
	//
	// 이렇게 하면 v.size역시 계속 증가하므로, 무한루프에 빠진다.
	
	for(unsigned int i=0; i<10; i++)
	{
		v.push_back(i+1);
	}
	cout << v.size() << endl;	// 20 출력
	//
	// 10개의 벡터가 추가된다.

	for(unsigned int i=0; i<v.size(); i++)
	{
		v[i] = i+100;
		cout << v[i] << endl;
	}
	cout << v.size()<< endl;	// 20 출력
	//
	// 20개의 벡터의 값을 변경하고 출력한다.
	

	cout<<" -----------------------------------------------------------------------------------------------\n";
	
	// 생성자를 이용하여 joohongbirth 객체 생성
	//
	DayofYear joohongbirth(12,8);

	SpecialDay date1;
	date1.date = joohongbirth;
	strcpy(date1.datename, "주홍 생일");

	// 클래스를 타입으로 갖는 벡터역시 선언할 수 있다.
	//
	vector<SpecialDay> vdate;

	vdate.push_back(date1);
	
	// 벡터에 값이 정확하게 들어갔는지 확인한다.
	//
	cout << "Month : " <<vdate[0].date.month <<endl;
	cout << "Day : " <<vdate[0].date.day <<endl;
	cout << "datename : " <<vdate[0].datename <<endl;

	// 벡터를 이용하여 값을 수정할 수 있다.
	//
	vdate[0].date.month = 3;
	vdate[0].date.day = 12;
	strcpy(vdate[0].datename, "은지 생일");
	
	cout << "Month : " <<vdate[0].date.month <<endl;
	cout << "Day : " <<vdate[0].date.day <<endl;
	cout << "datename : " <<vdate[0].datename <<endl;


	
	return 0;
}


DayofYear::DayofYear(int newmonth, int newday):month(newmonth), day(newday)
{

}
DayofYear::DayofYear()
{

}
SpecialDay::SpecialDay()
{

}


/*
	* 효율성 문제
	- 벡터는 현재 할당된 메모리에 저장할 수 있는 원소의 수인 용량(capacity)를 갖고 있다.
	> capacity() 멤버 함수를 사용하면 벡터의 용량을 알 수 있다.
		[★주의사항★]
		- 벡터의 용량과 벡터의 크기를 혼동해서는 안된다
			> 벡터의 크기 : 벡터에 포함된 원소 수
			> 벡터의 용량 : 할당되어 있는 메모리에 저장될 수 있는 원소의 수
			(벡터의 용량은 언제나 벡터의 크기보다 크거나 같다)

	- 벡터가 현재 용량을 다 사용해서 새로운 원소를 저장할 공간이 필요하게 되면
	  언제든 자동으로 용량이 증가된다.
	> 정확한 증가량은 구현 방법에 따라 다르지만, 
	  흔히 사용되는 구현 방법은 필요할때마다 2배로 증가시키는 것이다.
	  (용량을 증가시키는 것은 복잡한 작업이므로, 작은 단위보단 큰 단위로 증가시키는것이 좋다)
    
	- 벡터의 용량에 대해선 전혀 신경 쓸 필요가 없으며, 
	  용량은 프로그램이 수행되는데 어떤 영향도 미치지 않을 것이다.
	  But, 효율성이 문제가 된다면 용량이 더 필요할때마다 무조건 2배로 증가시키지 않고
	       스스로 용량에 대해 관리할 수 도 있다 ---> reserve() 멤버함수
		   ex) v.reserve(32);
				-> 벡터의 용량이 최소한 32개 원소가 되도록 지정
			   v.reserve(v.size() + 10);
			    -> 벡터의 용량을 현재 원소 수보다 최소한 10개가 더 많도록!

	  또한, resize() 멤버함수를 통해 벡터의 크기를 변경할 수 있다.
			ex) v.resize(24); 
				-> 벡터의 크기가 24개의 원소로 조정된다.
				   이전의 크기가 24보다 작다면, 새로운 원소들이 초기화 된다.
				   이전의 크기가 24보다 크다면, 처음 24개를 제외하고 나머지는 모두 잃게 된다.
*/