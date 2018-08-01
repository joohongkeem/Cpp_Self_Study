﻿#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

/*
	* 기본적인 메모리 관리

	- 자유저장공간(freestore) 또는 힙(heap)이라고 불리는 특수 목적의 메모리 영역이 동적 할당 변수를 위해
	  사전에 확보되어 있다.
	> 프로그램 실행 중에 생성된 모든 동적 변수는 힙 영역의 메모리를 사용한다.
	> 만일 너무 많은 동적 변수를 생성하면, 힙의 모든 메모리를 소비할 수도 있다.
	  힙의 모든 메모리를 소비한 다음에 new 명령어를 호출하였을땐, 컴파일러마다 반응이 다르다.
	  사용 가능한 메모리가 부족할 때, 새로운 동적변수를 생성하려면 new 연산자가 NULL 값을 반환하기도 하고,
	  프로그램을 종료시키기도 한다.
	> 앞의 방식을 사용하는 컴파일러의 경우(대체로 오래된 컴파일러) 아래의 코드를 통해
	  new 연산자가 정상적으로 수행되었는지 확인할 수 있다.
			int *p;
			p = new int;
			if(p==NULL)
			{
				cout << "Error: Insufficient Memory.\n";
				exit(1);		// <cstdlib> 또는 <stdlib.h> 를 포함시켜야 한다.
			}



	* NULL 포인터

	- 상수 NULL의 실제 값은 정수 0이다.
	  But, 프로그래머는 이를 정수 0으로 인식하지 않고, 포인터 변수에 할당할 수 있는 특수한 포인터 값인 NULL로 인식해야 한다.
	> <iostream>과 <cstddef>과 같은 표준 라이브러리에서 NULL 값이 0으로 정의되어 있으므로,
	  NULL포인터를 사용하려면 위와 같은, 또는 적절한 라이브러리를 include 지시자로 포함해야 한다.
	
	- NULL의 실제 값은 0이므로 컴파일 전에 C++ 의 전처리기는 NULL값을 0으로 치환한다.
	  다시 말해, NULL은 어느 네임스페이스내에도 있지 않으며, using 지시자도 필요로 하지 않는다.
	
	- 즉, NULL은 아무것도 가리키지 않는 포인터의 값을 나타내는 특수한 상수 포인터 값이다.
	> NULL은 어떠한 유형의 포인터에도 저장될 수 있다.




	* delete 연산자
	
	- 프로그램이 어느 동적 변수를 더 이상 필요로 하지 않을때, 그 동적 변수가 차지하고 있는 메모리를
	  '힙 메모리 관리자' 에게 되돌려 주기위해 delete연산자를 사용한다.
	> delete 연산자는 동적 변수를 삭제하고, 동적 변수가 사용한 메모리를 '힙 메모리 관리자' 에게 되돌려준다.

		ex) int *p = new int;
				...
			delete p;

		> delete 명령어를 실행한 후, 포인터 변수 p의 값은 미정상태(undefined)가 된다.
		  이러한 미정상태의 포인터를 허상 포인터(dangling pointer)라고 한다.
		  만약, 포인터 p가 허상 포인터이고, p에 역참조 연산자 * 를 적용한다면 그 결과는 예측 불가능하다.
		  허상 포인터를 피하는 한가지 방법은, 모든 허상 포인터를 NULL 값으로 설정하고
		  모든 포인터에 역참조 연산자를 적용하기전에 포인터가 NULL인지 아닌지를 체크하는 것이다.
		 (But, 쉽지않다, Why? 삭제된 동적 변수를 가리키는 모든 포인터를 NULL로 설정해야 하기 때문!!)
	
*/