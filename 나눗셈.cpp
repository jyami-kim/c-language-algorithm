#include <stdio.h>
int main (void) {
	double mo = 0;
	double ja = 0;
	printf("분자를 입력하시오:");
	scanf("%f", &ja);
	printf("분모를 입력하시오:");
	scanf("%f", &mo);
	if (mo == 0) {
		printf("0으로 나눌 수 없습니다.");
	}
	else {
		printf("결과는 %f 입니다.\n", ja/mo);
	}
	return 0;
}
