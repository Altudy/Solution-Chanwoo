목록
-----

**BOJ_3671**: [산업 스파이의 편지](https://www.acmicpc.net/problem/3671)
```
- 테스트 케이스가 서로 영향을 끼치지 않는다면, Initialize방식으로 모든 정보를 저장하지 않는게 깔끔하다.
- 순열을 구현하는 여러가지 방식을 배울 수 있었다. 다른 사람의 좋은 풀이를 많이 참고해서 적용해보자. (ing)
-     1. 이미 뽑힌 index를 true로 가지는 bool 배열을 가지고 반복문돌리기
-     2. bit 연산자를 이용한 순열 구현_신박..
- 소수 판별 알고리즘을 구현하는 방법도 여러가지가 있더라.
```

**BOJ_3080**: [아름다운 이름](https://www.acmicpc.net/problem/3080)
```c
- 트라이 구조를 생각하고 들어가야 하지만, 입력이 크기 때문에, 트라이 자료구조를 그대로 구현하면 메모리 초과가 무조건 뜬다.
- recursion으로 정렬된 문자열들을 탐색하며 답을 구해야 한다. 입출력에 시간을 줄이는 방법들을 배웠다.
    char input[1 << 20];
    setvbuf(stdin, input, _IOFBF, sizeof(input));
    
    typedef struct _str {
        char str[3001];
    }STR;
```
