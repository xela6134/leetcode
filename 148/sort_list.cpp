#include <iostream>
#include <vector>
#include "ListNode.h"

ListNode* sortList(ListNode* head) {
    std::vector<int> numbers;
    ListNode* curr = head;

    while (curr != nullptr) {
        numbers.push_back(curr->val);
        curr = curr->next;
    }

    std::sort(numbers.begin(), numbers.end());

    curr = head;
    int i = 0;
    while (curr != nullptr) {
        curr->val = numbers[i++];
        curr = curr->next;
    }

    return head;
}

int main() {

}
