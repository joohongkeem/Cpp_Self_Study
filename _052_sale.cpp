// 기반 클래스 Sale의 구현
// - 인터페이스는 파일 "_052_sale.h"에 있다.
//

#include <iostream>
#include "_052_sale.h"
using std::cout;

namespace SavitchSale
{
	Sale::Sale() : price(0)
	{ /* 의도적인 공백 */}

	Sale::Sale(double thePrice)
	{
		if(thePrice>=0) 
			price = thePrice;
		else
		{
			cout<< "Error : Cannot Have a Negative Price!!\n" ;
			exit(1);
		}
	}

	double Sale::bill() const
	{
		return price;
	}

	double Sale::getPrice() const
	{
		return price;
	}

	void Sale::setPrice(double newPrice)
	{
		if(newPrice>=0)
			price = newPrice;
		else
		{
			cout<< "Error : Cannot Have a Negative Price!!\n" ;
			exit(1);
		}
	}

/*
	- 클래스 Sale은 할인이나 배송비가 없는 단일 품목에 대한 단순 판매에 해당된다.
	  
	- 멤버 함수 savings와 오버로딩된 연산자 <가 각각 함수 bill을 사용함을 주목하라 ★★★★
	  bill 이 가상 함수로 선언되었기 떄문에, 나중에 클래스 Sale의 파생 클래스를 정의할 수 있고,
	  각 파생 클래스의 멤버 함수 bill을 정의할 수 있다.

	  ★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★
	- 즉, bill이 가상함수이므로, other에 파생된 클래스 DiscountSale 객체가 들어간다면,
	  DiscountSale.bill() 함수가 호출되는 것이다.
	  
*/
	double Sale::savings(const Sale& other) const
	{
		return (bill() - other.bill());
	}

	bool operator < (const Sale& first, const Sale& second)
	{
		return(first.bill() < second.bill());
	}

	
}