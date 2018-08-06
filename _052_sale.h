// 기반 클래스 Sale에 대한 인터페이스
//

#ifndef SALE_H
#define SALE_H

namespace SavitchSale
{

/*
	- 클래스 Sale은 할인이나 배송비가 없는 단일 품목에 대한 단순 판매에 해당된다.
	  
	- 멤버 함수 savings와 오버로딩된 연산자 <가 각각 함수 bill을 사용함을 주목하라 ★★★★
	  bill 이 가상 함수로 선언되었기 떄문에, 나중에 클래스 Sale의 파생 클래스를 정의할 수 있고,
	  각 파생 클래스의 멤버 함수 bill을 정의할 수 있다.
*/
	class Sale
	{
	public:
		Sale();
		Sale(double thePrice);
		double getPrice() const;
		void setPrice(double newPrice);
		virtual double bill() const;
		double savings(const Sale& other) const;				// 호출 객체 대신에 다른 것을 사면, savings를 반환한다.

	private:
		double price;
	};

	bool operator < (const Sale& first, const Sale& second);	// 어떤 것이 더 큰지를 보기 위해 두 판매를 비교한다.
}

#endif