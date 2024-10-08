#include <vector>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == nullptr) return head;
    else if (k == 1) return head;

    // Count number of nodes
    int count = 0;
    ListNode* curr = head;
    while (curr != nullptr) {
        ++count;
        curr = curr->next;
    }

    // Check if k is valid
    if (k > count) return head;

    // Reverse nodes
    ListNode* prev = nullptr;
    curr = head;
    ListNode* next = nullptr;
    count = 0;

    while (curr != nullptr and count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if (next != nullptr) {
        head->next = reverseKGroup(next, k);
    }

    return prev;
}

void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "NULL" << std::endl;
}

int main() {
    // List: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode* result = reverseKGroup(head, 3);
    printList(result);

    return 0;
}