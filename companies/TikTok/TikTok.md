# Leetcode stuff (Actual Leetcode Qs)

### find the first non repeated character of a given string

```cpp
class Solution {
public:
    int firstUniqChar(string s) {
        std::unordered_map<char, int> counts;
        for (char c : s) {
            ++counts[c];
        }

        for (int i = 0; i < s.size(); ++i) {
            if (counts[s[i]] == 1) return i;
        }

        return -1;
    }
};
```

### find duplicate numbers in an array (if it contains multiple duplicates)

```cpp
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        std::vector<int> result;

        // 4 3 2 7 8 2 3 1
        // index=3, nums[index]=7
        // 4 3 2 -7 8 2 3 1
        // index=2, nums[index]=2
        // 4 3 -2 -7 8 2 3 1
        // index=1, nums[index]=3
        // 4 -3 -2 -7 8 2 3 1
        // index=6, nums[index]=3
        // 4 -3 -2 -7 8 2 -3 1
        // index=7, nums[index]=2
        // 4 -3 -2 -7 8 2 -3 -1
        // index=1, nums[index]=-3
        // 
        for (int num : nums) {
            int index = abs(num) - 1;
            if (nums[index] < 0) {
                result.push_back(abs(num));
            } else {
                nums[index] = -nums[index];
            }
        }
        
        return result;
    }
};
```

### remove duplicates from an array in place

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 1;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) {
                nums[index] = nums[i];
                ++index;
            }
        }

        return index;
    }
};
```

### find the middle element of a singly linked list

```cpp
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast and fast->next) {
            // std::cout << slow->val << ", " << fast->val << std::endl;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
};
```

### check if a given linked list contains a cycle

```cpp
class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) return true;
        }

        return false;
    }
};
```

### find the entry of the cycle

![](./cycle.PNG)

slow = `a + b`
fast = `a + b + c + b`

`2(a + b) = a + 2b + c`

therefore, distance-wise `a = c`

if we start all over again from head & curr slow, we can find the entry point of the cycle.

```cpp
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                slow = head;

                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }

                return slow;
            }
        }

        return nullptr;
    }
};
```

### reverse a singly linked list without recursion

```cpp

```

### traverse a given binary tree in preorder without recursion

```cpp

```

### traverse a given binary tree in inorder without recursion

```cpp

```

# Non-leetcode stuff

