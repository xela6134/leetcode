#include <iostream>
#include "ListNode.h"

bool hasCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr) {
        fast = fast->next;
        
        if (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;

            if (fast == slow) {
                return true;
            }
        }
    }

    return false;
}

int main() {

}
