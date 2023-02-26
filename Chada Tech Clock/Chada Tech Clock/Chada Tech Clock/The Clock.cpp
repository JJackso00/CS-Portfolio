/* Project One: Chada Tech Clock
	Jasmine Jackson
	01/27/2023 */
#include <iostream>
#include <chrono>
#include <thread>
#include <tuple>
#include <iomanip>
using namespace std;

int userAdd;
int milHour;
int minute;
int hour;
int second;
bool quit = false;

string AMPM() {
	
	if ((milHour >= 12) && (milHour <= 23)) {
		
		return "  P.M.";
	
	}
	
	else {
		
		return "  A.M.";
	
	}
}

void formatMenu(int j, int k) {

	for (int m = 0; m < k; ++m) {
		for (int i = 0; i < j; ++i) {
			
			cout << "*";
		
		}
		
		cout << " ";
	
	}
}

tuple <int, int, int, int> timeCheck() {

	if (second >= 60) {
		
		second = 0;
		minute++;
	
	}

	if (minute >= 60) {
		
		hour++;
		milHour++;
		minute = 0;
	
	}

	if ((hour == 12) && (second > 59)) {
		
		hour = 1;
	
	}

	if (milHour >= 24) {
		
		milHour = 0;
	
	}

	return make_tuple(hour, minute, second, milHour);
}

void time12Hour() {

	cout << setfill('0') << setw(2) << get<0>(timeCheck()) << ":";
	cout << setfill('0') << setw(2) << get<1>(timeCheck()) << ":";
	cout << setfill('0') << setw(2) << get<2>(timeCheck()) << AMPM();
}

void time24Hour() {

	cout << setfill('0') << setw(2) << get<3>(timeCheck()) << ":";
	cout << setfill('0') << setw(2) << get<1>(timeCheck()) << ":";
	cout << setfill('0') << setw(2) << get<2>(timeCheck());
}

void printTime() {
	
	formatMenu(27, 2);
	cout << endl;
	cout << "*      12-Hour Clock      *   *      24-Hour Clock      *" << endl;
	cout << "*      ";
	time12Hour();
	cout << "      *" << "  *      ";
	time24Hour();
	cout << "      *" << endl;
	formatMenu(27, 2);
	
	cout << endl;
	this_thread::sleep_for(chrono::seconds(1));
}

void displayMenu() {
	
	formatMenu(27,2);
	cout << endl << "*      1-Add One Hour      *" << endl;
	cout << "*      2-Add One Minute      *" << endl;
	cout << "*      3-Add One Second      *" << endl;
	cout << "*      4-Exit Program      *" << endl;
	formatMenu(27, 2);

	cin >> userAdd;
	switch (userAdd) {
		case 1:
			hour++;
			milHour++;
			printTime();
			break;
		case 2:
			minute++;
			printTime();
			break;
		case 3:
			second++;
			second--;
			printTime;
			break;
		case 4:
			cout << "Exiting Clock..." << endl;
			quit = true;
			break;
	}
}

int main() {
	
	while (!quit) {
		
		printTime();
		displayMenu();
	
	}
	
	return 0;
}