#include <vector>
#include <iostream>
#include <queue>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {};                      // Default constructor
    ListNode(int x) : val(x), next(nullptr) {};                 // Constructor with value
    ListNode(int x, ListNode *next) : val(x), next(next) {};    // Constructor with value and next
};

// Attempt 1 (Merge everything together)
// auto mergeKLists(std::vector<ListNode*>& lists) -> ListNode* {
//     std::priority_queue<int, std::vector<int>, std::greater<int>> queue;

//     for (ListNode* node : lists) {
//         ListNode* curr = node;
//         while (node != nullptr) {
//             queue.push(node->val);
//             node = node->next;
//         }
//     }

//     ListNode* dummy = new ListNode();
//     ListNode* curr = dummy;

//     while (not queue.empty()) {
//         int value = queue.top();
//         queue.pop();

//         ListNode* new_node = new ListNode(value);
//         curr->next = new_node;
//         curr = new_node;
//     }

//     curr->next = nullptr;
//     return dummy->next;
// }

auto mergeKLists(std::vector<ListNode*>& lists) -> ListNode* {
    auto cmp = [](ListNode* node1, ListNode* node2) {
        return node1->val > node2->val;
    };

    // dammit what was decltype again?
    std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)> queue;

    for (ListNode* node : lists) {
        if (node != nullptr) queue.push(node);
    }

    ListNode* dummy = new ListNode();
    ListNode* curr = dummy;

    while (not queue.empty()) {
        auto node = queue.top();
        queue.pop();

        curr->next = node;
        curr = node;

        if (node->next != nullptr) {
            queue.push(node->next);
        }
    }

    return dummy->next;
}

int main() {
    
}