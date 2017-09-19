#include <iostream>
#include <string>
using namespace std;

string printbackwards(const string &thing, const int &length) {
	string returnvalue;
	unsigned int redundantcut = 0;
	for (long int x = length-1; x > -1; x--) {
		if (thing[x] == '0')
			redundantcut += 1;
		else
			break;
	}
	for (long int i = length-1-redundantcut; i > -1; i--)
		returnvalue += thing[i];
	return returnvalue;
}

short whichisbigger(const string &num1, const string &num2, short which_is_neg) {
	unsigned long lennum1 = num1.length();
	unsigned long lennum2 = num2.length();
	if (which_is_neg == 1)
		lennum1 -= 1;
	if (which_is_neg == 2)
		lennum2 -= 1;
	if (lennum1 > lennum2)
		return 0;
	else if (lennum1 < lennum2)
		return 1;
	else {
		for (unsigned long i = 0; i < lennum1; i++) {
			short diff;
			if (which_is_neg == 1)
				diff = static_cast<short> (num1[i+1]) - static_cast<short> (num2[i]);
			else
				diff = static_cast<short> (num1[i]) - static_cast<short> (num2[i+1]);
			if (diff > 0)
				return 0;
			else if (diff < 0)
				return 1;
			else if (diff == 0 && i == (lennum1 - 1))
				return 2;

		}
	}

}

string addemup(const string &num1, const string &num2, bool negate) {
	short endpoint = 0;
	if (negate)
		endpoint = 1;
	string finalresult;
	long num1pt = (num1.length()) - 1;
	long num2pt = (num2.length()) - 1;
	bool overflow = false;
	while (true) {
		if (num1pt < endpoint && num2pt < endpoint) {
			if (overflow)
				finalresult += '1';
			break;
		}
		else {
			short minicalc;
			if (num1pt >= endpoint && num2pt >= endpoint) {
				minicalc = static_cast<short> (num1[num1pt]) + static_cast<short> (num2[num2pt]) - 96;
			}
			else if (num1pt < endpoint) {
				if (overflow) {
					minicalc = static_cast<short> (num2[num2pt]) - 48;
				}
				else {
					minicalc = -1;
					finalresult += num2[num2pt];
				}
			}
			else {
				if (overflow) {
					minicalc = static_cast<short> (num1[num1pt]) - 48;
				}
				else {
					minicalc = -1;
					finalresult += num1[num1pt];
				}
			}
			if (minicalc >= 0) {
				if (overflow) {
					minicalc = minicalc + 1;
					overflow = false;
				}
				if (minicalc > 9) {
					overflow = true;
					minicalc -= 10;

				}
				finalresult += to_string(minicalc)[0];
			}
			num1pt -= 1;
			num2pt -= 1;
		}


	}
	if (negate)
		return '-' + printbackwards(finalresult, finalresult.length());
	else
		return printbackwards(finalresult, finalresult.length());
}

string subtractem(const string &num1, const string &num2, bool negate) {
	short endpoints[2] = { 0,0 };
	if (num1[0] == '-')
		endpoints[0] = 1;
	if (num2[0] == '-')
		endpoints[1] = 1;
	string finalresult;
	long num1pt = (num1.length()) - 1;
	long num2pt = (num2.length()) - 1;
	bool overflow = false;
	while (true) {
		if (num1pt < endpoints[0] && num2pt < endpoints[1])
			break;
		else {
			short minicalc;
			if (num1pt >= endpoints[0] && num2pt >= endpoints[1]) {
				short topnum, bottomnum;
				topnum = static_cast<short> (num1[num1pt]) - 48;
				bottomnum = static_cast<short> (num2[num2pt]) - 48;
				if (overflow) {
					topnum -= 1;
					overflow = false;
				}
				if (topnum < bottomnum) {
					topnum += 10;
					overflow = true;
				}
				minicalc = topnum - bottomnum;
				finalresult += to_string(minicalc)[0];

			}
			else {
				if (overflow) {
					minicalc = static_cast<short> (num1[num1pt]) - 48;
					minicalc -= 1;
					finalresult += to_string(minicalc)[0];
					overflow = false;
				}
				else {
					finalresult += num1[num1pt];
				}
			}
		}
		num1pt -= 1;
		num2pt -= 1;
	}
	if (negate)
		return '-' + printbackwards(finalresult, finalresult.length());
	else
		return printbackwards(finalresult, finalresult.length());
}