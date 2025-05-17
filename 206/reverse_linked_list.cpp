#include <iostream>
#include "ListNode.h"

ListNode* reverseList(ListNode* head) {
    // 1->2->3->4->X

    // prev=X, curr=1, next=2
    // 1->X
    
    // prev=1, curr=2, next=3
    // 2->1->X

    // prev=2, curr=3, next=4
    // 3->2->1->X

    // prev=3, curr=4, next=X
    // 4->3->2->1->X

    // prev=4, curr=X, 
    // terminate

    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* next;

    while (curr) {
        // theres a good reason why next is calculated differently
        // 1. Get next
        // 2. Redirect pointers
        // 3. Get prev & curr
        next = curr->next;

        curr->next = prev;
        
        prev = curr;
        curr = next;
    }

    return prev;
}

int main() {

}
