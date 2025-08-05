/*
1. 문제 설명
정수를 저장하는 스택을 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.
명령은 총 다섯 가지이다.

push : 정수 num을 스택에 넣는 연산이다.
pop : 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size : 스택에 들어있는 정수의 개수를 출력한다.
empty : 스택이 비어있으면 1, 아니면 0을 출력한다.
peek : 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 –1을 출력한다.

첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다. 둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다. 주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다. 문제에 나와있지 않은 명령이 주어지는 경우는 없다.

출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef int element;
element data[MAX_STACK_SIZE];
int top;

void init_stack() { top = -1; }
int is_empty() 
{ 
    if (top == -1) {
        return 1; // 스택이 비어있음
    } else {
        return 0; // 스택이 비어있지 않음
    }
}
int is_full() 
{
    if (top == MAX_STACK_SIZE - 1){
        return 1; // 스택이 가득 참
    } 
    else {
        return 0; // 스택이 가득 차지 않음
    }        
}
int size() 
{
    return top + 1; // 스택에 들어있는 정수의 개수, top이 -1이면 스택이 비어있음 => top+1이라고 생각하면 됨
}
void push(element item)
{
	if (is_full()){
        printf("error\n"); // 스택이 가득 찼을 때 에러 출력
        return; // void 함수는 return; 하면 종료함.
    }
	else {
        top++;
        data[top] = item; // 스택에 아이템을 추가
        return; // void 함수는 return; 하면 종료함. 
        // 같은 표현으로 data[++top] = item; 도 가능
    }
}
element pop()
{
	if (is_empty()){
        return -1; // 에러일 때, int형 함수는 -1을 반환
    }
	else{
        int item = data[top]; // 스택의 가장 위에 있는 아이템을 저장
        top--; // 스택에서 아이템 제거, // top이 -1이 되면 스택이 비어있음
        // 메모리적으로는 스택 배열에 값이 남아있긴 함. 
        // 하지만 top이 그 위치보다 하나 작은 인덱스를 가리키므로 기존 top 위치는 스택에 들어있는 영역으로 간주되지 않음.
        // 따라서 스택의 크기가 줄었다고 생각. 또한 스택의 크기가 줄어도 메모리적으로는 기존 아이템이 남아있음. 
        // 그래서 그 위치를 다시 push로 사용하면 기존 아이템이 덮어쓰여짐.
        // 스택에서 아이템을 제거한다는 의미는 "논리적인 제거"이고, "물리적인 제거"는 아님.
        return item; // 아이템 반환
    }
}
element peek()
{
	if (is_empty()){
        return -1; // 스택이 비어있을 때 -1 반환
    }
    else {
        return data[top]; // 스택의 가장 위에 있는 아이템 반환
    }	
}

int main(void)
{
	element num;
	int n;
	char c[10];
	scanf("%d", &n);
    init_stack();
	for (int i = 0; i < n; i++)
	{
		scanf("%s", c);
		
		if (strcmp(c, "push") == 0) { scanf("%d\n", &num); push(num); }
		else if (strcmp(c, "pop") == 0)printf("%d\n", pop());
		else if (strcmp(c, "size") == 0) printf("%d\n", size());
		else if (strcmp(c, "empty") == 0)printf("%d\n", is_empty());
		else if (strcmp(c, "peek") == 0)printf("%d\n", peek());
		else printf("error\n");
	}
	return 0;
}
