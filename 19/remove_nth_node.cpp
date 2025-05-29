#include <iostream>
#include "ListNode.h"

ListNode* removeNthFromEnd(ListNode* head, int n) {
    // Two traversals
    // 1 2 3 4
    // 2 3 4 5

    ListNode* track = head;
    ListNode* curr = head;
    ListNode* prev = nullptr;

    for (int i = 0; i < n; ++i) {
        track = track->next;
    }

    while (track != nullptr) {
        track = track->next;
        prev = curr;
        curr = curr->next;
    }

    // Now curr points to 4 (aka node to be deleted)
    if (not prev) return head->next;
    prev->next = curr->next;
    
    return head;
}

int main() {

}
