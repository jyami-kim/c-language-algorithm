#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

void isLeapYear(int year, int monthArray[]) {
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		monthArray[1] = 29;
	else
		monthArray[1] = 28;
	return;
}

int dayOfWeek(int month, int year, int *monthArray) {
	int default_year = 2018;
	int result = 0;
	int return_val = 0;

	if (year >= default_year) {
		for (int i = default_year; i < year; i++) {
			isLeapYear(i, monthArray);
			if (monthArray[1] == 29)
				result += 366;
			else
				result += 365;
		}
		isLeapYear(year, monthArray);
		for (int i = 0; i < month - 1;i++) {
			result += monthArray[i];
		}
		return_val = (1 + result) % 7;
		return return_val;
	}
	else {
		for(int i = default_year ; i > year+1;i--){
			isLeapYear(i, monthArray);
			if (monthArray[1] == 29)
				result += 366;
			else
				result += 365;
		}
		isLeapYear(default_year, monthArray);
		for (int i = 12; i >= month;i--) {
			result += monthArray[i-1];
		}
		return_val = 7 + ((1 - result) % 7);
		return return_val;
	}
}

int main(void) {

	int year;
	int month;
	int monthArray[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int yo;

	printf("년도를 입력하세요>> ");
	scanf_s("%d", &year);
	printf("달을 입력하세요 >> ");
	scanf_s("%d", &month);
	
	yo = dayOfWeek(month, year, monthArray);
	int count = 0;

	//달력 프린트
	printf("=====================\n");
	printf(" 일 월 화 수 목 금 토 \n");
	printf("=====================\n");
	for (int i = 0; i < yo; i++) {
	printf("   ");
	count++;
	}

	for (int i = 1; i < monthArray[month-1]+1; i++) {
		printf("%3d", i);
		count++;
		if (count > 6) {
			printf("\n");
			count = 0;
		}
	}
	printf("\n");

	return 0;
}

