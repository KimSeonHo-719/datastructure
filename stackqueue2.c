/*
2.

문제 설명
강의 자료에 나와 있는 알고리즘을 참고하여 중위 표기 수식을 후위 표기 수식으로 변경하는 프로그램을 작성해보자.

첫 번째 줄에 중위 표기 방식으로 입력이 들어간다.
입력과 출력의 숫자들은 모두 정수로 나타내며 연산자는 ‘+’, ‘-’, ‘*’, ‘/’, ‘(’, ‘)’로 이루어져 있다.
각각의 문자들은 띄어쓰기로 구분한다. ( ex. 12∨-∨3∨(∨(∨4∨+∨3∨-∨2∨)∨*∨(∨2∨+∨5∨)∨) )

출력은 첫째 줄에 후위 표기 형태가 표시된다.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef int element;
element data[MAX_STACK_SIZE];
int top;

void init_stack()
{
    top = -1;
}
int is_empty()
{
    if (top == -1)
        return 1;
    else
        return 0;        
}
int is_full()
{
    if (top == MAX_STACK_SIZE - 1)
        return 1;
    else
        return 0;
}
int size() { return top + 1; }
void push(element item)
{
    if (is_full())
        return;
    else data[++top] = item;
        
}
element pop()
{
    if (is_empty())
        return -1; 
    else
        return data[top--];
}
element peek()
{
    if (is_empty())
        return -1; 
    else
        return data[top];
}

int prec(char op)
{
    switch (op)
    {
    case '(': case ')':
        return 0;
        break;
    case '+': case '-':
        return 1;
        break;
    case '*': case '/':
        return 2;
        break;
    }
    return -1;
}

void Infix_to_Postfix(char infix[], char post[])
{
    int len = strlen(infix);
    int i, j = 0;
    int tmp;
    int top_op;
    init_stack();
    for (i = 0; i < len; i++)
    {
        switch (infix[i])
        {
        case '+': case'*': case '-':case'/':
            while (!is_empty() && )
            {
                
            }
            
            break;
        case '(':
            
            break;
        case ')':
            
            while ()
            {
                
                
                
            }
            break;
            case ' ':
                break;
        default:
            if (isdigit(infix[i]))
            {
                while (isdigit(infix[i]))
                {
                    post[j++] = infix[i++];
                }
                post[j++] = ' ';
                break;
            }
        }
        
    }
    while (!is_empty())
    {
        post[j++] = pop();
        post[j++] = ' ';
    }
    

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

    //function call
    Infix_to_Postfix(in, post);

    //out string
    printf("%s\n", post);

    return 0;
}
