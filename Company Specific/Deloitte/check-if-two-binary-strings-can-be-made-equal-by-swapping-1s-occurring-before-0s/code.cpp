// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Function to check if it is possible to make
// two binary strings equal by given operations
void isBinaryStringsEqual(string str1, string str2)
{

	// Stores count of 1's and 0's
	// of the string str1
	int str1Zeros = 0, str1Ones = 0;

	// Stores count of 1's and 0's
	// of the string str2
	int str2Zeros = 0, str2Ones = 0;

	int flag = 0;

	// Stores current count of 1's
	// presenty in the string str1
	int curStr1Ones = 0;

	// Count the number of 1's and 0's
	// present in the strings str1 and str2
	for (int i = 0; i < str1.length(); i++) {

		if (str1[i] == '1') {
			str1Ones++;
		}

		else if (str1[i] == '0') {
			str1Zeros++;
		}

		if (str2[i] == '1') {
			str2Ones++;
		}

		else if (str2[i] == '0') {
			str2Zeros++;
		}
	}

	// If the number of 1's and 0's
	// are not same of the strings str1
	// and str2 then print not possible
	if (str1Zeros != str2Zeros && str1Ones != str2Ones) {
		cout << "Not Possible";
	}

	else {

		// Traversing through the
		// strings str1 and str2
		for (int i = 0; i < str1.length(); i++) {

			// If the str1 character not
			// equals to str2 character
			if (str1[i] != str2[i]) {

				// Swaps 0 with 1 of the
				// string str1
				if (str1[i] == '0' && curStr1Ones > 0) {
					str1[i] = '1';
					curStr1Ones--;
				}

				// Breaks the loop as the count
				// of 1's is zero. Hence, no swaps possible
				if (str1[i] == '0' && curStr1Ones == 0) {

					flag++;
					break;
				}

				// Swaps 1 with 0 in the string str1
				if (str1[i] == '1' && str2[i] == '0') {

					str1[i] = '0';
					curStr1Ones++;
				}
			}
		}

		if (flag == 0) {
			cout << "Possible";
		}

		// Print not possible
		else {
			cout << "Not Possible";
		}
	}
}

// Driver Code
int main()
{
	// Given Strings
	string str1 = "0110";
	string str2 = "0011";

	// Function Call
	isBinaryStringsEqual(str1, str2);

	return 0;
}

