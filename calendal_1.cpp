#include<stdio.h>

int main(void) {
	int year, month;
	int yun, i, leapday = 0;
	int totalday;
	int day1, day2 = 0;
	int month_day[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };


	printf("연도와 월을 입력하시오:");
	scanf_s("%d %d", &year, &month);

	for (i = 0; i < year; i++)
	{
		if ((i % 4 == 0 && !(i % 100 == 0)) || i % 400 == 0) {
			leapday++;
		}
	} /*leapday= 입력year전년도까지 있었던 윤년의 수*/

	day1 = 365 * (year - 1) + leapday;
	/*day1=1년 1월 1일부터 입력년도 전년도까지 일 수*/


	for (i = 0; i < month - 1; i++) {
		day2 += month_day[i];

	}

	if ((year % 4 == 0 && !(year % 100 == 0)) || year % 400 == 0) {
		yun = 1;
		if (month >= 3)
			day2 += 1;
	}
	else {
		yun = 0;
		day2 = day2;
	}
	//day2= 입력년 1월 1일부터 입력월 1일까지 일 수

	totalday = day1 + day2;

	printf("\t<%d년%d월>\n", year, month);
	printf(" SUN MON TUE WED THU FRI SAT\n");

	int x = totalday % 7;

	for (i = 0; i < x; i++) {
		printf("    ");
	}

	if (yun == 1 && month == 2) {
		for (i = 1; i <= 29; i++) {
			x++;
			printf("%4d", i);
			if (x % 7 == 0)
				printf("\n");
		}
	}
	else {
		for (i = 1; i <= month_day[month - 1]; i++) {
			printf("%4d", i);
			x++;
			if (x % 7 == 0)
				printf("\n");
		}
	}
	printf("\n");

	return 0;
}
