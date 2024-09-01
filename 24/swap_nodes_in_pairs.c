#include <cstddef>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode* read = head;
    int size = 0;
    while (read != NULL) {
        read = read->next;
        size++;
    }

    if (size == 0 || size == 1) {
        return head;
    }

    struct ListNode* curr = head;
    struct ListNode* next;

    while (curr != NULL) {
        // odd number edge case
        if (curr->next == NULL) break;

        // swapping curr and next's vals
        next = curr->next;
        int temp = curr->val;
        curr->val = next->val;
        next->val = temp;

        // traverse 2
        curr = curr->next->next;
    }

    return head;
}