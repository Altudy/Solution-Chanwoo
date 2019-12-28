목록
-------
**CF_1279A**[New Year Garland](http://codeforces.com/contest/1279/problem/A)
```
- 연속된 색깔의 램프가 나올수 밖에 없는 경우는 하나의 색깔이 격순으로 나오게 해도 충분치 않은 경우이다.
- 그 말은 제일 숫자가 많은 램프가 나머지 두 색깔 합보다 더 많은 경우이고 정확히는 하나를 더 초과하여 많은 경우이다.
```


**CF_1279B**[Verse For Santa](http://codeforces.com/contest/1279/problem/B)
```
- 스킵할수 있는 cite가 최대 1개인 것을 잘못 이해하여 풀지 못했던 문제이다.
- TIP1 : 모든 cite를 암송할 수 있을 때는 0을 출력하는데, 이는 입력과 동시에 sum에 더하여 마지막에 sum을 확인해주면 된다.
- TIP2 : 순서대로 cite 가중치를 더해갈 때 마지막에 더한 cite를 빼야하는지, 
        아니면 그동안 최대였던 max_cite를 빼야하는지 마지막에 구분해주어야 했다.
```
