LIST
----

[E - Crested Ibis vs Monster](https://atcoder.jp/contests/abc153/tasks/abc153_e)
```c
- 동적계획법 : 매 입력으로 주어지는 A, B에 대해 0..H까지 소모되는 cost를 업데이트한다.

  for (int i = 0; i < a; i++)
      Min(dp[i], b);
  for (int i = a; i <= H; i++)
      Min(dp[i], dp[i - a] + b);
            
- DFS로 풀어보았는데, dp[0] != 0일 때 생기는 예외를 어떻게 해결해야 할지 모르겠다.
```
[F - Silver Fox vs Monster](https://atcoder.jp/contests/abc153/tasks/abc153_f)
```c
- 그리디로 접근하는 것은 그려졌지만,
- 폭탄이 터지는 범위의 원소를 매번 검사하여 갱신시키는 것이 시간초과를 야기하였다.
- E번도 그렇고 153 contest는 동적계획법을 적절히 응용해야하는 문제들이 많았다.
[핵심]
  D.assign(n + 1, 0);
  for (int i = 0; i < n; i++) {
      if (D[i] < M[i].second) {
          ll rest = M[i].second - D[i];
          ll bound = M[i].first + 2 * d;
          ans += rest;
          D[i] += rest;
          int p = upper_bound(all(M), pll{ bound, INF }) - M.begin(); 
          D[p] -= rest;
      }
      D[i + 1] += D[i]; 
  }
```
