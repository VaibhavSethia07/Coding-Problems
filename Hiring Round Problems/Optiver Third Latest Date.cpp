#include <bits/stdc++.h>
using namespace std;

class Date {
public:
	int day, month, year;

	Date(int day = 0, int month = 0, int year = 0) {
		this->day = day;
		this->month = month;
		this->year = year;
	}
};

class DateComparator {
	int compare(int date1, int date2) {
		if (date1 == date2) {
			return 0;
		} else if (date1 < date2) {
			return -1;
		}

		return date1 > date2;
	}

public:
	bool operator()(Date& date1, Date& date2) {
		int yearCheck = compare(date1.year, date2.year);

		if (yearCheck == 0) {
			int monthCheck = compare(date1.month, date2.month);

			if (monthCheck == 0) {
				int dayCheck = compare(date1.day, date2.day);

				return dayCheck >= 0;
			}

			return monthCheck == 1;
		}

		return yearCheck == 1;
	}
};

Date ThirdLargest(std::vector<Date>& dates) {
	sort(dates.begin(), dates.end(), DateComparator());

	return dates[2];
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, day, month, year;
	cin >> N;

	vector<Date> dates(N);

	for (int i = 0; i < N; i++) {

		cin >> day >> month >> year;
		dates[i] = Date(day, month, year);
	}

	Date thirdLargest = ThirdLargest(dates);

	cout << thirdLargest.year << "-" << thirdLargest.month << "-" << thirdLargest.day << "\n";

	for (int i = 0; i < N; i++) {
		cout << dates[i].year << "-" << dates[i].month << "-" << dates[i].day << "\n";
	}

	return 0;
}
