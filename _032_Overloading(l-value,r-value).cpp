/*

	- 함수나 연산자가 l-value나 r-value로 사용될 때 각각 다르게 동작하도록 오버로딩할 수 있다.
	  예를 들어, 함수가 오버로딩되어 l-value 또는 r-value로 사용될 때 다르게 동작하도록 하고 싶다면 다음 예제를 살펴보라.
		Ex)	
		class SomeClass
		{
		public:
			int& f();				// l-value 호출에 사용
			const int& f() const;	// r-value 호출에 사용
			...
		};

	★★★★★★★★★★★★★★★★★★★
	> r-value호출엔 2개의 const와 &가 반드시 필요하다

*/