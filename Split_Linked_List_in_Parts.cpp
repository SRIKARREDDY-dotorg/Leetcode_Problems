// https://leetcode.com/problems/split-linked-list-in-parts/description/?envType=daily-question&envId=2024-09-08
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // find the length
        ListNode* temp = head;
        vector<ListNode*> result;
        int length = 0;
        while(temp) {
            length++;
            temp = temp->next;
        }

        if(length%k) {
            int remainder = length%k;
            int splitLength = length/k;
            int initialSplitLength = splitLength+1;
            int initialCount = 1;
            result.push_back(head);

            while(head && remainder) {
                if(initialCount == initialSplitLength) {
                    initialCount = 1;
                    ListNode* temp = head;
                    head = head->next;
                    if(head) result.push_back(head);
                    temp->next = NULL;
                    remainder--;
                } else {
                    initialCount++;
                    head = head->next;
                }
            }

            int count = 1;
            while(head) {
                if(count == splitLength) {
                    count = 1;
                    ListNode* temp = head;
                    head = head->next;
                    if(head) result.push_back(head);
                    temp->next = NULL;
                } else {
                    count++;
                    head = head->next;
                }
            }
        } else {
            int splitLength = length/k;
            int count = 1;
            result.push_back(head);
            while(head) {
                if(count == splitLength) {
                    count = 1;
                    ListNode* temp = head;
                    head = head->next;
                    if(head) result.push_back(head);
                    temp->next = NULL;
                } else {
                    count++;
                    head = head->next;
                }
            }
        }
        if(result.size() < k) {
            int remain = k - result.size();
            while(remain--) result.push_back(NULL);
        }
        return result;
    }
};
