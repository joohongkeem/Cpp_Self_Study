/*
 
 * 형 변환(Type Cast)
 >> 특정한 형에 속하는 값을 다른 형의 값으로 변환하는 방법
 
 Ex) 9/2는 피연산자가 모두 int형이기 때문에 4를 출력한다.
     만약, 4.5라는 결과값을 얻고 싶다면, 9/2.0을 사용하면 된다.

	 But, int m = 9, n = 2; 라면 m/n은 항상 4를 출력하기 된다.
	 만약, 4.5의 결과를 얻고 싶다면,
	 double ans = m/static_cast<double>(n); 의 꼴로 사용해야 한다.

	 1. static_cast<double>(n) 
	 - n의 값을 double형의 동일한 값으로 변환한다.
	 - [주의1] 변수 n의 값을 변환시키지 않는다.
	 - [주의2] static_cast<int>(n) 의 n에 실수형을 넣는다면, 소수점 이하를 버린 값이 반환.

	 2. const_cast<Type>(Expression) 
	 - 상수형 번환을 위해 사용된다.

	 3. dynamic_cast<Type>(Expression)
	 - 상속관계를 맺고 있는 부모와 자손형에서, 부모형을 자손형으로 변환할 때 사용


 * 고전적 형변환
 
 Ex) double(42), (double)42 등


 * 강제 형변환
 - double d = 5;
   라고 입력하면, C++은 자동적으로 형 변환을 수행하여 5에서 5.0으로 변환하고 d에 할당

*/