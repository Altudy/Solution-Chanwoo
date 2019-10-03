#include <stdio.h>
int num1, num2;
int main() {

	while (1) {
		scanf("%d %d", &num1, &num2);
		if (num1 == 0 && num2 == 0)	break; //while-loop ends if input is "0 0". 

		if (num1 % num2 == 0)
			puts("multiple");
		else if (num2%num1 == 0)
			puts("factor");
		else
			puts("neither");
	}

	return 0;
}
