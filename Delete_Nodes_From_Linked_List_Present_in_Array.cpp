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
