////////////////////////////////////////////////////////////////////////////////
// 배열 기반 큐 구현
////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

// 함수 프로토타입
void initializeQueue(Queue *q);
int isEmpty(Queue *q);
int isFull(Queue *q);
void enqueue(Queue *q, int value);
int dequeue(Queue *q);
void printQueue(Queue *q);

// 메인 함수: 메뉴
int main() {
    Queue q;
    int choice, value;

    initializeQueue(&q);

    while (1) {
        printf("\n===== Queue Menu =====\n");
        printf("1. Enqueue (삽입)\n");
        printf("2. Dequeue (삭제)\n");
        printf("3. Print Queue\n");
        printf("0. Exit\n");
        printf("Select> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                value = dequeue(&q);
                if (value != -1) {
                    printf("Dequeued value: %d\n", value);
                }
                break;
            case 3:
                printQueue(&q);
                break;
            case 0:
                printf("Bye!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}

////////////////////////////////////////////////////////////////////////////////
// 큐 초기화
void initializeQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

////////////////////////////////////////////////////////////////////////////////
// 큐가 비었는지 확인
int isEmpty(Queue *q) {
    /* 구현하세요 */
    return 0; // 임시 리턴
}

////////////////////////////////////////////////////////////////////////////////
// 큐가 꽉 찼는지 확인
int isFull(Queue *q) {
    /* 구현하세요 */
    return 0; // 임시 리턴
}

////////////////////////////////////////////////////////////////////////////////
// 삽입
void enqueue(Queue *q, int value) {
    /* 구현하세요 */
}

////////////////////////////////////////////////////////////////////////////////
// 삭제
int dequeue(Queue *q) {
    /* 구현하세요 */
    return -1; // 임시 리턴
}

////////////////////////////////////////////////////////////////////////////////
// 큐 출력
void printQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue contents: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}
