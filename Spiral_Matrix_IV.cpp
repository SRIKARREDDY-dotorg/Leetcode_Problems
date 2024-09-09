// https://leetcode.com/problems/spiral-matrix-iv/solutions/5758490/self-solved-this-solution-just-traverse-the-array/

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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        // first figure out how to traverse
        vector<vector<int>> result(m, vector<int>(n, -1));
        // fill the cells with head value, and go next
        // if head null, end loop.
        int totalNumbers = m*n;
        int k = 0;
        int rowSteps = n;
        int colSteps = m;
        int x = 0, y = 0;
        while(k < totalNumbers && head) {
            for(int i = 0; i < rowSteps && head; i ++) {
                // cout<<x<<" "<<y<<endl;
                result[x][y++] = head->val;
                head = head->next;
                k++;
            }
            x++;
            y--;
            // cout<<"--------------\n";
            for(int j = 0; j < colSteps-1 && head; j ++) {
                // cout<<x<<" "<<y<<endl;
                result[x++][y] = head->val;
                head = head->next;
                k++;
            }
            x--;
            y--;
            // cout<<"--------------\n";
            for(int i = 0; i < rowSteps-1 && head; i ++) {
                // cout<<x<<" "<<y<<endl;
                result[x][y--] = head->val;
                head = head->next;
                k++;
            }
            y++;
            x--;
            // cout<<"--------------\n";
            // cout<<colSteps<<" "<<k<<endl;
            for(int j = 0; j < (colSteps-2) && head; j ++) {
                // cout<<x<<" "<<y<<endl;
                result[x--][y] = head->val;
                head = head->next;
                k++;
            }
            x++;
            y++;
            // cout<<"--------------\n";
            rowSteps-=2;
            colSteps-=2;
        }
        return result;
    }
};
