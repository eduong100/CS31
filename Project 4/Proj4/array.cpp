#include <iostream>
#include <cassert>
#include <string>
using namespace std;

int locateMinimum(const string array[], int n) {
	if (n <= 0) return -1;
	int indexOfMin = 0;
	string Min = array[0];
	for (int i = 1; i < n; i++) {
		if (array[i] < Min) {
			Min = array[i];
			indexOfMin = i;
		}
	}
	return indexOfMin;
}
int countPunctuation(const string array[], int  n) {
	if (n <= 0)
		return -1;
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (size_t j = 0; j < array[i].size(); j++) {
			char cur = array[i].at(j);
			switch (cur) {
				case ',':
				case '.':
				case ';':
				case '-':
				case '?':
				case '!':
				case ':':
				case '(':
				case ')':
					count++;
			}
		}
	}
	return count;
}
//assuming palindromes count as their own reverse
string buildReverse(string str) {
	string reverse = "";
	for (size_t i = 0; i < str.size(); i++) {
		reverse = str[i] + reverse;
	}
	return reverse;
}
bool hasReverse(const string array[], int n) {
	if (n <= 0)
		return false;
	string check;
	for (int i = 0; i < n; i++) {
		check = array[i];
		for (int j = i; j < n; j++) {
			if (check == buildReverse(array[j]))
				return true;
		}
	}
	return false;
}
char highestOccurredCharacter(const string array[], int n, int index) {
	if (n <= 0 || index >= n || index < 0)
		return '\0';
	char highestOccurred = '\0', check;
	int highestOccurrences = 0;
	for (size_t i = 0; i < array[index].size(); i++) {
		int count = 0;
		check = array[index].at(i);
		for (size_t j = 0; j < array[index].size(); j++) {
			if (array[index].at(j) == check)
				count++;
		}
		if (count > highestOccurrences) {
			highestOccurred = array[index].at(i);
			highestOccurrences = count;
		}
	}
	return highestOccurred;
}
bool isInIncreasingOrder(const string array[], int  n) {
	if (n <= 0) return false;
	string previous = array[0], current = "";
	for (int i = 1; i < n; i++) {
		current = array[i];
		if (current <= previous)
			return false;
		previous = current;
	}
	return true;
}
char firstNonRepeatedCharacter(const string array[], int n, int index) {
	if (n <= 0 || index >= n || index < 0)
		return '\0';
	char check;
	for (size_t i = 0; i < array[index].size(); i++) {
		int count = 0;
		check = array[index].at(i);
		for (size_t j = 0; j < array[index].size(); j++) {
			if (array[index].at(j) == check)
				count++;
		}
		if (count == 1)
			return array[index].at(i);
	}
	return '\0';
}
bool isOnlyDigits(const string array[], int n) {
	if (n <= 0) return false;
	int stringSize = 0;
	for (int i = 0; i < n; i++) {
		stringSize = array[i].size();
		if (array[i] == "")
			return false;
		for (int j = 0; j < stringSize; j++) {
			if (!(array[i].at(j) >= '0' && array[i].at(j) <= '9')) 
				return false;
		}
	}
	return true;
}
int main() {
	string a[6] = { "123", "456", "789", "13423", "1e44", "2359" };
	string people[5] = { "jon", "mamabbcc!", "samwell,", "daenerys.", "tyrion" };
	string folks[8] = {
		"samwell", "jon", "margaery", "daenerys",
		"tyrion", "sansa", "llewmas", "noj"
	};
	string b[5] = { "5", "4", "3", "2", "15" };
	string single[1] = { "racecar" };
	string empty[4] = { "", "123", "", "55445" };

	assert(isOnlyDigits(a, 6) == false);
	assert(isOnlyDigits(a, 3) == true);
	assert(isOnlyDigits(single, 1) == false);
	assert(isOnlyDigits(a, -1) == false);
	assert(isOnlyDigits(empty, 4) == false);

	assert(isInIncreasingOrder(people, 3) == true);
	assert(isInIncreasingOrder(people, 5) == false);
	assert(isInIncreasingOrder(single, 1) == true);
	assert(isInIncreasingOrder(single, 0) == false);
	assert(isInIncreasingOrder(empty, 4) == false);

	assert(locateMinimum(people, 5) == 3);
	assert(locateMinimum(single, 1) == 0);
	assert(locateMinimum(single, -2) == -1);
	assert(locateMinimum(empty, 4) == 0);

	assert(firstNonRepeatedCharacter(people, 5, 0) == 'j');
	assert(firstNonRepeatedCharacter(people, 5, 1) == '!');
	assert(firstNonRepeatedCharacter(single, 1, 0) == 'e');
	assert(firstNonRepeatedCharacter(single, 1, -1) == '\0');
	assert(firstNonRepeatedCharacter(empty, 4, 0) == '\0');
	assert(firstNonRepeatedCharacter(empty, 4, 3) == '\0');

	assert(countPunctuation(people, 5) == 3);
	assert(countPunctuation(people, 1) == 0);
	assert(countPunctuation(single, 1) == 0);
	assert(countPunctuation(single, -1) == -1);
	assert(countPunctuation(empty, 4) == 0);

	assert(highestOccurredCharacter(people, 5, 0) == 'j');
	assert(highestOccurredCharacter(people, 5, 2) == 'l');
	assert(highestOccurredCharacter(single, 1, 0) == 'r');
	assert(highestOccurredCharacter(single, -1, 0) == '\0');
	assert(highestOccurredCharacter(empty, 4, 0) == '\0');

	assert(hasReverse(folks, 8) == true);
	assert(hasReverse(people, 5) == false);
	assert(hasReverse(single, 1) == true);
	assert(hasReverse(single, -1) == false);
	assert(hasReverse(empty, 4) == true);
	//cout << isInIncreasingOrder(b, 0);
	//cout << highestOccurredCharacter(people, 5, 2);
	return 0;
}

/*if (cur == ',' || cur == '.' || cur == ';' || cur == '-' || cur == '?' ||
	cur == '!' || cur == ':' || cur == '(' || cur == ')')
	count++; */