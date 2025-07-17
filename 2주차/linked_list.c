////////////////////////////////////////////////////////////////////////////////
// 링크드 리스트 구현
////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

// 링크드 리스트 노드 구조체 정의
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// 링크드 리스트 구조체 정의 (헤드 포인터)
typedef struct {
    Node *head;
} LinkedList;

// --- 함수 프로토타입 ---

// 기본 기능
void initializeList(LinkedList *list);
void insert(LinkedList *list, int data); // 맨 앞에 삽입
void removeNode(LinkedList *list, int data); // 특정 값 삭제
Node* search(LinkedList *list, int data); // 값 검색
void printList(LinkedList *list);
void freeList(LinkedList *list);
int getCount(LinkedList *list); // 리스트 길이 반환
void reverse(LinkedList *list); // 리스트 뒤집기
void sort(LinkedList *list); // 리스트 정렬 (병합 정렬 기반)
void insert_sort(LinkedList *list, int data); // 정렬된 상태로 삽입

// 정렬을 위한 헬퍼(helper) 함수
void split(LinkedList *source, LinkedList *front, LinkedList *back); // 리스트 분할
void merge(LinkedList *result, LinkedList *front, LinkedList *back); // 두 리스트 병합


// --- 메인 함수: 메뉴 ---
int main() {
    LinkedList list;
    int choice, value, position;

    initializeList(&list);

    while (1) {
        printf("\n===== Linked List Professor Menu =====\n");
        printf("1. Insert (맨 앞에 삽입)\n");
        printf("2. Remove (값으로 삭제)\n");
        printf("3. Search (값 검색)\n");
        printf("4. Reverse (리스트 뒤집기)\n");
        printf("5. Sort (리스트 정렬)\n");
        printf("6. Print List (전체 출력)\n");
        printf("7. Get Count (길이 확인)\n");
        printf("0. Exit (종료)\n");
        printf("Select> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(&list, value);
                break;
            case 2:
                printf("Enter value to remove: ");
                scanf("%d", &value);
                removeNode(&list, value);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (search(&list, value) != NULL) {
                    printf("Value %d found in the list.\n", value);
                } else {
                    printf("Value %d not found.\n", value);
                }
                break;
            case 4:
                reverse(&list);
                printf("List reversed.\n");
                printList(&list);
                break;
            case 5:
                sort(&list);
                printf("List sorted.\n");
                printList(&list);
                break;
            case 6:
                printList(&list);
                break;
            case 7:
                printf("List count: %d\n", getCount(&list));
                break;
            case 0:
                printf("Bye, Professor!\n");
                freeList(&list);
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}

// --- 함수 구현 ---

////////////////////////////////////////////////////////////////////////////////
// 리스트 초기화
void initializeList(LinkedList *list) {
    list->head = NULL;
}

////////////////////////////////////////////////////////////////////////////////
// 노드 삽입 (가장 앞에 삽입)
void insert(LinkedList *list, int data) {
    // TODO: 새 노드를 동적으로 할당하고, 입력받은 데이터로 초기화합니다.
    //       그 다음, 새 노드가 리스트의 첫 번째 노드(head)를 가리키게 하고,
    //       리스트의 head를 새 노드로 변경합니다.
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
}

////////////////////////////////////////////////////////////////////////////////
// 특정 값을 가진 노드 삭제
void removeNode(LinkedList *list, int data) {
    // TODO: head부터 시작하여 삭제할 노드를 찾습니다.
    //       삭제할 노드가 head인 경우, head를 다음 노드로 변경합니다.
    //       그렇지 않은 경우, 이전 노드가 삭제할 노드의 다음 노드를 가리키게 합니다.
    //       마지막으로, 삭제된 노드의 메모리를 해제합니다.
    if (list->head == NULL) {
        printf("삭제할 노드가 없습니다");
        return;
    }
    Node *prev_node = NULL;
    Node *current_node = list->head;
    // 맨 처음 노드일 경우
    if (current_node->data == data) {
        if(current_node->next == NULL) {
            // 마지막 노드일 경우
            list->head = NULL;
        } else {
            list->head = current_node->next;
        }
        
        free(current_node);
        return;
    }
    while (current_node->next != NULL) {
        prev_node = current_node;
        current_node = current_node->next;
        

        if (current_node->data == data) {
            prev_node->next = current_node->next;
            free(current_node);
            return;
        }

    }
    // 맨 마지막 노드일 경우
    if (current_node->data == data) {
        prev_node->next = NULL;
        free(current_node);
        return;
    }

}

////////////////////////////////////////////////////////////////////////////////
// 특정 값을 가진 노드 검색
Node* search(LinkedList *list, int data) {
    // TODO: head부터 시작하여 리스트를 순회하며 data와 일치하는 노드를 찾습니다.
    //       찾으면 해당 노드의 포인터를 반환하고, 찾지 못하면 NULL을 반환합니다.
    Node *current_node = list->head;
    while (current_node != NULL) {
        if (current_node->data == data) {
            return current_node;
        }
        current_node = current_node->next;
    }
    
    return NULL;
}

////////////////////////////////////////////////////////////////////////////////
// 리스트의 노드 순서를 뒤집기
void reverse(LinkedList *list) {
    // TODO: 세 개의 포인터(previous, current, next)를 사용합니다.
    //       current 노드의 next가 previous를 가리키도록 변경하는 작업을
    //       리스트의 끝까지 반복합니다. 마지막에 head를 이전의 마지막 노드로 변경합니다.
}

////////////////////////////////////////////////////////////////////////////////
// 리스트 정렬 (병합 정렬 추천)
void sort(LinkedList *list) {
    // TODO: 재귀적인 접근 방식을 사용합니다.
    //       1. 리스트가 비어있거나 노드가 하나뿐이면 반환합니다.
    //       2. split() 함수를 사용해 리스트를 두 개의 하위 리스트로 분할합니다.
    //       3. 각 하위 리스트에 대해 재귀적으로 sort()를 호출합니다.
    //       4. merge() 함수를 사용해 정렬된 두 하위 리스트를 다시 하나로 병합합니다.
}

////////////////////////////////////////////////////////////////////////////////
// 정렬된 리스트에 노드 삽입
void insert_sort(LinkedList *list, int data) {
    // TODO: 새 노드를 생성합니다.
    //       리스트를 순회하며 새 노드가 들어갈 올바른 위치(정렬 순서에 맞는 위치)를 찾습니다.
    //       찾은 위치에 새 노드를 삽입합니다.
}

////////////////////////////////////////////////////////////////////////////////
// 리스트를 두 개의 하위 리스트로 분할 (병합 정렬용)
void split(LinkedList *source, LinkedList *front, LinkedList *back) {
    // TODO: "느린 포인터"와 "빠른 포인터" 기법을 사용합니다.
    //       빠른 포인터가 리스트의 끝에 도달할 때, 느린 포인터는 리스트의 중앙에 위치하게 됩니다.
    //       중앙을 기준으로 리스트를 두 부분으로 나눕니다.
}

////////////////////////////////////////////////////////////////////////////////
// 정렬된 두 리스트를 하나의 정렬된 리스트로 병합
void merge(LinkedList *result, LinkedList *front, LinkedList *back) {
    // TODO: front와 back 리스트의 노드를 하나씩 비교하면서
    //       더 작은 값을 가진 노드를 result 리스트에 추가하는 작업을 반복합니다.
    //       한쪽 리스트가 모두 소진되면, 남은 리스트의 노드들을 모두 result에 붙입니다.
}

////////////////////////////////////////////////////////////////////////////////
// 리스트의 모든 노드 데이터 출력
void printList(LinkedList *list) {
    // TODO: 임시 포인터를 head에서 시작하여 리스트의 끝(NULL)까지 이동시키면서
    //       각 노드의 데이터를 출력합니다. 리스트가 비어있다면 "List is empty."를 출력합니다.
    if (list->head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node *current_node = list->head;
    while (current_node != NULL) {
        printf("%d-", current_node->data);
        current_node = current_node->next;
    }
}

////////////////////////////////////////////////////////////////////////////////
// 리스트의 총 노드 개수 반환
int getCount(LinkedList *list) {
    // TODO: head부터 시작하여 리스트를 순회하며 노드의 개수를 셉니다.
    //       총 개수를 반환합니다.
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
// 리스트 전체 메모리 해제
void freeList(LinkedList *list) {
    // TODO: 임시 포인터를 사용하여 head부터 시작하여 각 노드를 순회하며
    //       동적으로 할당된 메모리를 순서대로 해제(free)합니다.
    //       모든 노드가 해제된 후, head를 NULL로 설정합니다.
}