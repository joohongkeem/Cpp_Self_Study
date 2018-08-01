

/*

	* 텍스트를 처리하는 경우, <cctype> 라이브러리에 다양한 함수가 정의되어 있다.
	> 사용하려면 #include <cctype> 을 하면 된다. 전역 네임스페이스에 정의문이 존재하기 때문에 지시자 사용을 필요없다.

		함수							설명
	
	toupper(char_exp)	char_exp 값을 대문자로 표현함 (★★정수형 값으로 처리★★)			

	tolower(char_exp)	char_exp 값을 소문자로 표현함 (★★정수형 값으로 처리★★)
						
	isupper(char_exp)	char_exp 값이 대문자면 true, 소문자면 false
									  
	islower(char_exp)	char_exp 값이 소문자면 true, 대문자면 true

	isalpha(char_exp)	char_exp 값이 알파벳이면 true, 아니면 false

	isdigit(char_exp)	char_exp 값이 숫자면 true, 아니면 false

	isalnum(char_exp)	char_exp 값이 문자or숫자면 true, 아니면 false

	isspace(char_exp)	char_exp 값이 공백계통의 문자이면 true, 아니면 false

	ispunct(char_exp)	char_exp 값이 공백문자, 숫자, 또는 알파벳이 아닌
						프린트 가능한 문자일 경우 true, 아니면 false

	isprint(char_exp)	char_exp 값이 프린트 가능한 문자이면 true, 아니면 false

	isgraph(char_exp)	char_exp 값이 공백 문자가 아닌 프린트 가능한 문자이면 true
						아니면 false

	isctrl(char_exp)	char_exp 값이 컨트롤 문자이면 true, 아니면 false




*/