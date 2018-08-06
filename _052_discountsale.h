// 파생클래스 DiscountSale의 인터페이스
//

#ifndef DISCOUNTSALE_H
#define DISCOUNTSALE_H

#include "_052_sale.h"

namespace SavitchSale
{
	class DiscountSale : public Sale
	{
	public:
		DiscountSale();
		DiscountSale(double thePrice, double theDiscount);
		//
		// theDiscount는 가격의 백분율로 표현된다.
		// 음의 할인은 가격 인상이다.

		double getDiscount() const;
		void setDiscount(double newDiscount);
		
		double bill() const;
		//
		// - bill은 기반 클래스에서 가상으로 선언되었기 떄문에 파생 클래스 DiscountSale에서 자동으로 가상이다.
		// > bill의 선언에 변경자 virtual을 추가하거나 여기서와 같이 생략할 수 있다.
		//   어느 경우에도 bill은 클래스 DiscountSale에서 가상이다.
		//   (필요하지않더라도 모든 가상 함수 선언에서는 virtual을 추가하는 것이 좋다, 여기선 생략해도 된다는 걸 보여주려 생략)
		//
		// ★★★★
		// 즉, 가상 함수의 속성은 상속된다.

	private:
		double discount;
	};
}


#endif