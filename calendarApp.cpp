#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <windows.h>
using namespace std;

void openPage(const char* initFileName) {
	ShellExecute	(NULL,
					"open",
					initFileName,
					NULL,
					NULL,
					SW_MAXIMIZE);
}

bool isLeapYear(int year) {
	if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return true;
    } else {
        return false;
    }
}

int resYear(int year) {
	if(isLeapYear(year)) {
        return 2;
    } else {
        return 1;
    }
}

int resMonth(int year, int month) {
	switch(month) {
        case 1:
		case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 3;
            break;
        case 2:
            if(isLeapYear(year)) {
                return 1;
            } else {
                return 0;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            return 2;
            break;
        default:
            return -1;
    }
}

void showMonth(int year, int month) {
    int totalRes = 0;
    int daysInMonth;
    string monthNames [] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    string monthName = monthNames [month - 1];
    string content = "<h1>" + monthName + " " + to_string(year) + "</h1><table><tr><th>Mo</th><th>Tu</th><th>We</th><th>Th</th><th>Fr</th><th>Sa</th><th>Su</th></tr>";

    for(int i = 1; i < year; ++i) {
        totalRes += resYear(i);
    }

    for(int i = 1; i < month; ++i) {
        totalRes += resMonth(year, i);
    }

    switch(month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            daysInMonth = 31;
            break;
        case 2:
            if(isLeapYear(year)) {
                daysInMonth = 29;
            } else {
                daysInMonth = 28;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            daysInMonth = 30;
            break;
        default:
            daysInMonth = 0;
    }

    int dayOfWeek = (totalRes % 7) + 1;
    for(int i = 1; i < ceil((daysInMonth + dayOfWeek - 1) / 7) + 2; ++i) {
        content += "<tr>";
        if(i == 1) {
            for(int j = 1; j < dayOfWeek; ++j) {
                content += "<td></td>";
            }

            for(int j = dayOfWeek; j < 8; ++j) {
                content += "<td>" + to_string(j + 1 - dayOfWeek) + "</td>";
            }
        } else {
            for(int j = 1; j < 8; ++j) {
                if((i - 1) * 7 + j + 1 - dayOfWeek < daysInMonth + 1) {
					content += "<td>" + to_string((i - 1) * 7 + j + 1 - dayOfWeek) + "</td>";
				} else {
					content += "<td></td>";
				}
            }
        }
        content += "</tr>";
    }
    content += "</table>";

    ofstream page;
    page.open("calendar.html");
    page << content;
    page.close();

    openPage("calendar.html");
}

int main() {
	int year, month;

	cout << "Enter a year: ";
	cin >> year;

	while(year < 1 || cin.fail()) {
		cout << "Error! Please, type in a valid year: ";
		cin.clear();
		cin.ignore(256,'\n');
		cin >> year;
	}

	cout << "Enter a month: ";
	cin >> month;

	while(month < 1 || month > 12 || cin.fail()) {
		cout << "Error! Please, type in a valid month: ";
		cin.clear();
		cin.ignore(256,'\n');
		cin >> month;
	}

	showMonth(year, month);

	return 0;
}
