// 기반클래스 PFArrayD의 인터페이스
// - 이 형의 객체는 double 값이 부분적으로 채워진 배열이다.
//

#ifndef PFARRAYD_H
#define PFARRAYD_H



class PFArrayD
{
public:
	PFArrayD();											// 배열의 크기를 50으로 초기화
	PFArrayD(int capacityValue);
	PFArrayD(const PFArrayD& PFAoBJECT);				// 복사 생성자

	void addElement(double element);
	bool full() const;									// 배열이 꽉차면 true, 아니면 false를 반환
	int getCapacity() const ;
	int getNumberUsed() const ;

	void emptyArray();									// 배열을 비움 (used를 0으로 설정하면 실질적으로 배열을 비우게 된다)
	double& operator [] (int index);					// 요소를 읽고 값을 변경함 (0부터 numberUsed-1 까지의 요소를 읽고 바꾼다)

	PFArrayD& operator = (const PFArrayD& rightside);	// 할당 연산자의 오버로딩 ( 반드시 멤버함수여야 한다, friend XXX)

	~PFArrayD();										// 소멸자

/*
	- 멤버 변수들을 protected로 제한하였으므로, ㅍ생 클래스의 멤버 함수들은 기반 클래스의 멤버 변수들을
	  일므을 통해 직접적으로 접근할 수 있게 된다.
*/
protected:
	double *a;											// double형 배열을 위한 포인터
	int capacity;										// 배열의 크기
	int used;											// 현재 사용중인 배열의 위치

};

#endif