#include <iostream>
#include <string>
using namespace std;

//Check if filing is viable
bool viable_filing(string status) {
	if (status == "Single" || status == "Married" || status == "Head of Household")
		return true;
	return false;
}

int main() {
	string filingStatus, trash = "";
	int income, children;

	// Check if filing viable
	cout << "What is your filing status? ";
	getline(cin, filingStatus);
	if (!viable_filing(filingStatus)) {
		cout << "Error - Invalid filing status.";
		return(0);
	}

	// Check if income viable
	cout << "What is your adjusted gross income? ";
	cin >> income;
	getline(cin, trash);
	if (income < 0 || cin.fail() || trash != "") {
		cout << "Error - Invalid income.";
		return(0);
	}
	// Check if number of dependents viable
	cout << "How many children under the age of 17 did you claim as a dependent? ";
	cin >> children;
	getline(cin, trash);
	if (children < 0 || cin.fail() || trash != "") {
		cout << "Error - Invalid number of dependents.";
		return(0);
	}

	// Define base amounts based on filing status
	int limit = 0, payment = 0, basePay = 0;
	if (filingStatus == "Single") {
		limit = 75000;
		basePay = 1200;
	}
	if (filingStatus == "Married") {
		limit = 150000;
		basePay = 2400;
	}
	if (filingStatus == "Head of Household") {
		limit = 112500;
		basePay = 1200;
	}
	
	// Calculate amount owed based on base amounts
	int leftover = income - limit;
	if (leftover <= 0)
		payment = basePay + (500*children);
	else
		payment = basePay - (leftover / 100 * 5) + (500 * children);

	if (payment < 0)
		payment = 0;

	// Output results
	cout << "Your stimulus check is $" << payment << ".";

	return(0);
}