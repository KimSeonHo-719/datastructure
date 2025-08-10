/*
3.

문제 설명
강의 자료에 나와 있는 알고리즘을 참고하여 후위 표기 수식을 계산 해 주는 프로그램을 만들어봅시다.

첫 번째 줄에 후위 표기 방식으로 입력이 들어간다.
입력과 출력의 숫자들은 모두 정수로 나타내며 연산자는 ‘+’, ‘-’, ‘*’, ‘/’, ‘(’, ‘)’로 이루어져 있다.
각각의 문자들은 띄어쓰기로 구분한다. ( ex. 1024 V 3 V 5 V + V 2 V 2 V + V - V * V 2 V 4 V + V 10 V + V 32 V * V / )

출력은 후위 표기 형태가 표시된 후 다음 줄에 계산한 값이 정수로 표시된다.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef int element;
element data[MAX_STACK_SIZE];
int top;

void init_stack() { top = -1; }
int is_empty()
{
    if (top == -1)
        return 1; // 스택이 비어있음
    else
        return 0; // 스택이 비어있지 않음
                
}
int is_full()
{
    if (top == MAX_STACK_SIZE - 1)
        return 1; // 스택이 가득 참
    else
        return 0; // 스택이 가득 차지 않음
        
}
int size() 
{ 
    return top + 1;

}
void push(element item)
{
    if (is_full())
        return;
    else
        data[++top] = item; // 스택에 아이템을 추가
}
element pop()
{
    if(is_empty())
        return -1; // 스택이 비어있을 때 -1 반환
    else
        return data[top--]; // 스택에서 아이템을 제거하고 반환
}
element peek()
{
    if (is_empty())
        return -1; // 스택이 비어있을 때 -1 반환
    else
        return data[top]; // 스택의 가장 위 아이템을 반환
}

/****************

필요한 함수 추가 가능
** Fill the code  **

****************/

int eval(char exp[]) // 후위 표기 수식 계산 함수
{
    init_stack();
    int i, len, op1, op2; // op1, op2는 연산에 사용될 피연산자
    len = strlen(exp);
    int value=0;
    for (i = 0; i < len; i++)
    {
        if (isdigit(exp[i])) // 수식에 숫자가 있다면
        {
            value=exp[i++]-'0'; // 숫자를 정수로 변환, i는 다음 문자로 이동
            while(isdigit(exp[i])) // 숫자가 연속으로 나올 경우
            {
                value = value * 10 + (exp[i++] - '0'); // 숫자를 조합
            }
        }
        else if(exp[i]==' ')
        {
            continue; // 공백은 무시
        }
        else
        {
            switch (exp[i])
            {
            // 모든 연산자 계산은 구조적으로 당연히 같음.
            // 괄호는 배제
            case '+':
                op2 = pop(); // 스택에서 두 개의 피연산자를 꺼냄
                op1 = pop();
                push(op1 + op2); // 두 피연산자의 합을 스택에 푸시
                break;
            case '-':
                op2 = pop();
                op1 = pop();
                push(op1 - op2); // 두 피연산자의 차를 스택에 푸시
                break;
            case '*':
                op2 = pop();
                op1 = pop();
                push(op1 * op2); // 두 피연산자의 곱을 스택에 푸시 
                break;
            case '/':
                op2 = pop();
                op1 = pop();
                if (op2 == 0) { // 0으로 나누는 예외 처리는 항상 해줘야 함.
                    printf("Error: Division by zero\n");
                    return -1; 
                }
                break;

            }
        }
  
    }
    return pop(); // 스택에서 최종 결과를 꺼내 반환
}
int main() {
    int i = 0;
    char t = 0;
    char in[1000] = { 0 };
    char post[1000] = { 0 };

    //input string
    while ((t = getchar()) != EOF)
        in[i++] = t;
    in[i] = '\0';

    //output
    printf("%d\n", eval(in));

    return 0;
}
