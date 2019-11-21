목록
-------
**CF_01A**[Theatre Square](http://codeforces.com/problemset/problem/1/A)
```
- m*n직사각형을 a*a정사각형으로 덮어야하고, 넘치는건 괜찮으나 부족하면 안된다.
- 매우 쉬운 문제였지만 각 입력의 범위가 1<= m,n,a <= 10^9 였으므로 m,n이 10^9, a가 1일 경우 답이 10^18까지 나올 수 있기 때문에
- 변수와 함수의 반환 type을 long long으로 해주어야 한다.
```

**CF_04C**[Registration system](http://codeforces.com/contest/4/problem/C)
```
- 처음에, 문제 요구사항이 적절한 hashing인줄 알았는데, STL의 map 클래스로 아주 간단히 해결가능하였다.
- 그래서 map과 hashed_map의 차이점이 있을까 하여 알아봤는데 간략히 다음과 같은 다른점이 있다.
# A map requires O(log(N)) time for inserts and finds operations, 
# as it's implemented as a Red-Black Tree data structure.
# An unordered_map requires an 'average' time of O(1) for inserts and finds, 
# but is allowed to have a worst - case time of O(N).This is because it's implemented using Hash Table data structure.
```

**CF_96A**[Football](http://codeforces.com/problemset/problem/96/A)
```
- 난이도0. 복잡도O(N)
- 문자열 1개를 입력으로 받고 첫번째 문자부터 차례로 훑으며 7개 이상의 중복이 있는지 검사하여 끝까지 간다.
```


