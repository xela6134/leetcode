// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.

// Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
// Output: [8,9,9,9,0,0,0,1]

// 2    4    3
// 5    6    4
// 7    0   7+1
// 
// 9    9    9    9    9    9    9
// 9    9    9    9
// 8    9    9    9    0    0    0    1

// 1. just add 2 numbers (straightforward)
// 2. add only remaining num

// add remainder in next iteration

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


auto addTwoNumbers(ListNode* l1, ListNode* l2) -> ListNode* {
    // Revision: head is only made to initialise, meaningful values are stored afterwards
    ListNode* head = new ListNode();
    ListNode* curr = head;

    int carry = 0;

    // Revision: (l1 || l2 || carry) syntax works in C++, no more C
    while (l1 || l2 || carry) {
        int sum = carry;

        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;
        sum = sum % 10;

        curr->next = new ListNode(sum);
        curr = curr->next;
    }

    return head->next;
}

void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

auto main() -> int {
    ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

    ListNode* list = addTwoNumbers(l1, l2);
    printList(list);
}
