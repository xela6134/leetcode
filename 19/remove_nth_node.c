#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* read = head;

    int size = 0;
    while (read != NULL) {
        read = read->next;
        ++size;
    }

    int target = size - n;

    if (target == 0) {
        struct ListNode* newHead = head->next;
        free(head);
        return newHead;
    }
    
    struct ListNode* prev;
    struct ListNode* curr = head;

    int curr_num = 0;
    while (curr_num < target) {
        prev = curr;
        curr = curr->next;
        ++curr_num;
    }

    prev->next = curr->next;
    free(curr);

    return head;
}

int main() {
    return 0;
}