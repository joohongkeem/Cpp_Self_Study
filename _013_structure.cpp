#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

struct person
{
	char name[10];
	int age;
};
typedef struct person PERSON;

struct schoolinfo
{
	char id[10];
	PERSON pinfo;
	//bool older;		// bool은 0이 아니면 참이니깐 세개의 선택을 위해 char로 해주자
	char older;
} P_joohong, P_eunji;

void showInfo(struct schoolinfo a);
struct schoolinfo compareAge(struct schoolinfo &a, struct schoolinfo &b);


int main()
{
	struct schoolinfo P_yongbin = {"20130221", "김용빈", 32, 0};
	//
	// 이렇게 선언과 동시에 초기화할 수도 있다!! (단, 순서에 주의하자★★)

	strcpy(P_joohong.id,"20110543");
	P_joohong.pinfo.age = 27;
	strcpy(P_joohong.pinfo.name, "김주홍");
	P_joohong.older = 0;

	strcpy(P_eunji.id, "20150674");
	P_eunji.pinfo.age = 23;
	strcpy(P_eunji.pinfo.name, "안은지");
	P_eunji.older = 0;

	showInfo(P_joohong);
	showInfo(P_eunji);
	showInfo(P_yongbin);

	compareAge(P_joohong, P_eunji).older = 1;
	if(P_joohong.older = 1) P_eunji.older = 2;
	else if(P_joohong.older = 2) P_eunji.older = 1;

	showInfo(P_joohong);
	showInfo(P_eunji);
	showInfo(P_yongbin);


	return 0;
}

void showInfo(struct schoolinfo a)
{
	cout << "-----------------------------" << endl;
	cout << "학번 : " << a.id << endl;
	cout << "이름 : " << a.pinfo.name << endl;
	cout << "나이 : " << a.pinfo.age << endl;
	if(a.older == 1) cout << "늙은이" << endl;
	else if(a.older == 2) cout << "젊은이" << endl;
	else cout << "미확정" << endl;
}
struct schoolinfo compareAge(struct schoolinfo &a, struct schoolinfo &b)
{
	if(a.pinfo.age >= b.pinfo.age) return a;
	else return b;
}
