#include <iostream>
#include "ListNode.h"

ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast and fast->next) {
        slow = slow->next;         // move by 1
        fast = fast->next->next;   // move by 2
    }

    // middle node
    return slow;
}

int main() {

}
