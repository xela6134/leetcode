#include <iostream>
#include "ListNode.h"

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    if (headA == nullptr or headB == nullptr) return nullptr;

    // Will meet at intersection after lengthA + lengthB
    ListNode* pA = headA;
    ListNode* pB = headB;

    while (pA != pB) {
        if (pA == nullptr) {
            pA = headB;
        } else {
            pA = pA->next;
        }

        if (pB == nullptr) {
            pB = headA;
        } else {
            pB = pB->next;
        }
    }

    if (pA == pB) return pA;

    return nullptr;
}

int main() {

}
