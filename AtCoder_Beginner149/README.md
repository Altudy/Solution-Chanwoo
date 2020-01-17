콘테스트 링크 -> [여기](https://atcoder.jp/contests/abc149)

A - Strings
- 두 문자열을 역순으로 붙이는 게 다였던 간단한 문제.

B - Greedy Takahashi

C -	Next Prime

D	- Prediction and Restriction

E	- Handshake
```
- 악수가능한 유명인사의 수가 최대 10^5였기 때문에 그리디알고리즘으로 접근하려고 하면 10^5 * 10^5에 가까운 경우의 수를 검사해야한다.
- 시간초과를 피할수 없으므로 1쌍의 최소, 최대합 0 ~ 200000에서 시작해서 그 사이에 M개의 짝을 갖는 중간점을 찾는다.
  for (int p1 = 0; p1 < N; p1++) {
      while (p2 >= 0 && A[p1] + A[p2] < mid) p2--;
      cnt += p2 + 1;
  } -> 빠르게 중간점까지의 짝 개수를 구할 수 있다.

```

F	- Surrounded Nodes
