#include <string>
#include <cassert>

using namespace std;

//Get integer from string
int getIntFromString(size_t& pos, string str) {
	int final_int = 0;
	int current_number;

	//Loop through string until it ends or we no longer read a number
	for ( ; ; ) {
		//read in string building final_int step by step
		if (pos >= str.size())
			break;

		if (str.at(pos) >= '0' && str.at(pos) <= '9') {
			current_number = str.at(pos) - '0';
			final_int = (10 * final_int) + current_number;
		}
		else
			break;
		
		pos += 1;
		
	}
	return final_int;
}
//PDSI
bool isWellFormedGroceryOrderString(string grocerystring) {
	int pickup_count = 0, delivery_count = 0, total_count = 0, previous_int = 0;
	char current_letter = ' ';
	bool previous_is_number = false;
	if (grocerystring == "") 
		return false;
	//Loop through string testing for validity
	for (size_t pos = 0; pos < grocerystring.size(); pos++) {
		current_letter = grocerystring.at(pos);

		// Take this path if last read was a number or is the first read
		if (previous_is_number) {
			//Check for PDSI
			if (!(toupper(current_letter) == 'P' || toupper(current_letter) == 'D' || toupper(current_letter) == 'S' || toupper(current_letter) == 'I')) {
				return false;
			}
			if (toupper(current_letter) == 'P')
				pickup_count += previous_int;
			if (toupper(current_letter) == 'D')
				delivery_count += previous_int;
			previous_is_number = false;
		}

		// Take this path if last read was a letter
		else {
			if (!(current_letter > '0' && current_letter <= '9'))
				return false;

			previous_int = getIntFromString(pos, grocerystring);
			//previous_int updates pos... compensate for going too far
			pos = pos - 1;

			total_count += previous_int;
			previous_is_number = true;
		}
		//cout << "Position: "<< pos << endl;
		//check totals
		if (total_count > 99 || delivery_count > 10 || pickup_count > 20)
			return false;
	}
	if (previous_is_number)
		return false;
	return true;
}
int pickupCount(string grocerystring) {
	int previous_int = 0, count = 0;
	char current_letter = ' ';
	
	if (isWellFormedGroceryOrderString(grocerystring)) {
		for (size_t pos = 0; pos < grocerystring.size(); pos++) {
			current_letter = grocerystring.at(pos);
			if (current_letter >= '0' && current_letter <= '9') {
				previous_int = getIntFromString(pos, grocerystring);
				//previous_int updates pos... compensate for going too far
				pos = pos - 1;
			}
			else {
				if (toupper(current_letter) == 'P')
					count += previous_int;
				previous_int = 0;
			}
		}
		return count;
	}
	return -1;
}

int deliveryCount(string grocerystring) {
	int previous_int = 0, count = 0;
	char current_letter = ' ';

	if (isWellFormedGroceryOrderString(grocerystring)) {
		for (size_t pos = 0; pos < grocerystring.size(); pos++) {
			current_letter = grocerystring.at(pos);
			if (current_letter >= '0' && current_letter <= '9') {
				previous_int = getIntFromString(pos, grocerystring);
				//previous_int updates pos... compensate for going too far
				pos = pos - 1;
			}
			else {
				if (toupper(current_letter) == 'D')
					count += previous_int;
				previous_int = 0;
			}
		}
		return count;
	}
	return -1;
}

int shipCount(string grocerystring) {
	int previous_int = 0, count = 0;
	char current_letter = ' ';

	if (isWellFormedGroceryOrderString(grocerystring)) {
		for (size_t pos = 0; pos < grocerystring.size(); pos++) {
			current_letter = grocerystring.at(pos);
			if (current_letter >= '0' && current_letter <= '9') {
				previous_int = getIntFromString(pos, grocerystring);
				//previous_int updates pos... compensate for going too far
				pos = pos - 1;
			}
			else {
				if (toupper(current_letter) == 'S')
					count += previous_int;
				previous_int = 0;
			}
		}
		return count;
	}
	return -1;
}

int inpersonCount(string grocerystring) {
	int previous_int = 0, count = 0;
	char current_letter = ' ';

	if (isWellFormedGroceryOrderString(grocerystring)) {
		for (size_t pos = 0; pos < grocerystring.size(); pos++) {
			current_letter = grocerystring.at(pos);
			if (current_letter >= '0' && current_letter <= '9') {
				previous_int = getIntFromString(pos, grocerystring);
				//previous_int updates pos... compensate for going too far
				pos = pos - 1;
			}
			else {
				if (toupper(current_letter) == 'I')
					count += previous_int;
				previous_int = 0;
			}
		}
		return count;
	}
	return -1;
}

int main() {
	//cout << getIntFromString(0, "") << endl << getIntFromString(0, "0001") << endl << getIntFromString(2, "AB124GGg")
	//cout << toupper('a');
	
	assert(isWellFormedGroceryOrderString("happyDays10") == false);
	assert(isWellFormedGroceryOrderString("000001P") == false);
	assert(isWellFormedGroceryOrderString("+1P") == false);
	assert(isWellFormedGroceryOrderString("1p1d   XYZ") == false);
	assert(isWellFormedGroceryOrderString("10p10p10p1d1s1i") == false);
	assert(isWellFormedGroceryOrderString("5d5d5d1p1s1i") == false);
	assert(isWellFormedGroceryOrderString("50i50i50s") == false);
	assert(isWellFormedGroceryOrderString("1p1d1s1i") == true);
	assert(isWellFormedGroceryOrderString("5d5p") == true);
	assert(isWellFormedGroceryOrderString("1D10P4d4p") == true);
	assert(isWellFormedGroceryOrderString("PDSI") == false);
	assert(isWellFormedGroceryOrderString("P0DSI") == false);
	assert(isWellFormedGroceryOrderString("") == false);

	assert(pickupCount("5d5p") == 5);
	assert(pickupCount("1p1d1s1i") == 1);
	assert(pickupCount("5p1d1s1i6P") == 11);
	assert(pickupCount("1P3DpSI") == -1);

	assert(deliveryCount("5d5p") == 5);
	assert(deliveryCount("4D1d1s3d") == 8);
	assert(deliveryCount("5Fp1d1s1i6P") == -1);

	assert(shipCount("5d5p") == 0);
	assert(shipCount("1p1d1s1i") == 1);
	assert(shipCount("5d5d5d1p1s1i") == -1);

	assert(inpersonCount("5d5p ") == -1);
	assert(inpersonCount("") == -1);
	assert(inpersonCount("5p1d1s31i6P") == 31);
	assert(isWellFormedGroceryOrderString("1s1d1i1p1S1D1I1P") == true);
	assert(shipCount("1s1d1i1p1S1D1I1P") == 2);
	assert(deliveryCount("1s1d1i1p1S1D1I1P") == 2);
	assert(inpersonCount("1s1d1i1p1S1D1I1P") == 2);
	assert(pickupCount("1s1d1i1p1S1D1I1P") == 2);
	
	return 0;
}
