/*
5.스택 2개를 이용하여 정수를 저장하는 큐를 구현하시오.
기본적인 아이디어는 다음과 같다.

한 스택을 입력 스택, 다른 하나는 출력 스택으로 사용한다.
enqueue 명령의 경우, 입력 스택에 값을 넣는다.
dequeue 명령의 경우, 출력 스택의 값을 꺼낸다. 단, 출력 스택이 비어있다면 입력 스택의 모든 값을 출력 스택으로 옮긴 후에 값을 꺼낸다.
위와 같이 큐를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.
명령은 총 여섯 가지이다.

enqueue e: 주어진 요소 e를 큐의 맨 뒤에 추가한다.
dequeue: 큐가 비어있지 않으면 맨 앞 요소를 삭제하고 반환한다.
empty: 큐가 비어있으면 true를 아니면 false를 반환한다.
peek: 큐가 비어있지 않으면 맨 앞 요소를 삭제하지 않고 반환한다.
full: 큐가 가득 차 있으면 true을 아니면 false을 반환한다.
size: 큐의 모든 요소들의 개수를 반환한다.

첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다. 둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다. 주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다. 문제에 나와있지 않은 명령이 주어지는 경우는 없다.

출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.
큐의 크기는 100으로 한다.(MAX_QUEUE_SIZE = 100)
*/

// 무조건 그림 그려보면서 시도해 볼 것.
// 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
#define MAX_QUEUE_SIZE 100
#define Element int

Element data[2][MAX_STACK_SIZE]; // data[0]은 입력 스택, data[1]은 출력 스택

int top[2]; // top[0]은 입력 스택의 top, top[1]은 출력 스택의 top
// stack_num = 0이면 입력 스택, 1이면 출력 스택

void init_stack(int stack_num) 
{
    top[stack_num] = -1; // 스택 초기화
}
int is_empty_stack(int stack_num) 
{ 
    return top[stack_num] == -1; // 스택이 비어있는지 확인

}
int is_full_stack(int stack_num) 
{ 
    return top[stack_num] == MAX_STACK_SIZE - 1; // 스택이 가득 찼는지 확인
}
int size_stack(int stack_num) 
{ 
    return top[stack_num] + 1; // 스택의 크기 반환
}

void init_queue() { init_stack(0); init_stack(1); } // 큐 초기화, 입력 스택과 출력 스택 초기화
int is_empty_queue() {
    if (is_empty_stack(0) && is_empty_stack(1)) 
    {
        return 1; // 큐가 비어있으면 1 반환
    } 
    else 
    {
        return 0; // 큐가 비어있지 않으면 0 반환
    }
}
int is_full_queue()
{
    if (is_full_stack(0) || is_full_stack(1)) 
    {
        return 1; // 큐가 가득 차 있으면 1 반환
    } 
    else 
    {
        return 0; // 큐가 가득 차 있지 않으면 0 반환
    }
}

int size_queue() { return size_stack(0) + size_stack(1); } // 큐의 크기 반환

void push(Element item, Element stack_num)
{
    if(is_full_stack(stack_num))
        return;
    else data[stack_num][++top[stack_num]] = item; // 스택에 아이템을 추가
}

Element pop(Element stack_num)
{
    if (is_empty_stack(stack_num))
    {
        return -1; // 스택이 비어있으면 -1 반환
    }
    else
    {
        return data[stack_num][top[stack_num]--]; // 스택에서 아이템을 제거하고 반환
    }
                
}

Element peek(Element stack_num)
{
    if (is_empty_stack(stack_num))
    {
        return -1; // 스택이 비어있으면 -1 반환
    }
    else
    {
        return data[stack_num][top[stack_num]]; // 스택의 맨 위 아이템을 반환
    }
                
}


void enqueue(Element val)
{
    if (is_full_queue()!=1)
        push(val, 0);
    else
        return;

}
Element dequeue()
{
    if (is_empty_stack(1))
    {
        while (!is_empty_stack(0))
        {
            push(pop(0), 1);
        }
    }
    else if (is_empty_queue()==1)
        return -1;

    return pop(1);
}
Element peek_queue()
{
    if (is_empty_stack(1))
    {
        while (!is_empty_stack(0))
        {
            push(pop(0), 1);
        }
    }
    else if (is_empty_queue()==1)
        return -1;
    return peek(1);
}

int main(void)
{
    Element num;
    int n;
    char c[10];
    init_queue();
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", c);

        if (strcmp(c, "enqueue") == 0) { scanf("%d\n", &num); enqueue(num); }
        else if (strcmp(c, "dequeue") == 0)printf("%d\n", dequeue());
        else if (strcmp(c, "size") == 0) printf("%d\n", size_queue());
        else if (strcmp(c, "empty") == 0)printf("%d\n", is_empty_queue());
        else if (strcmp(c, "full") == 0)printf("%d\n", is_full_queue());
        else if (strcmp(c, "peek") == 0)printf("%d\n", peek_queue());
        else printf("error\n");
    }
    return 0;
}