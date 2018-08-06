// 파생클래스 PFArrayDBak의 구현
// 

#include "_050_pfarraydbak.h"
#include <iostream>

using std::cout;

PFArrayDBak::PFArrayDBak() : PFArrayD(), usedB(0)
{
	b = new double[capacity];
	// b = new double[getCapacity()];			// 이 구현은 기반 클래스에 있는 모든 멤버 변수가 protected가 아닌 public이여도 동작한다.
}

PFArrayDBak::PFArrayDBak(int capacityValue) : PFArrayD(capacityValue), usedB(0)
{
	b = new double[capacity];
	// b = new double[getCapacity()];			// 이 구현은 기반 클래스에 있는 모든 멤버 변수가 protected가 아닌 public이여도 동작한다.
}

PFArrayDBak::PFArrayDBak(const PFArrayDBak &oldObject) : PFArrayD(oldObject), usedB(0)
{
	b = new double[capacity];
	// b = new double[getCapacity()];			// 이 구현은 기반 클래스에 있는 모든 멤버 변수가 protected가 아닌 public이여도 동작한다.
	usedB = oldObject.usedB;
	for(int i=0; i<usedB; i++)
		b[i] = oldObject.b[i];
}

void PFArrayDBak::backup()
{
	usedB = used;
	for(int i=0; i<usedB; i++)
		b[i] = a[i];				// b는 배열 a의 사본이다.
									// b = a; 를 사용하지 않는다.
}

void PFArrayDBak::restore()
{
	used = usedB;
	for(int i=0; i<used; i++)
		a[i] = b[i];
}

PFArrayDBak& PFArrayDBak::operator =(const PFArrayDBak &rightSide)
{
	int oldCapacity = capacity;
	PFArrayD::operator =(rightSide);	// 기반 클래스 멤버 변수에 값을 할당하기 위해 기반 클래스 할당 연사자를 호출한다.

	if(oldCapacity != rightSide.capacity)
	{
		delete [] b;
		b = new double[rightSide.capacity];
	}

	usedB = rightSide.usedB;
	for(int i=0; i<usedB; i++)
		b[i] = rightSide.b[i];

	return *this;
}

PFArrayDBak::~PFArrayDBak()
{
	delete [] b;
	//
	// 기반 클래스 PfFArrayD의 소멸자가 자동으로 호출되고 delete [] a; 를 수행한다.
}