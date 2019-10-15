#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
using namespace std;
 
int main() {
	ios::sync_with_stdio(false);
	string str, ans;
 
	getline(cin, str);
	transform(str.begin(), str.end(), str.begin(), ::tolower); //C++17~
	//iterator가 arg1이 arg2까지 1씩 증가되며 arg4에 적용된 unary or binary operation을 적용시킨다.
	//각 return 값은 arg3이 가리키는 장소에 저장되며 똑같이 1씩 증가한다.
 
	for (int i = 0; i < str.size(); i++) {
 
		// if str[i] is vowel, continue;
		if (!(str[i] == 'a' || str[i] == 'o' || str[i] == 'y' || str[i] == 'e' || str[i] == 'u' || str[i] == 'i'))
			ans += str[i];
			// else lowercase alpha is appended to answer.
	}
 
	for (int i = 0; ans[i] != '\0'; i++)
		cout << "." << ans[i];
 
	return 0;
}
