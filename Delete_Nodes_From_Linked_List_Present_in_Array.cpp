// https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/description/?envType=daily-question&envId=2024-09-06


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // ListNode* result = head;
        unordered_map<int, bool> numsPresense;
        for(int i = 0; i < nums.size(); i ++) {
            numsPresense[nums[i]] = 1;
        }

        ListNode* temp = head;
        ListNode* prevNode = NULL;
        while(temp) {
            if(numsPresense[temp->val]) {
                if(prevNode) {
                    ListNode* curr = temp->next;
                    prevNode->next = curr;
                    temp = temp->next;
                } else {
                    temp = temp->next;
                    head = temp;
                }
            } else {
                prevNode = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};

// Another way but same

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteNode(ListNode* node) {
        ListNode* nextNode = node->next;
        node->next = NULL;
        // cout<<node->val<<endl;
        return nextNode;
    }
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int, bool> numsMap;
        for(int& num: nums) {
            numsMap[num] = 1;
        }
        ListNode* currentNode = head;
        ListNode* prevNode = NULL;
        while(currentNode) {
            if(numsMap[currentNode->val]) {
                if(head->val == currentNode->val) {
                    head = currentNode->next;
                }
                ListNode* nextNode = deleteNode(currentNode);
                if(prevNode) prevNode->next = nextNode;
                currentNode = nextNode;
            } else {
                prevNode = currentNode;
                currentNode = currentNode->next;
            }
        }
        return head;
    }
};
