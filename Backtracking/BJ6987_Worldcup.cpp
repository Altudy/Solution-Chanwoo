#include<iostream>
using namespace std;

bool checkAvailable(int Test[6][3], int th);
//Return: True, If Test[6][3] is possible result.

//0: A, 1: B, 2: C, 3: D, 4: E, 5: F <- represent match using 2 array.
int T1[] = { 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 3, 3, 4 };
int T2[] = { 1, 2, 3, 4, 5, 2, 3, 4, 5, 3, 4, 5, 4, 5, 5 };

int main() {

	int Case[4][6][3];

	//Input
	for (int test = 0; test < 4; test++) {
		for (int team = 0; team < 6; team++) {
			for (int i = 0; i < 3; i++) {
				cin >> Case[test][team][i];
			}
		}
	}

	//Output
	for (int i = 0; i < 4; i++) {
		if (checkAvailable(Case[i], 0))
			cout << 1 << " ";
		else
			cout << 0 << " ";
	}

	return 0;
}

bool checkAvailable(int Test[6][3], int th) {
	if (th == 15) {
		bool last = true;
		for (int i = 0; i < 6; i++) 
			for (int j = 0; j < 3; j++) 
				if (Test[i][j] != 0) 
					last = false;
		return last;
	}

	bool ch1(false), ch2(false), ch3(false);

	//win case
	if (Test[T1[th]][0] > 0 && Test[T2[th]][2] > 0) {
		--Test[T1[th]][0];	--Test[T2[th]][2];
		ch1 = checkAvailable(Test, th + 1);
		++Test[T1[th]][0];	++Test[T2[th]][2];
	}


	//draw case
	if (Test[T1[th]][1] > 0 && Test[T2[th]][1] > 0) {
		--Test[T1[th]][1];	--Test[T2[th]][1];
		ch2 = checkAvailable(Test, th + 1);
		++Test[T1[th]][1];	++Test[T2[th]][1];
	}

	//lose case
	if (Test[T1[th]][2] > 0 && Test[T2[th]][0] > 0) {
		--Test[T1[th]][2];	--Test[T2[th]][0];
		ch3 = checkAvailable(Test, th + 1);
		++Test[T1[th]][2];	++Test[T2[th]][0];
	}

	return (ch1 || ch2 || ch3);
}
