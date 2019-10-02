#include<ios>
int c, i, left, right, find, s;
char a[17] = "qwertyasdfgzxcvb";
int main() {
	while (~scanf_s("%c", &c)) { 
		// ~는 붙이지 않아도 동작, 그때 그떄 소멸시켜주기 위해?
		if (c == '\n') break; //공백이면 문장의 끝.
		if (c == ' ') { s++; continue; }
		for (i = find = 0; i < 17 && !find; i++)
			if (c == a[i]) find = 1;
			else if (c == a[i] - 'a' + 'A')	find = ++s;
			//대문자일때, 
		if (find) left++;
		else {
			right++;
			if (c < 'a') s++;
		}
	}
	while (s--) left > right ? right++ : left++;
	printf("%d %d", left, right);
}
