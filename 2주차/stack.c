////////////////////////////////////////////////////////////////////////////////
// 배열 기반 스택 구현
////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int items[MAX];
    int top;
} Stack;

// 함수 프로토타입
void initializeStack(Stack *s);
int isEmpty(Stack *s);
int isFull(Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);
void printStack(Stack *s);

// 메인 함수: 메뉴
int main() {
    Stack s;
    int choice, value;

    initializeStack(&s);

    while (1) {
        printf("\n===== Stack Menu =====\n");
        printf("1. Push (삽입)\n");
        printf("2. Pop (삭제)\n");
        printf("3. Print Stack\n");
        printf("0. Exit\n");
        printf("Select> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&s, value);
                break;
            case 2:
                value = pop(&s);
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                printStack(&s);
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
// 스택 초기화
void initializeStack(Stack *s) {
    s->top = -1;
}

////////////////////////////////////////////////////////////////////////////////
// 스택이 비었는지 확인
int isEmpty(Stack *s) {
}

////////////////////////////////////////////////////////////////////////////////
// 스택이 꽉 찼는지 확인
int isFull(Stack *s) {
}

////////////////////////////////////////////////////////////////////////////////
// 삽입
void push(Stack *s, int value) {
}

////////////////////////////////////////////////////////////////////////////////
// 삭제
int pop(Stack *s) {
}

////////////////////////////////////////////////////////////////////////////////
// 스택 출력
void printStack(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack contents: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}
