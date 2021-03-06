﻿#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

/*
	* 분리 컴파일

	- C++은 하나의 프로그램을 분할하여 별개의 파일에 나누어 저장하고,
	  각기 컴파일 한 후에, 프로그램이 실행될 때 서로 링크할 수 있는 기능을 가지고 있다.
	  이러한 방법을 사용하면, 클래스의 정이를 해당 클래스를 사용하는 프로그램과 분리된 파일안에 위치시킬 수 있다.
	  즉, 클래스 라이브러리 생성이 가능하며, 여러 프로그램이 같은 클래스를 사용하는것이 가능해진다.



	* 캡슐화

	- 캡슐화의 원리는 클래스 구현과 세부 사항과 클래스가 프로그래머에 의해 어떻게 사용되는지에 대한 명세를 분리시키는 것이다.
	  이러한 분리는 클래스를 사용하는 프로그램의 어떠한 수정 없이도 구현의 수정이 완벽하게 가능해야 한다.
	  분리를 보장하기 위한 3가지 규칙은 다음과 같다.
		1) 멤버 변수들은 모두 클래스의 비공개(private) 변수로 작성한다.
		
		2) 클래스의 기본 연산을 공개 멤버 함수, friend함수, 일반 함수, 또는 오버로드 함수 중 하나로 작성한다.
		   클래스의 정의, 함수 및 연산자 선언들을 모아 그룹을 만든다.
		   이 것이 동반하는 주석에 따라서 이러한 그룹을 클래스의 '인터페이스(interface)'라고 한다.
		   이러한 클래스(prototypes) 함수 및 연산자 선언에 주석을 달아서 각각의 함수 및 연산자의 사용 방법을 완벽히 설명한다.

		3) 클래스 사용 프로그래머에게는 기본 연산의 '구현(implementation)' 사항을 사용할 수 없게 해야 한다.
		   기본 연산의 구현 사항은 어떠한 도움을 주는 함수나 이러한 정의들을 필요로 하는 추가적인 사항에 따라
		   함수의 정의 및 오버로드 연산자 정의로 구성된다.

	- 이러한 규칙을 잘 따르기 위해서는 인터페이스 부분과 클래스 구현 부분을 서로 다른 파일에 저장하는 것이 좋다.
	  인터페이스를 저장하는 파일을 '인터페이스 파일', 구현을 저장하는 파일을 '구현 파일' 이라고 한다.



	* 헤더파일과 구현파일

	- dtime.h 에는 class를 정의한다.
	  이 파일은 파일의 인터페이스를 포함하며, 확장자 .h는 이 파일이 '헤더파일'임을 나타낸다.
	  이 클래스를 사용하는 모든 프로그램은 반드시 #include "dtime.h"를 해줘야 한다.
	  #include 지시자를 사용할 때, 이미 정의된 헤더파일은 < > 안에 적어주고, 프로그래머가 작성한 헤더파일은 " " 안에 적어준다.(검색을 위하여)

	- dtime.cpp 파일에는 정의된 클래스의 멤버 함수와 오버로드 연산자의 정의 부분을 작성한다.
	  이 파일을 '구현 파일'이라고 하며, 인터페이스 파일과 동일한 이름을 갖는다.
	  
	- 구현 파일과 프로그램 파일은 모두 인터페이스 파일을 이름 짓는 #include 지시자를 반드시 명시하여야 한다.
	  main 함수를 가진 프로그램을 포함하는 파일을 '응용 파일(application file)' 또는 '드라이버 파일(driver file)' 라고 부른다.

	★★★★★★★★★
	> 즉, 요약하자면 하나의 클래스를 클래스 정의 부분과 멤버 함수의 구현 부분으로 별도의 파일에 위치시킬 수 있다.
	  그 클래스를 사용하는 어떠한 프로그램도 별도로 컴파일 할 수 있으며, 하나의 클래스를 프로그램의 여러곳에서 사용할 수 있다.
	  그 클래스는 다음과 같은 방법으로 여러 파일로 나누어 저장할 수 있다.

	  1) '인터페이스 파일'이라 불리는 헤더 파일은 클래스의 정의 부분이다.
	     헤더 파일은 .h로 끝난다.
		 인터페이스 파일은 함수 선언이나 중복 정의된 연산자의 선언을 포함하지만, 클래스의 정의에는 기록되지 않는다.
		 또한 이러한 연산자와 함수들이 어떻게 사용되는지 이에 관하나 주석을 포함한다.

	  2) 모든 함수 및 중복 연산자들의 정의는 '구현 파일'이라고 불리는 별도의 파일에 포함된다.
	     이 파일은 앞서 기술한 인터페이스 파일을 포함하는 지시어를 반드시 포함하여야 한다. (ex. #include "dtime.h"
		 인터페이스 파일과 구현 파일은 일반적으로 동일한 이름을 가진다.
		 But, 인터페이스 파일은 확장자가 .h로 끝나며, 구현 파일은 일반적인 C++파일과 동일한 확장자를 가진다.
		 구현 파일은 다른 C++ 프로그램에서 사용되기 전에 별도로 컴파일 된다.

	  3) 프로그램 안에서 클래스를 사용하고 한다면 응용 프로그램 또는 드라이버 파일 안에 다음 지시어를 포함하여야 한다. (#include "dtime.h)
	     응용 파일은 구현 파일과 별도로 컴파일된다.
		 여러 응용 프로그램이 하나의 인터페이스 파일과 구현 파일을 여러번 사용하는 것이 가능하다.
		 전체 프로그램을 실행하고자 한다면 구현 파일과 응용 파일의 컴파일에 의해 생성된 각각의 object코드를 먼저 연결시켜야 한다.
		 몇며 시스템에서는 링킹이 자동 혹은 반자동적으로 수행될 수 있다.

	* ★★★컴파일 과정★★★
	
	- 프로그램을 컴파일하면 먼저 전처리기(pre-processor)가 include 지시자를 읽어서 dtime.h파일의 내용으로 대치한다.
	  인터 페이스 구현 파일과 응용 프로그램 파일이 컴파일된 후에 두 파일이 같이 실행될 수 있도록 
	  분리된 '링커(Linker)'라는 유틸리티가 '링킹(linking)' 작업을 실행한다.
	  ( UNIX시스템에서 make 유틸리티가 이를 처리한다)
	  대부분의 IDE(통합개발환경) 에서는 실행에 필요한 여러 파일을 한 '프로젝트(project)'로 연결하여 실행한다.

*/


/*
	* #ifndef 사용하기

	- dtime.h 파일을 다음과 같이 수정하면, 클래스의 중복 정의를 방지할 수 있다.

	#ifndef DTIME_H
	#define DTIME_H

	(dtime.h의 내용)

	#endif

*/