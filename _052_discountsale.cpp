// 파생 클래스 DiscountSale의 구현
// - 인터페이스는 헤더파일 "_052_discountsale.h"에 있다.
//

#include "_052_discountsale.h"

namespace SavitchSale
{
	DiscountSale::DiscountSale() : Sale(), discount(0)
	{
		// 의도적인 공백
	}

	DiscountSale::DiscountSale(double thePrice, double theDiscount)
		: Sale(thePrice), discount(theDiscount)
	{
		// 의도적인 공백
	}

	double DiscountSale::getDiscount() const
	{
		return discount;
	}

	void DiscountSale::setDiscount(double newDiscount)
	{
		discount = newDiscount;
	}

	// ★★★
	// - 함수 정의에서 virtual을 반복하지 않는다.
	//
	double DiscountSale::bill() const
	{
		double fraction = discount / 100;
		return (1-fraction) * getPrice();
	}
}