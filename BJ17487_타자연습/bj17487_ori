#include <iostream>
#include <string>
using namespace std;

static int num_shift(0), num_SP(0), left(0), right(0);

void detect(char item);

int main() {
	string Str;
	getline(cin, Str);

	for (int i = 0; i < Str.size(); i++) {
		detect(Str[i]);
		//cout << (int)Str[i] << endl;
	}



	int common = ::num_shift + ::num_SP;
	while (common != 0) {
		if (::left <= ::right)
			::left++;
		else
			::right++;
		common--;
	}

	cout << ::left << " " << ::right;

	return 0;
}

void detect(char item) {
	if ((item >= 65) && (item <= 90)) {
		item += 32;
		::num_shift++;
	}

	if ((item >= 97) && (item <= 122)) {
		switch (item)
		{
		case 'q':
		case 'w':
		case 'e':
		case 'r':
		case 't':
		case 'y':
		case 'a':
		case 's':
		case 'd':
		case 'f':
		case 'g':
		case 'z':
		case 'x':
		case 'c':
		case 'v':
		case 'b':
			::left++; break;
		case 'u':
		case 'i':
		case 'o':
		case 'p':
		case 'h':
		case 'j':
		case 'k':
		case 'l':
		case 'n':
		case 'm':
			::right++; break;
		}
	}
	else if (item == 32)
		::num_SP++;
}
