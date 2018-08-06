﻿/*

	* 다형성(polymorphism)

	- 다형성은 가상 함수(virtual function) 혹은 사후 바인딩(late binding)으로 알려진 특별한 기법을 써서
	  하나의 함수에 여러 의미를 연관시키는 능력을 나타낸다.
	> 다형성은 객체지향 프로그래밍으로 알려진 대중적이며 강력한 프로그래밍 철학의 기본적인 기법들 중 하나이다.
	  (가상 함수란, 해당 함수가 정의되기 전에 사용되기 떄문에 가상이라는 이름이 붙었다)


	* 사후 바인딩(last binding)

	- 가상 함수를 이해하기 쉽도록, 예를 들어보자.
	  사각형, 원, 타원형 등 여러 종류의 도형에 대한 클래스를 가지는 그래픽 패키지 소프트웨어를 설계한다고 가정해보자.
	  각각의 도형은 다른 클래스의 객체여야 한다.
	  예를들면 Rectangle 클래스는 높이, 폭, 중심점을 멤버 변수로 가지지만,
				Circle 클래스는 중심점과 반지름을 멤버 변수로 갖는다.
	  잘 설계된 프로그래밍 프로젝트에서는 이들 모든 클래스는 단일 부모 클래스(예를 들어 Figure)의 자손일 수 있다.
	  이제 화면에 도형을 그리기 위한 함수를 작성하려고 한다.
	  이 때, r이 Rectangle 객체이고, c가 Circle 객체라면, r.draw()와 c.draw()는 다른 코드로 구현된 함수 일 수 있다.

	  부모 클래스 Figure는 모든 도형에 적용할 수 있는 함수를 가진다.
	  예를들면, 함수 center는 원래의 도형을 지우고 도형을 화면의 중심으로 이동시키고 화면의 중심에서 다시 그린다.
	  함수 Figure::center는 화면의 중심에 도형을 다시 그리기 위해 함수 draw를 사용한다.
	  클래스 Rectangle과 Circle의 도형에 상속함수 center를 사용하려고 생각할때, 여기에 복잡한 문제가 있딴 것을 알게 된다.

	  좀 더 극단적으로 생각하기 위해, Figure클래스가 이미 작성되어 사용되고 있고, 그 후에 Triangle이라는 새로운 도형 클래스를 추가한다고 생각해보자.
	  이제 Triangle은 클래스 Figure의 파생 클래스이고, 그래서 함수 center는 클래스 Figure로부터 상속받을 것이다.
	  함수 center는 모든 Triangle에 적용되고 정확하게 동작되어야 하지만, 여기에 복잡한 무제가 있다.
	  함수 center는 draw를 사용하고, 함수 draw는 도형마다 각각 그 내용이 다르다.
	  상속함수 center가 클래스 Figure에서 주어진 함수 draw의 정의를 사용한다면, 함수 draw는 Tirangle에 대해 올바르게 동작하지 않는다.
	  상속 멤버 함수 center는 함수 Figure::draw보다는 함수 Triangle::draw를 사용해야 할 것이다.

	  그러나, 클래스 Figure에서 정의된 함수 center가 작성되고 컴파일될 때, 클래스 Triangle과 함수 Triangle::draw는 작성되지도 않았다.
	  어떻게 함수 center가 Triangle에 대해서 올바르게 동작할 수 있을까?
	  컴파일러는 center가 컴파일될때 Triangle::draw에 대해 알지 못한다.
	  이 때, 해결 방법이 draw를 가상 함수로 제공하는 것이다.

	  ★★★
	  함수를 가상(virtual)로 만드는 것은 컴파일러에 
	  "나는 함수가 어떻게 구현되는지 모른다. 프로그램에서 사용될 때까지 기다려라. 그리고 객체 인스턴스로부터 구현을 얻어라."라고 말하는 것이다
	  프로시저의 구현을 알기 위해 실행 시간까지 기다리는 기법을 '사후 바인딩(late binding)' 또는 '동적 바인딩'dynamic binding)'이라고 한다.
	  가상 함수는 C++이 사후 바인딩을 제공하는 방법이다.

	  
*/