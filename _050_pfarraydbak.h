// 파생클래스 PFArrayDBak의 인터페이스이다.
// - 이 형의 객체는 double 값이 부분적으로 채워진 배열이며
//   이 버전은 프로그래머로 하여금 부분적으로 채워진 배열의 백업 사본을 만들고 최근에 저장된 사본으로 복원할 수 있도록 한다.
//

#ifndef PFARRAYDBAK_H
#define PFARRAYDBAK_H

#include "_050_pfarrayd.h"

class PFArrayDBak : public PFArrayD
{
public:
	PFArrayDBak();								// 배열의 크기를 50으로 초기화
	PFArrayDBak(int capacityValue);
	PFArrayDBak(const PFArrayDBak& Object);

	void backup();								// 부분적으로 채워진 배열의 백업 사본을 만든다.
	void restore();								// 가장 최근에 저장된 버전의 부분적으로 채워진 배열로 복원한다.
												// - 만약 백업이 한번도 이루어진 적이 없다면, 부분적으로 채워진 배열이 빈채로 유지된다.
	PFArrayDBak& operator = (const PFArrayDBak& rightSide);

	~PFArrayDBak();

private:
	double *b;		// 메인 배열의 백업
	int usedB;		// 상속된 멤버 변수 used의 백업
};


#endif