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

auto mergeKLists(std::vector<ListNode*>& lists) -> ListNode* {
    auto comp = [](ListNode* n1, ListNode* n2) {
        return n1->val > n2->val;
    };

    // Nothing too complicated, 
    // Declaring a priority queue for ListNode,
    // with container type of std::vector<ListNode>,
    // with lambda function comp() as its custom comparator.
    std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(comp)> min_queue(comp);

    for (ListNode* node : lists) {
        if (node != nullptr) {
            min_queue.push(node);
        }
    }

    ListNode* dummy = new ListNode();
    ListNode* current = dummy;

    while (not min_queue.empty()) {
        ListNode* smallest = min_queue.top();
        min_queue.pop();

        current->next = smallest;
        current = current->next;

        if (smallest->next != nullptr) {
            min_queue.push(smallest->next);
        }
    }

    return dummy->next;
}

auto main() -> int {
    
}