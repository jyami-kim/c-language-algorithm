#include <stdio.h>

int main(void) {
	double c = 0;
	double f = 0;

	printf("화씨온도를 입력하시오: ");
	scanf("%f", f);
	c = 5 / 9 * (f - 32);
	printf("섭씨온도는 %f입니다.", c);
}
