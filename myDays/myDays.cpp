#include <iostream>
using namespace std;

int gregorian[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int leapyear[] = {31, 29, 31, 30, 31 ,30, 31, 31, 30, 31, 30, 31};
string months[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };


bool leap(int year) {

	bool leap;

	if (year  % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0) {
				leap = true;
			}
		}
		else {
			leap = true;
		} 

	}
	else {
		leap = false;
	}

	return leap; 

}


//before dob calc
int bruh(int month, int day, int year) {
	int sum = 0;

	if (leap(year) == true) {
		for (int i = 1; i < month; i++) {
			sum = sum + leapyear[i - 1];
		}
	}
	else {
		for (int i = 1; i < month; i++) {
			sum = sum + gregorian[i - 1];
		}
	}
	
	return sum + day; 

}
//after due date calc
int huh(int month, int day, int year) {

	int sum = 0;
	
	if (leap(year) == true) {
		for (int i = 12; i >= month; i--) {
			sum = sum + leapyear[i - 1];
		}
	}	
	else {
		for (int i = 12; i >= month; i--) {

			sum = sum + gregorian[i - 1];


		}
	}
	return sum - day;

}

void valid(int month, int day, int year, string one, string two) {
	if (leap(year) == true) {
		while (month < 1 || month > 12 || day > leapyear[month - 1] || day < 1 || year < 1 || year > 3000) {

			cout << one << endl;
			cout << two;
			cin >> month >> day >> year;
		}
	}
	else {
		while (month < 1 || month > 12 || day > gregorian[month - 1] || day < 1 || year < 1 || year > 3000) {

			cout << one << endl;
			cout << two;
			cin >> month >> day >> year;
		}
	}

}


void age_calc(int birth_month, int birth_day, int birth_year, int due_month, int due_day, int due_year) {

	int month_, days_;
	int years_ = due_year - birth_year;

	if (birth_month > due_month) {

		years_--;
		month_ = 12 - (birth_month - due_month);
	}
	else {
		month_ = due_month - birth_month; //also be written (month_ = 12 - abs(birth_month - due_month) ) so that birth_m - due_moneth isnt negative
	}
	if (due_day < birth_day)
	{
		month_--;
		days_ = gregorian[due_month - 1] - (birth_day - due_day);
	}
	else
	{
		days_ = due_day - birth_day;
	}
	cout << "Your age is: ";
	cout << years_ << " years " << month_ << " months " << days_ << " days. ";
}



int main()
{

	//test in from class: 5 31 1993 9 20 2014

	int birth_month;
	int birth_day;
	int birth_year;

	int due_month;
	int due_day;
	int due_year;


	cout << "\nEnter your date of birth (mm/dd/yy): ";
	cin >> birth_month >> birth_day >> birth_year;
	cout << endl;
	valid(birth_month, birth_day, birth_year, "Please re-enter a valid date.", "\nEnter your date of birth (mm/dd/yy): ");


	cout << "\nEnter the due date (mm/dd/yy): ";
	cin >> due_month >> due_day >> due_year;
	cout << endl;

	valid(due_month, due_day, due_year, "Please re-enter a valid date.", "\nEnter the due date (mm/dd/yy): ");



	int age_days, age, in_between_years, days_remaining, nbefore, nafter;
	string birth_month_output;
	string due_date_output;
	int leap_years = 0;
	in_between_years = (due_year - birth_year) + 1;

	for (int i = birth_year; i <= due_year; i++) {

		if (leap(i) == true) {

			leap_years = leap_years + 1;

		}

	}



	nbefore = bruh(birth_month, birth_day, birth_year);


	nafter = huh(due_month, due_day, due_year);
	age_days = ((in_between_years - leap_years) * 365) + (leap_years * 366) - (nbefore + nafter);




	cout << "Date of Birth: " << months[birth_month - 1] << " " << birth_day << ", " << birth_year << endl;
	cout << "Due Date: " << months[due_month - 1] << " " << due_day << ", " << due_year << endl;
	cout << "Age: " << age_days << " days" << endl;



	cout << "Leap years during time period: " << leap_years << endl;
	cout << "Days in year before day you were born: " << nbefore << endl;

	cout << "Days in year left after due date: " << nafter << endl;



	int years_ = in_between_years - 1;

	int month_, days_;

	age_calc(birth_month, birth_day, birth_year, due_month, due_day, due_year);


}
