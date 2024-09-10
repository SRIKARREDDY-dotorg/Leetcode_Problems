// https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/?envType=daily-question&envId=2024-09-10
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
    int gcd(int a, int b) {
        if(a%b == 0) return b;
        int rem = a%b;
        a = b;
        b = rem;
        return gcd(a,b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* result = head;
        while(head->next) {
            int node1 = head->val;
            int node2 = head->next->val;
            ListNode* newNode = new ListNode(gcd(max(node1, node2), min(node1, node2)));
            ListNode* temp = head->next;
            head->next = newNode;
            newNode->next = temp;
            head = temp;
        }
        return result;
    }
};
