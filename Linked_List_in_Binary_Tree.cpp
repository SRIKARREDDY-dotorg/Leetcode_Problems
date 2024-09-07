// https://leetcode.com/problems/linked-list-in-binary-tree/description/?envType=daily-question&envId=2024-09-07

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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 // LinkedList in a binary tree.
class Solution {
public:
    bool traverse(ListNode* head, TreeNode* root) {
        if(!head) return true;
        if(!root) return false;
        bool leftTraversal = false;
        bool rightTraversal = false;
        if(head->val == root->val) {
            leftTraversal = traverse(head->next, root->left);
            rightTraversal = traverse(head->next, root->right);
        }
        if(leftTraversal || rightTraversal) return true;
        return false;
    }
    bool isSubPathHelper(ListNode* head, TreeNode* root) {
        if(!root) return false;

        if(root->val == head->val) {
            ListNode* temp = head;
            bool ans = traverse(temp, root);
            if(ans) return true;
        }
        bool leftValue = isSubPathHelper(head, root->left);
        bool rightValue = isSubPathHelper(head, root->right);
        return leftValue || rightValue;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        return isSubPathHelper(head, root);
    }
};
