#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* head = new ListNode();
    ListNode* curr = head;

    while (list1 and list2) {
        if (list1->val < list2->val) {
            curr->next = list1;
            curr = curr->next;
            list1 = list1->next;
        } else {
            curr->next = list2;
            curr = curr->next;
            list2 = list2->next;
        }
    }

    if (list1) {
        curr->next = list1;
    } else {
        curr->next = list2;
    }

    return head->next;
}

auto main() -> int {
    ListNode* list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode* list2 = new ListNode(1, new ListNode(3, new ListNode(4)));

    ListNode* mergedList = mergeTwoLists(list1, list2);

    ListNode* current = mergedList;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;

    while (mergedList != nullptr) {
        ListNode* temp = mergedList;
        mergedList = mergedList->next;
        delete temp;
    }

    return 0;
}
