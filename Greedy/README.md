목록
-----

**CF160A**: [Twins](https://codeforces.com/contest/160/problem/A)
```
- 주어진 Coin을 정렬한 다음, 값이 큰 Coin부터 하나씩 집고, 집을때마다 내 몫이 남은 코인들의 합보다 큰지 검사해준다.
```

**BJ1931**: [회의실 배정](https://www.acmicpc.net/problem/1931)
```
- 회의 시작, 끝남시간이 0이상 2^32-1미만이었으므로 unsigned int pair로 배열저장.
- Induction Basis: 단위시간 0일 때는 당연히 optimal하다
- Induction Hypothesis: 단위시간 i번째에 가장빨리 끝나는 회의를 택한 것이 유망하다고 가정
- Induction Step: 만약 단위시간 i에서 i+1 까지 걸쳐있는 회의가 존재하지 않는다면, 무조건 optimal하다.
- 만약 존재한다고 해도, i번째에 끝나는 회의를 택했을때에 회의 개수가 i+1까지 걸쳐있는 회의를 택했을 때보다 크거나 같다.
- 때문에 매 i단위시간에 끝나는 회의를 택하고 다음 가능한 회의 시작시간에서 부터 다시 가장 빨리 끝나는 회의를 택하는 것보다 회의개수가 큰 어떤 집합은 존재하지 않는다.
```

**BJ5585**: [거스름돈](https://www.acmicpc.net/problem/5585)
```
- 그때그때 가장 큰 동전을 먼저 집어 count한다.
```

**BJ11047**: [동전 0](https://www.acmicpc.net/problem/11047)
```
- 준규가 가지고 있는 동전이 배수로 증가한다는 조건으로 인해 Greedy algorithm사용가능.
```

**BJ11399**: [ATM](https://www.acmicpc.net/problem/11399)
```
- i번째 손님이 기다려야 하는 시간은 바로 (전사람이 기다려야 하는 시간 + 자신이 업무를 보는데에 드는 시간) 임을 파악
- 그때 그때 처리시간이 가장 짧은 사람을 고르는 것이 optimal하다.
```


