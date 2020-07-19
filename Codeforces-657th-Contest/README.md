List
-----

[Codeforces-657th-Contest](https://codeforces.com/contest/1379)

**A_Acacius and String.cpp**
```
1. 문제를 구현하기 전에 알고리즘을 구상하지 않았다.
2. 2가지 분기점을 고려했다.
  a. ?를 대체하기 전의 'abacaba' 개수를 count.
  b. ?를 대체하기 전, 하나도 포함되어 있지 않을 때, exactly once를 위반하지 않으면서 대체할 수 있는지.

3. 마지막까지 놓쳤던 부분: ?를 대체해서 문자열 'abacaba'를 만들었을 때, abacabacaba와 같은 문자열이 되어 1개만 포함할 수가 없는 상황을 고려하지 못함.
```

**B_Dubious Cyrpto**
```
1. n * a + b - c = m 이라는 식에서, 먼저 b-c는 l,r의 간격과 비례한다는 것을 먼저 알아낸다.
2. 그렇게 되면, 양의 정수 n과 a곱에 [l-r, r-l]구간 안의 정수를 더해 m을 구한다는 말이 된다.
3. (b-c)/a를 x로 두면, n = m/a + x 이고, a는 [l, r]구간 안의 정수이므로 구간 안의 모든 정수를 검사해도 시간을 초과하지 않는다. 
```
