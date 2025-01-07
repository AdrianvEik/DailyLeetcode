
#include <stdlib.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

typedef struct ListNode* ListNode;

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }
    
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* current = head;

    while (list1 != NULL && list2 != NULL) {
        if (list1->val < list2->val) {
            current->next = list1;
            list1 = list1->next;
        }
        else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    if (list1 != NULL) {
        current->next = list1;
    }

    if (list2 != NULL) {
        current->next = list2;
    }

    return head->next;
}

void main() {
    ListNode list1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    list1->val = 1;
    list1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    list1->next->val = 2;
    list1->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    list1->next->next->val = 4;
    list1->next->next->next = NULL;

    ListNode list2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    list2->val = 1;
    list2->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    list2->next->val = 3;
    list2->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    list2->next->next->val = 4;
    list2->next->next->next = NULL;

    ListNode res = mergeTwoLists(list1, list2);
    printf("Merged List: ");
    while (res != NULL) {
        printf("%d ", res->val);
        res = res->next;
    }
}