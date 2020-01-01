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
