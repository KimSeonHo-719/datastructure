/*
4.

정수를 저장하는 원형큐을 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.
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

// 충분히 생각하고 시도 ㄱㄱ
// 기본 개념을 이해하고 구현하는 것이 중요
// 원형 큐 자체가 좀 헷갈릴 수 있는데 pdf 보면서 그림 그려보면서 시도하기
// 모듈 연산 항상 까먹지 말고 할 것.

#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	#define MAX_QUEUE_SIZE 100
	#define Element int

	Element data[MAX_QUEUE_SIZE];

	int front;
	int rear;

	void error(char* str)
	{
		fprintf(stderr, "%s\n", str);
		exit(1);
	};

	void init_queue()
	{
        front = 0;
        rear = 0;
	}
	int is_empty() 
	{
		return (front == rear);
	}
	int is_full() 
	{
		return((rear + 1) % MAX_QUEUE_SIZE == front);
	}
	int size() 
	{
		return rear - front + 1;
	}
	void enqueue(Element val) // 큐의 맨 뒤에 값을 추가하는 함수
	{
		if (is_full())
			error(" 큐 포화 에러");
		rear = (rear + 1) % MAX_QUEUE_SIZE; // 원형 큐이므로 rear를 증가시킬 때 모듈로 연산을 사용
		data[rear] = val; // rear 위치에 값을 저장
	}
	Element dequeue() // 큐의 맨 앞에 있는 값을 삭제하고 반환하는 함수
	{
		if (is_empty())
			error(" 큐 공백 에러");
		front = (front + 1) % MAX_QUEUE_SIZE; // 원형 큐이므로 front를 증가시킬 때 모듈로 연산을 사용
		return data[front]; // front 위치의 값을 반환
	}
	Element peek()
	{
		if (is_empty())
			error(" 큐 공백 에러");
		return data[(front + 1) % MAX_QUEUE_SIZE]; // front 다음 위치의 값을 반환 (삭제하지 않음)
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
			else if (strcmp(c, "size") == 0) printf("%d\n", size());
			else if (strcmp(c, "empty") == 0)printf("%d\n", is_empty());
			else if (strcmp(c, "full") == 0)printf("%d\n", is_full());
			else if (strcmp(c, "peek") == 0)printf("%d\n", peek());
			else printf("error\n");
		}
		return 0;
	}
