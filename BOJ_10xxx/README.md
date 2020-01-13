목록
----

**BOJ_10809**[알파벳 찾기](https://www.acmicpc.net/problem/10809)
```c
for (int i = 0; i < size; i++) {
    int s = int(str[i] - 'a');
    if (A[s] == -1)
        A[s] = i;
}
- A[0..25]에 a~z가 처음 나타난 위치를 저장한다. 
```

**BOJ_10942**[팰린드롬?](https://www.acmicpc.net/problem/10942)
```c
- 동적계획법으로 짧은 길이에서 긴 길이의 팰린드롬으로 모든 팰린드롬 유무를 저장한뒤 출력해주면 되는 문제.
- 출력시 시간 소모를 줄여야 통과 가능.
```
