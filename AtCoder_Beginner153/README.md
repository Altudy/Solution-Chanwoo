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
