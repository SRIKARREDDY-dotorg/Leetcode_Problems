// https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/description/?envType=daily-question&envId=2024-10-22
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
class Solution {
public:
    // maxheap with level order traversal
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> queue;
        queue.push(root);
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        while(!queue.empty()) {
            int size = queue.size();
            long long levelSum = 0;
            while(size--) {
                TreeNode* root = queue.front();
                levelSum+=root->val;
                queue.pop();
                if(root->left) queue.push(root->left);
                if(root->right) queue.push(root->right);
            }
            pq.push(levelSum);
            if(pq.size()>k) pq.pop();
        }
        if(pq.size() < k) return -1;
        return pq.top();
    }
};
