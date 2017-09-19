#include <iostream>
#include <string>
#include "functions.cpp"
using namespace std;

string printbackwards(const string &thing, const int &length);

short whichisbigger(const string &num1, const string &num2, short which_is_neg);

string addemup(const string &num1, const string &num2, bool negate);

string subtractem(const string &num1, const string &num2, bool negate);

int main()
{
	cout << "Welcome to the most powerful bignum calculator there is!\nEnter 2 giant Integers for adding, subtracting, or multiplying! \n";
	cout << "Example: 5 + 6. \nDon't forget to press 'q' when finished!\n\n";
	while(true) {
		string num1,num2;
		char operation;
		cin >> num1;
		if (num1 == "q")
			break;
		cin >> operation;
		cin >> num2;
		if (operation == '-')
			num2 = operation + num2;
		if (operation != '*') {
			if (num1[0] != '-' && num2[0] != '-')
				cout << addemup(num1, num2, false);
			else if (num1[0] == '-' && num2[0] == '-')
				cout << addemup(num1, num2, true);
			else if (num1[0] == '-') {
				short comparisonResult = whichisbigger(num1, num2, 1);
				if (comparisonResult == 0)
					cout << subtractem(num1, num2, true);
				else if (comparisonResult == 1)
					cout << subtractem(num2, num1, false);
				else
					cout << 0;
			}
			else if (num2[0] == '-') {
				short comparisonResult = whichisbigger(num1, num2, 2);
				if (comparisonResult == 0)
					cout << subtractem(num1, num2, false);
				else if (comparisonResult == 1)
					cout << subtractem(num2, num1, true);
				else
					cout << 0;
			}
		}
		else {
			bool negmult = false;
			string acc = num1;
			if (acc[0] == '-')
				negmult = true;
			while (true) {
				if (num2 == "1") {
					cout << acc;
					break;
				}
				if (negmult)
					acc = addemup(acc, num1, true);
				else
					acc = addemup(acc, num1, false);
				num2 = subtractem(num2, "1", false);
			}
		}
			
		cout << "\n";
	}
}