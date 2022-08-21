#include <bits/stdc++.h>
using namespace std;

const int MAXN = 13;
int monthDays[MAXN] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isLeapYear(int year) {
	return year % 4 == 0 || year % 100 == 0;
}

int daysInSameYear(int day1, int month1, int day2, int month2, int year) {
	if (month1 == month2) {
		return day2 - day1 + 1;
	}

	int days = 0;
	if (isLeapYear(year)) {
		monthDays[2] = 29;
	} else {
		monthDays[2] = 28;
	}

	for (int i = month1 + 1; i < month2; i++) {
		days += monthDays[i];
	}

	days += monthDays[month1] - day1 + 1;
	days += monthDays[month2] - day2 + 1;

	return days;
}

int daysInConsecutiveYears(int day1, int month1, int day2, int month2, int year) {
	int days = 0;

	if (isLeapYear(year)) {
		monthDays[2] = 29;
	} else {
		monthDays[2] = 28;
	}

	for (int i = month1 + 1; i < MAXN; i++) {
		days += monthDays[i];
	}

	if (isLeapYear(year + 1)) {
		monthDays[2] = 29;
	} else {
		monthDays[2] = 28;
	}

	for (int i = 1; i < month2; i++) {
		days += monthDays[i];
	}

	days += monthDays[month1] - day1 + 1;
	days += day2 - 1 + 1;

	return days;
}

int daysInYears(int day1, int month1, int year1, int day2, int month2, int year2) {
	int days = 0;

	for (int year = year1 + 1; year < year2; year++) {
		if (isLeapYear(year)) {
			days += 366;
		} else {
			days += 365;
		}
	}

	days += daysInSameYear(day1, month1, 31, 12, year1);
	days += daysInSameYear(1, 1, day2, month2, year2);

	return days;
}

void daysInMonth(int day1, int month1, int year1, int day2, int month2, int year2) {

	int days = 0;
	if (year1 == year2) {
		days = daysInSameYear(day1, month1, day2, month2, year1);
	} else if (year1 + 1 == year2) {
		days = daysInConsecutiveYears(day1, month1, day2, month2, year1);
	} else {
		days = daysInYears(day1, month1, year1, day2, month2, year2);
	}

	cout << days - 1 << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int day1, month1, year1, day2, month2, year2;
	cin >> year1 >> month1 >> day1 >> year2 >> month2 >> day2;

	daysInMonth(day1, month1, year1, day2, month2, year2);

	return 0;
}
