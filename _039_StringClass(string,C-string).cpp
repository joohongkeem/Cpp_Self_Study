
/* 
	* string 객체와 C-String의 상호 변환

	- C++에서는 string형 변수에 C-String 값을 저장하는 경우 자동적으로 형 변환이 일어난다.
		char aCString[] = "This is my C-String.";
		string stringVariable;
		stringVariable = aCString;
	> 즉, 위의 코드는 아무런 문제가 없다.
	
	  But, 다음과 같은 코드들은 허용되지 않는다.
		aCString = stringVariable;			(XXXXX)
		strcpy(aCString, stringVariable);	(XXXXX)

	  Why? strpcy함수의 두 번째 인자는 string 객체를 취할 수 없으며
		   string객체는 C-String으로 자동적으로 변환되지 않는다.

	★★★★★★★★★★★
    - C-String을 string 객체로 변환하기 위해서는 반드시 명시적인 형 변환을 수행하여야 한다.
	  이를 위해서, string 멤버 함수인 c_str() 함수를 사용할 수 있다.
		strcpy(aCString, stringVariable.c_str());	(OOOOO)

	  But, 할당 연산자를 사용하여 C-String을 처리할 수 없기 때문에 다음과 같은 문장을 허용되지 않는다.
		aCString = stringVariable.c_str();			(XXXXX)

*/