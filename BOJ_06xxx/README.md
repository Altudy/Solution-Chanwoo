목록
-----

**BOJ_6603**[로또](https://www.acmicpc.net/problem/6603)
```
- {1, ... , 49}의 부분집합에서 6개를 고르는 조합수를 구하는 문제. 여러가지 방법으로 풀이가 가능할것 같다.
- #define FOR(i, in, s) for(int i= in; i < s; i++) //To ease distinguish index. 매크로 연습
- 재귀함수를 이용한 풀이 -> BJ6603_recur.cpp
```

**BOJ_6603(2)**[로또](https://www.acmicpc.net/problem/6603)_재귀풀이
```c
//몇번째 고르는 숫자인지에 따라 제한이 있어야 했다. 예를 들어 1 2 3 4 5 6에서 첫번째 고르는 숫자는 1밖에 안된다.
//그렇지 않으면 나머지 5개의 숫자를 고를수 없기 때문이다. 
//이 조건을  __i <= N - 6 + picked__ 로 해결했다.
for (i = index; i <= N - 6 + picked; i++) { 
		Six[picked] = K[i];
		S(picked + 1, i + 1);
		Six[picked] = 0;
	}

```


**BOJ_6987**: [월드컵](https://www.acmicpc.net/problem/6987)
```
- 접해본 첫 Backtracking문제
- 모든 경우의 수를 접근하며 비교하기엔 연산이 많아지므로 순서가 있는 15경기를 승, 무, 패로 쪼개어 접근하며 찾는다.
```



