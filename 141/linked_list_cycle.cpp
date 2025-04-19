#include <iostream>
#include <unordered_set>
#include "ListNode.h"

bool hasCycle(ListNode* head) {
    std::unordered_set<ListNode*> visited;

    while (head != nullptr) {
        if (visited.count(head)) {
            return true;
        }
        visited.insert(head);
        head = head->next;
    }

    return false;
}

int main() {

}
